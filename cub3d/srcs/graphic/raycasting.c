/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:32:52 by eonoh             #+#    #+#             */
/*   Updated: 2025/03/25 21:32:54 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

double	get_dist_with_dda(t_config *config, t_dir ray, t_dda *dda)
{
	init_dda_setting1(config, ray, dda);
	while (dda->hit != 1)
	{
		if (dda->side_x < dda->side_y)
		{
			dda->map_x += dda->step_x;
			dda->side_x += dda->delta_x;
			dda->side = 0;
		}
		else
		{
			dda->map_y += dda->step_y;
			dda->side_y += dda->delta_y;
			dda->side = 1;
		}
		if (dda->map_y < 0 || dda->map_x < 0 || \
			dda->map_y >= config->params->map_h || \
			dda->map_x >= config->params->map_w || \
			config->params->map_raw[dda->map_y][dda->map_x].val == '1')
			dda->hit = 1;
	}
	if (dda->side == 0)
		return (dda->side_x - dda->delta_x);
	else
		return (dda->side_y - dda->delta_y);
}

void	draw_ceiling_and_floor(t_config *config, t_dot tmp)
{
	int	idx;
	int	color;

	idx = 0;
	color = config->params->ceiling;
	while (idx < tmp.y)
	{
		put_pixel_in_image(config->img_data, tmp.x, idx, color);
		idx++;
	}
	idx = 0;
	color = config->params->floor;
	while (tmp.y + idx < WINDOW_HEIGHT)
	{
		put_pixel_in_image(config->img_data, tmp.x, tmp.y + idx, color);
		idx++;
	}
}

void	draw_vertical_line_with_dist(t_config *config, t_dir ray, int win_idx)
{
	int		vertical_line;
	t_dda	dda;

	dda.distance = get_dist_with_dda(config, ray, &dda);
	if (dda.distance != 0)
		vertical_line = WINDOW_HEIGHT / dda.distance;
	else
		vertical_line = WINDOW_HEIGHT;
	dda.tmp.x = win_idx;
	dda.tmp.y = (WINDOW_HEIGHT / 2) - (vertical_line / 2);
	dda.vertical_line = vertical_line;
	draw_ceiling_and_floor(config, dda.tmp);
	if (vertical_line > 0)
		draw_texture(config, &dda, &ray);
}

void	raycasting(t_config *config)
{
	t_dir	ray;
	double	cam_idx;
	int		win_idx;

	win_idx = 0;
	while (win_idx <= (WINDOW_WIDTH))
	{
		cam_idx = (2 * win_idx / (double)(WINDOW_WIDTH)) - 1;
		ray.dx = config->pov.dirx + config->pov.camx * cam_idx;
		ray.dy = config->pov.diry + config->pov.camy * cam_idx;
		draw_vertical_line_with_dist(config, ray, win_idx);
		win_idx++;
	}
}

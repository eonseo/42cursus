/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:16:45 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/24 15:19:12 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_bonus.h"

void	draw_full_cell(int row, int col, t_config *config)
{
	t_dot	start;
	int		i;
	int		j;

	start = config->params->map_raw[row][col].pos;
	start.x *= config->cell_size;
	start.y *= config->cell_size;
	i = 0;
	while (i < config->cell_size)
	{
		j = 0;
		while (j < config->cell_size)
		{
			put_pixel_in_image(config->img_data, \
					start.x + j, start.y + i, C_WHITE);
			j++;
		}
		i++;
	}
}

void	draw_empty_cell(int row, int col, t_config *config)
{
	t_dot	dot1;
	t_dot	dot2;
	t_dot	dot3;
	t_dot	dot4;

	dot1.x = config->cell_size * col;
	dot1.y = config->cell_size * row;
	dot2.x = dot1.x + config->cell_size - 1;
	dot2.y = dot1.y;
	dot3.x = dot1.x;
	dot3.y = dot1.y + config->cell_size - 1;
	dot4.x = dot2.x;
	dot4.y = dot3.y;
	dda_line(dot1, dot2, config);
	dda_line(dot2, dot4, config);
	dda_line(dot1, dot3, config);
	dda_line(dot3, dot4, config);
}

void	draw_map_grid(t_config *config)
{
	int	row;
	int	col;

	row = 0;
	while (row < config->params->map_h)
	{
		col = 0;
		while (col < config->params->map_w)
		{
			if (config->params->map_raw[row][col].val == '1')
				draw_full_cell(row, col, config);
			else if (config->params->map_raw[row][col].val == '0')
				draw_empty_cell(row, col, config);
			col++;
		}
		row++;
	}
}

void	draw_minimap_ray(t_config *config, t_dir ray)
{
	t_dot	dot;

	dot = config->pov.location;
	dot.x *= config->cell_size;
	dot.y *= config->cell_size;
	while (is_thisdot_in_scaled_wallarea(dot, config) == NO)
	{
		put_pixel_in_image(config->img_data, dot.x, dot.y, C_GREEN);
		dot.x += ray.dx;
		dot.y += ray.dy;
	}
}

void	mini_map(t_config *config)
{
	t_dir	ray;
	double	cam_idx;
	int		int_idx;

	draw_map_grid(config);
	int_idx = 0;
	while (int_idx < (WINDOW_WIDTH))
	{
		cam_idx = (2 * int_idx / (double)(WINDOW_WIDTH)) - 1;
		ray.dx = config->pov.dirx + config->pov.camx * cam_idx;
		ray.dy = config->pov.diry + config->pov.camy * cam_idx;
		draw_minimap_ray(config, ray);
		int_idx++;
	}
}

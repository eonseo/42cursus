/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_rendering_info.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:18:22 by eonoh             #+#    #+#             */
/*   Updated: 2025/03/25 21:30:17 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

double	get_wall_hit_ratio(t_config *config, t_dda *dda, t_dir *ray)
{
	double	wall_x;

	if (dda->side == 0)
		wall_x = config->pov.location.y + dda->distance * ray->dy;
	else
		wall_x = config->pov.location.x + dda->distance * ray->dx;
	dda->wall_x = wall_x;
	dda->hit_ratio = wall_x - floor(wall_x);
	return (dda->hit_ratio);
}

int	set_wall_direction(t_dda *dda, t_dir *ray)
{
	int	direction;

	if (dda->side == 0)
	{
		if (ray->dx > 0)
			direction = WEST;
		else
			direction = EAST;
	}
	else
	{
		if (ray->dy > 0)
			direction = NORTH;
		else
			direction = SOUTH;
	}
	dda->wall_direction = direction;
	return (direction);
}

int	find_x_pos_on_tex(t_config *config, t_dda *dda, t_dir *ray)
{
	int		texture_width;

	texture_width = config->texture[dda->wall_direction].width;
	dda->tex_x = (int)(dda->hit_ratio * (double)texture_width);
	if (dda->side == 1 && ray->dy > 0)
		dda->tex_x = texture_width - dda->tex_x -1;
	else if (dda->side == 0 && ray->dx < 0)
		dda->tex_x = texture_width - dda->tex_x -1;
	return (ray->dx);
}

int	get_draw_start(t_dda *dda)
{
	int	draw_start;

	draw_start = WINDOW_HEIGHT / 2 - (dda->vertical_line / 2);
	if (draw_start < 0)
		draw_start = 0;
	dda->draw_start = draw_start;
	return (draw_start);
}

int	get_draw_end(t_dda *dda)
{
	int	draw_end;

	draw_end = WINDOW_HEIGHT / 2 + (dda->vertical_line / 2);
	if (draw_end > WINDOW_HEIGHT)
		draw_end = WINDOW_HEIGHT - 1;
	dda->draw_end = draw_end;
	return (draw_end);
}

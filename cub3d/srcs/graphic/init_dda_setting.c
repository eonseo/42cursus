/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dda_setting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:53:27 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/24 15:15:07 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	init_dda_setting1(t_config *config, t_dir ray, t_dda *dda)
{
	dda->pos_x = config->pov.location.x;
	dda->pos_y = config->pov.location.y;
	dda->map_x = (int)(dda->pos_x);
	dda->map_y = (int)(dda->pos_y);
	dda->hit = 0;
	dda->side = 0;
	if (ray.dx != 0)
		dda->delta_x = fabs(1 / ray.dx);
	else
		dda->delta_x = INFINITY;
	if (ray.dy != 0)
		dda->delta_y = fabs(1 / ray.dy);
	else
		dda->delta_y = INFINITY;
	init_dda_setting2(ray, dda);
}

void	init_dda_setting2(t_dir ray, t_dda *dda)
{
	if (ray.dx < 0)
	{
		dda->step_x = -1;
		dda->side_x = (dda->delta_x) * (dda->pos_x - dda->map_x);
	}
	else
	{
		dda->step_x = 1;
		dda->side_x = (dda->delta_x) * ((1 + dda->map_x) - dda->pos_x);
	}
	if (ray.dy < 0)
	{
		dda->step_y = -1;
		dda->side_y = (dda->delta_y) * (dda->pos_y - dda->map_y);
	}
	else
	{
		dda->step_y = 1;
		dda->side_y = (dda->delta_y) * ((1 + dda->map_y) - dda->pos_y);
	}
}

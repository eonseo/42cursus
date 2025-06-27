/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:29:05 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/24 15:29:46 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	is_thisdot_in_scaled_wallarea(t_dot dot, t_config *config)
{
	int	row;
	int	col;

	if (dot.x < 0 || dot.y < 0)
		return (YES);
	row = dot.y / config->cell_size;
	col = dot.x / config->cell_size;
	if (row >= config->params->map_h || col >= config->params->map_w)
		return (YES);
	if (config->params->map_raw[row][col].val == '1')
		return (YES);
	else
		return (NO);
}

int	is_thisdot_in_wallarea(t_dot dot, t_config *config)
{
	int	row;
	int	col;

	if (dot.x < 0 || dot.y < 0)
		return (YES);
	row = (int)dot.y;
	col = (int)dot.x;
	if (row >= config->params->map_h || col >= config->params->map_w)
		return (YES);
	if (config->params->map_raw[row][col].val == '1')
		return (YES);
	return (NO);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mapinfo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:27:19 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/24 15:28:03 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	setup_mapinfo(t_config *config)
{
	int		row;
	int		col;
	t_coord	**map;

	map = config->params->map_raw;
	row = 0;
	while (row < config->params->map_h)
	{
		col = 0;
		while (col < config->params->map_w)
		{
			if (map[row][col].amihere == 1)
			{
				config->pov.location.x = col + 0.5;
				config->pov.location.y = row + 0.5;
				config->pov.angle = check_angle(map[row][col].val);
				make_player_vector(config);
			}
			col++;
		}
		row++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:54:53 by eonoh             #+#    #+#             */
/*   Updated: 2025/03/24 15:20:28 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	check_angle(char val)
{
	if (val == 'E')
		return (0);
	else if (val == 'N')
		return (270);
	else if (val == 'W')
		return (180);
	else
		return (90);
}

void	make_player_vector(t_config *config)
{
	double	radian;

	radian = angle_to_radian(config->pov.angle);
	config->pov.dirx = cos(radian);
	config->pov.diry = sin(radian);
	config->pov.camy = (config->pov.dirx) * (0.6);
	config->pov.camx = (config->pov.diry) * (-1) * (0.6);
}

void	init_player_pov(t_config *config)
{
	int		i;
	int		j;
	int		cell_size;
	t_coord	**map_raw;

	cell_size = config->cell_size;
	map_raw = config->params->map_raw;
	i = 0;
	while (i < config->params->map_h)
	{
		j = 0;
		while (j < config->params->map_w)
		{
			if (map_raw[i][j].amihere == 1)
			{
				config->pov.location.x = (cell_size * j) + (cell_size / 2);
				config->pov.location.y = (cell_size * i) + (cell_size / 2);
				config->pov.angle = check_angle(map_raw[i][j].val);
				make_player_vector(config);
			}
			j++;
		}
		i++;
	}
}

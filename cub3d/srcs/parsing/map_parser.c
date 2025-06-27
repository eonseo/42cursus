/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:38:26 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/24 14:08:00 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	check_neighbor(t_coord **map, int x, int y)
{
	if (map[y - 1][x - 1].val == ' ')
		return (STOP);
	if (map[y][x - 1].val == ' ')
		return (STOP);
	if (map[y + 1][x - 1].val == ' ')
		return (STOP);
	if (map[y - 1][x].val == ' ')
		return (STOP);
	if (map[y + 1][x].val == ' ')
		return (STOP);
	if (map[y - 1][x + 1].val == ' ')
		return (STOP);
	if (map[y][x + 1].val == ' ')
		return (STOP);
	if (map[y + 1][x + 1].val == ' ')
		return (STOP);
	return (CONTINUE);
}

int	map_border_check(t_params *params)
{
	int	y;
	int	x;

	y = 0;
	while (y < params->map_h)
	{
		x = 0;
		while (x < params->map_w)
		{
			if (params->map_raw[y][x].val == '0')
			{
				if (x == 0 || y == 0 || \
						x == params->map_w - 1 || y == params->map_h - 1)
					return (STOP);
				else if (check_neighbor(params->map_raw, x, y) == STOP)
					return (STOP);
			}
			x++;
		}
		y++;
	}
	return (CONTINUE);
}

int	map_parser(t_params *params, int fd)
{
	t_mapstr	*mapstr;

	mapstr = NULL;
	if (check_map_and_backup(params, fd, &mapstr) == STOP)
		return (free_mapstr(mapstr));
	if (make_map_into_arr(params, mapstr) == STOP)
		return (free_mapstr(mapstr));
	free_mapstr(mapstr);
	if (map_border_check(params) == STOP)
		return (STOP);
	return (CONTINUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:38:23 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/24 14:01:04 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	free_split(char ***split, int idx)
{
	int	i;

	if (!split || !(*split))
		return (STOP);
	i = 0;
	while (i <= idx)
	{
		if ((*split)[i] != NULL)
			free ((*split)[i]);
		i++;
	}
	free (*split);
	*split = NULL;
	return (STOP);
}

int	free_mapstr(t_mapstr *mapstr)
{
	t_mapstr	*curr;
	t_mapstr	*next;

	if (!mapstr)
		return (STOP);
	if (mapstr->prev)
		mapstr->prev->next = NULL;
	curr = mapstr;
	while (curr)
	{
		next = curr->next;
		free (curr->line);
		free (curr);
		curr = next;
	}
	return (STOP);
}

int	free_mapraw(t_coord **map, int map_h)
{
	int	idx;

	if (!map)
		return (STOP);
	idx = 0;
	while (idx < map_h)
	{
		if (map[idx])
			free (map[idx]);
		idx++;
	}
	free (map);
	return (STOP);
}

int	free_params(t_params *params)
{
	free_mapraw(params->map_raw, params->map_h);
	if (params->north_path)
		free (params->north_path);
	if (params->south_path)
		free (params->south_path);
	if (params->west_path)
		free (params->west_path);
	if (params->east_path)
		free (params->east_path);
	free(params);
	return (STOP);
}

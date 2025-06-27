/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_into_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:38:24 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/24 14:05:19 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	fill_out_one_dot(t_coord *row, int row_idx, int col_idx)
{
	row[col_idx].pos.y = row_idx;
	row[col_idx].pos.x = col_idx;
	row[col_idx].pos.color = 0;
}

static void	fill_out_one_row(t_coord *row, t_mapstr *tmp,
		int width, int row_idx)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (tmp->line[i] == '\0')
			break ;
		row[i].val = tmp->line[i];
		if (tmp->line[i] == 'S' || tmp->line[i] == 'N'\
		|| tmp->line[i] == 'W' || tmp->line[i] == 'E')
			row[i].amihere = 1;
		else
			row[i].amihere = 0;
		fill_out_one_dot(row, row_idx, i);
		i++;
	}
	while (i < width)
	{
		row[i].val = ' ';
		row[i].amihere = 0;
		fill_out_one_dot(row, row_idx, i);
		i++;
	}
}

int	make_map_into_arr(t_params *params, t_mapstr *mapstr)
{
	int			idx;
	t_mapstr	*curr;

	if (!params || !(mapstr))
		return (STOP);
	params->map_raw = (t_coord **)malloc(sizeof(t_coord *) * params->map_h);
	if (!(params->map_raw))
		return (STOP);
	curr = mapstr;
	idx = 0;
	while (idx < (params->map_h))
	{
		params->map_raw[idx] = (t_coord *)malloc(\
				sizeof(t_coord) * params->map_w);
		if (!(params->map_raw[idx]))
		{
			free_mapraw(params->map_raw, params->map_h);
			params->map_raw = NULL;
		}
		fill_out_one_row(params->map_raw[idx], curr, params->map_w, idx);
		idx++;
		curr = curr->next;
	}
	return (CONTINUE);
}

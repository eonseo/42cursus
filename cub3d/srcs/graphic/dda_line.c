/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:15:22 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/24 14:16:28 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

t_line	*init_line(t_dot start, t_dot end)
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->start = start;
	line->end = end;
	line->dx = end.x - start.x;
	line->dy = end.y - start.y;
	if (return_abs(line->dx) > return_abs(line->dy))
		line->step = (int)return_abs(line->dx);
	else
		line->step = (int)return_abs(line->dy);
	line->inc_x = line->dx / (double) line->step;
	line->inc_y = line->dy / (double) line->step;
	return (line);
}

void	dda_line(t_dot start, t_dot end, t_config *config)
{
	t_line	*line;
	double	pc_x;
	double	pc_y;
	int		idx;

	line = init_line(start, end);
	if (!line)
		return ;
	idx = 0;
	pc_x = (double)start.x;
	pc_y = (double)start.y;
	while (idx < line->step)
	{
		put_pixel_in_image(config->img_data, (int)pc_x, (int)pc_y, C_WHITE);
		pc_x += line->inc_x;
		pc_y += line->inc_y;
		idx++;
	}
	free (line);
}

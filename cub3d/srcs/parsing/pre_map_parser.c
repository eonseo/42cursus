/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_map_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:38:30 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/24 14:11:20 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	process_by_type(t_params *params, char **split)
{
	if (ft_strncmp(split[0], "NO", 3) == 0)
		return (north_parser(params, split));
	else if (ft_strncmp(split[0], "SO", 3) == 0)
		return (south_parser(params, split));
	else if (ft_strncmp(split[0], "WE", 3) == 0)
		return (west_parser(params, split));
	else if (ft_strncmp(split[0], "EA", 3) == 0)
		return (east_parser(params, split));
	else if (ft_strncmp(split[0], "F", 2) == 0)
		return (floor_parser(params, split));
	else if (ft_strncmp(split[0], "C", 2) == 0)
		return (ceiling_parser(params, split));
	else
		return (STOP);
}

int	pre_map_parser(t_params *params, char *line)
{
	char	**split;
	int		i;
	int		res;

	if (ft_strncmp(line, "\n", 2) == 0)
		return (CONTINUE);
	split = ft_split(line, ' ');
	if (!split)
		return (STOP);
	i = 0;
	while (split[i] != NULL)
		i++;
	res = STOP;
	if (i == 2)
		res = process_by_type(params, split);
	free_split(&split, i);
	if (i != 2 || res == STOP)
		return (STOP);
	return (res);
}

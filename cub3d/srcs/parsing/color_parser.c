/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:38:17 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/24 13:55:12 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static int	check_num_range(char *str)
{
	int	i;

	if (!str)
		return (STOP);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (STOP);
		i++;
	}
	if (i > 10)
		return (STOP);
	if (0 <= ft_atoi(str) && ft_atoi(str) <= 255)
		return (CONTINUE);
	else
		return (STOP);
}

int	floor_parser(t_params *params, char **split)
{
	char	**color;
	int		idx;

	if (get_wrdcnt(split[1], ',') - 1 != 2)
		return (STOP);
	color = ft_split(split[1], ',');
	if (!color)
		return (STOP);
	remove_newline_from_str(&(color[2]));
	idx = 0;
	while (color[idx])
	{
		if (check_num_range(color[idx]) == STOP)
			return (free_split(&color, 2));
		idx++;
	}
	params->floor = ft_atoi(color[0]) << 16;
	params->floor += ft_atoi(color[1]) << 8;
	params->floor += ft_atoi(color[2]);
	free_split(&color, 2);
	return (CONTINUE);
}

int	ceiling_parser(t_params *params, char **split)
{
	char	**color;
	int		idx;

	if (get_wrdcnt(split[1], ',') - 1 != 2)
		return (STOP);
	color = ft_split(split[1], ',');
	if (!color)
		return (STOP);
	remove_newline_from_str(&(color[2]));
	idx = 0;
	while (color[idx])
	{
		if (check_num_range(color[idx]) == STOP)
			return (free_split(&color, 2));
		idx++;
	}
	params->ceiling = (ft_atoi(color[0]) << 16);
	params->ceiling += (ft_atoi(color[1]) << 8);
	params->ceiling += (ft_atoi(color[2]));
	free_split(&color, 2);
	return (CONTINUE);
}

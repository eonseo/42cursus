/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:38:19 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/24 13:56:39 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	north_parser(t_params *params, char **split)
{
	if (params->north_path)
		return (STOP);
	if (split[1])
		params->north_path = ft_strdup(split[1]);
	else
		return (STOP);
	remove_newline_from_str(&(params->north_path));
	return (CONTINUE);
}

int	south_parser(t_params *params, char **split)
{
	if (params->south_path)
		return (STOP);
	if (split[1])
		params->south_path = ft_strdup(split[1]);
	else
		return (STOP);
	remove_newline_from_str(&(params->south_path));
	return (CONTINUE);
}

int	west_parser(t_params *params, char **split)
{
	if (params->west_path)
		return (STOP);
	if (split[1])
		params->west_path = ft_strdup(split[1]);
	else
		return (STOP);
	remove_newline_from_str(&(params->west_path));
	return (CONTINUE);
}

int	east_parser(t_params *params, char **split)
{
	if (params->east_path)
		return (STOP);
	if (split[1])
		params->east_path = ft_strdup(split[1]);
	else
		return (STOP);
	remove_newline_from_str(&(params->east_path));
	return (CONTINUE);
}

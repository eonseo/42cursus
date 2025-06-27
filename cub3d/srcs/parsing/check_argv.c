/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:38:06 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/24 13:40:14 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	check_extension(char *filename)
{
	char	*lastdot;

	lastdot = ft_strrchr(filename, '.');
	if (lastdot == NULL)
		return (STOP);
	if (ft_strncmp(lastdot, ".cub", 5) != 0)
		return (STOP);
	else
		return (CONTINUE);
}

int	check_argv(int ac, char **av)
{
	if (ac != 2)
		return (STOP);
	if (check_extension(av[1]) == STOP)
		return (STOP);
	return (CONTINUE);
}

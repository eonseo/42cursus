/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:30:48 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/24 15:30:49 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(int ac, char **av)
{
	t_params	*params;
	t_config	*config;

	if (check_argv(ac, av) == STOP)
		return (printf("Error\n"));
	params = file_parsing(av[1]);
	if (!params)
		return (0);
	config = init_config(params);
	if (!config)
		return (free_params(params));
	setup_mapinfo(config);
	cub3d(config);
	mlx_hook(config->win_ptr, KEY_PRESS, 1L << 0, handle_key, config);
	mlx_hook(config->win_ptr, DESTROY_NOTIFY, 0, close_all, config);
	mlx_loop(config->mlx_ptr);
}

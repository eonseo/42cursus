/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:31:46 by eonoh             #+#    #+#             */
/*   Updated: 2025/03/25 21:32:09 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_bonus.h"

int	main(int ac, char **av)
{
	t_params	*params;
	t_config	*config;
	t_bonus		bonus;

	if (check_argv(ac, av) == STOP)
		return (1);
	params = file_parsing(av[1]);
	if (!params)
		return (1);
	config = init_config(params);
	if (!config)
		return (free_params(params));
	setup_mapinfo(config);
	cub3d(config);
	bonus.mini_map_flag = 0;
	bonus.config = config;
	bonus.mouse_x = 0;
	config->cell_size = (WINDOW_WIDTH / 2) / config->params->map_w;
	mlx_hook(config->win_ptr, MOTION_NOTIFY, \
		1L << 6, handle_mouse, &bonus);
	mlx_hook(config->win_ptr, KEY_PRESS, \
		1L << 0, handle_key_bonus, &bonus);
	mlx_hook(config->win_ptr, DESTROY_NOTIFY, 0, close_all, config);
	mlx_loop(config->mlx_ptr);
}

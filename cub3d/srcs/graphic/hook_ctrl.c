/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:32:29 by eonoh             #+#    #+#             */
/*   Updated: 2025/03/25 21:32:36 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	set_delta(t_dir *delta, int keycode, t_config *config)
{
	t_dir	player;

	player.dx = config->pov.dirx;
	player.dy = config->pov.diry;
	if (keycode == XK_W)
	{
		delta->dx = player.dx;
		delta->dy = player.dy;
	}
	else if (keycode == XK_S)
	{
		delta->dx = player.dx * (-1);
		delta->dy = player.dy * (-1);
	}
	else if (keycode == XK_A)
	{
		delta->dx = (-1) * (config->pov.camx);
		delta->dy = (-1) * (config->pov.camy);
	}
	else if (keycode == XK_D)
	{
		delta->dx = (config->pov.camx);
		delta->dy = (config->pov.camy);
	}
}

void	handle_movement(int keycode, t_config *config)
{
	t_dir	delta;
	int		idx;

	set_delta(&delta, keycode, config);
	idx = 0;
	while (idx <= MOVE_STEP)
	{
		if (config->params->map_raw[(int)(config->pov.location.y + \
			(delta.dy) * (0.05))][(int)(config->pov.location.x + \
			(delta.dx) * (0.05))].val != '1')
		{
			config->pov.location.y += (delta.dy) * (0.02);
			config->pov.location.x += (delta.dx) * (0.02);
		}
		else
			break ;
		idx++;
	}
}

void	handle_angle(int keycode, t_config *config)
{
	if (keycode == XK_LEFT)
		config->pov.angle -= 5;
	else if (keycode == XK_RIGHT)
		config->pov.angle += 5;
	make_player_vector(config);
}

int	handle_key(int keycode, t_config *config)
{
	if (keycode == KEY_ESCAPE)
		close_all(config);
	else if (keycode == XK_W || keycode == XK_A \
			|| keycode == XK_S || keycode == XK_D)
		handle_movement(keycode, config);
	else if (keycode == XK_LEFT || keycode == XK_RIGHT)
		handle_angle(keycode, config);
	cub3d(config);
	return (0);
}

int	close_all(t_config *config)
{
	free_texture_with_count(config, 3);
	free_config(config);
	exit(0);
	return (0);
}

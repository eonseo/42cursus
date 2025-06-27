/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:56:07 by eonoh             #+#    #+#             */
/*   Updated: 2025/03/24 14:14:46 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	cub3d(t_config *config)
{
	ft_bzero(config->img_data->data, \
			(WINDOW_HEIGHT * WINDOW_WIDTH * (config->img_data->bpp / 8)));
	raycasting(config);
	mlx_put_image_to_window(config->mlx_ptr, \
			config->win_ptr, config->img_ptr, 0, 0);
}

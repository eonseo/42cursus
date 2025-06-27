/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:22:04 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/24 14:24:47 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

t_img	*init_img(t_config *config)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->data = mlx_get_data_addr(config->img_ptr,
			&(img->bpp), &(img->size_line), &(img->endian));
	return (img);
}

t_config	*init_config(t_params *params)
{
	t_config	*config;

	config = (t_config *)malloc(sizeof(t_config));
	if (!config)
		return (NULL);
	config->params = params;
	config->mlx_ptr = mlx_init();
	config->win_ptr = mlx_new_window(config->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);
	config->img_ptr = mlx_new_image(config->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	config->img_data = init_img(config);
	initialize_texture(config);
	config->cell_size = 1;
	config->pov.location.color = 0;
	config->pov.location.x = 0;
	config->pov.location.y = 0;
	config->pov.angle = 0;
	return (config);
}

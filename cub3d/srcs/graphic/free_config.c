/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:17:30 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/25 21:12:35 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	free_texture_with_pre_count(t_config *config, int count)
{
	int	idx;

	idx = 0;
	while (idx < count)
	{
		mlx_destroy_image(config->mlx_ptr, config->texture[idx].tex_ptr);
		idx++;
	}
}

void	free_texture_with_count(t_config *config, int count)
{
	int	idx;

	idx = 0;
	while (idx <= count)
	{
		mlx_destroy_image(config->mlx_ptr, config->texture[idx].tex_ptr);
		idx++;
	}
}

int	free_config(t_config *config)
{
	if (!config)
		return (STOP);
	if (config->params)
		free_params(config->params);
	config->params = NULL;
	free(config->img_data);
	mlx_destroy_image(config->mlx_ptr, config->img_ptr);
	mlx_destroy_window(config->mlx_ptr, config->win_ptr);
	mlx_destroy_display(config->mlx_ptr);
	free(config->mlx_ptr);
	free(config);
	return (STOP);
}

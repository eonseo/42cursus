/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:32:45 by eonoh             #+#    #+#             */
/*   Updated: 2025/03/25 21:32:47 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	load_tex(t_config *config, t_tex *texture, char *path, int idx)
{
	if (!path)
		return (STOP);
	texture->path = path;
	texture->tex_ptr = \
		mlx_xpm_file_to_image(config->mlx_ptr, path, \
			&texture->width, &texture->height);
	if (texture->tex_ptr == NULL)
	{
		printf("Error\n:Failed to load texture: %s\n", path);
		free_texture_with_pre_count(config, idx);
		free_config(config);
		exit (EXIT_FAILURE);
	}
	texture->tex_data = mlx_get_data_addr(texture->tex_ptr, &texture->bpp, \
		&texture->size_line, &texture->endian);
	if (texture->tex_data == NULL)
	{
		printf("Error\n:Cannot get texture data: %s\n", path);
		free_texture_with_pre_count(config, idx);
		free_config(config);
		exit (EXIT_FAILURE);
	}
	return (CONTINUE);
}

int	initialize_texture(t_config *config)
{
	if (!(load_tex(config, &config->texture[0], config->params->north_path, 0)))
		return (STOP);
	if (!(load_tex(config, &config->texture[1], config->params->south_path, 1)))
		return (STOP);
	if (!(load_tex(config, &config->texture[2], config->params->east_path, 2)))
		return (STOP);
	if (!(load_tex(config, &config->texture[3], config->params->west_path, 3)))
		return (STOP);
	return (1);
}

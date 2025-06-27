/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:17:11 by eonoh             #+#    #+#             */
/*   Updated: 2025/03/25 21:29:54 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	find_color_in_texture(t_config *config, t_dda *dda, int y)
{
	unsigned char	*texture_data;
	unsigned int	pixel_offset;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	texture_data = \
		(unsigned char *)config->texture[dda->wall_direction].tex_data;
	pixel_offset = (y * config->texture[dda->wall_direction].size_line) + \
		dda->tex_x * (config->texture[dda->wall_direction].bpp / 8);
	r = texture_data[pixel_offset + 2];
	g = texture_data[pixel_offset +1];
	b = texture_data[pixel_offset];
	return ((r << 16) | (g << 8) | b);
}

void	draw_texture_line(t_config *config, t_dda *dda)
{
	double	step;
	double	texture_pos;
	int		display_y;
	int		texture_y;
	int		color;

	step = 1.0 * config->texture[dda->wall_direction].height / \
		dda->vertical_line;
	texture_pos = fabs(dda->draw_start - \
		WINDOW_HEIGHT / 2 + dda->vertical_line / 2) * step;
	display_y = dda->draw_start;
	while (display_y < dda->draw_end)
	{
		texture_y = (int)texture_pos % \
			(config->texture[dda->wall_direction].height - 1);
		texture_pos += step;
		color = find_color_in_texture(config, dda, texture_y);
		put_pixel_in_image(config->img_data, dda->tmp.x, display_y, color);
		display_y++;
	}
}

void	draw_texture(t_config *config, t_dda *dda, t_dir *ray)
{
	get_wall_hit_ratio(config, dda, ray);
	set_wall_direction(dda, ray);
	find_x_pos_on_tex(config, dda, ray);
	get_draw_start(dda);
	get_draw_end(dda);
	draw_texture_line(config, dda);
}

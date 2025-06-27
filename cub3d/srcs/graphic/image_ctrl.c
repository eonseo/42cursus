/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_ctrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:21:42 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/24 14:21:48 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	put_pixel_in_image(t_img *img, int x, int y, int color)
{
	int	pixel;

	if (0 < x && x <= WINDOW_WIDTH && 0 < y && y <= WINDOW_HEIGHT)
	{
		pixel = ((x * (img->bpp / 8)) + (y * img->size_line));
		*(unsigned int *)(img->data + pixel) = color;
	}
}

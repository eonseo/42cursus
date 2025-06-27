/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:28:29 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/24 15:28:54 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

double	return_abs(double a)
{
	if (a < 0)
		return (-a);
	return (a);
}

double	radian_to_degree(double radian)
{
	double	degree;

	degree = radian * (180 / PI);
	return (degree);
}

double	angle_to_radian(double degree)
{
	double	radian;

	radian = degree * (PI / 180);
	return (radian);
}

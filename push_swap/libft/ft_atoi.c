/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:17:25 by eonoh             #+#    #+#             */
/*   Updated: 2024/07/26 17:08:59 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../srcs/push_swap.h"

int	ft_atoi(const char *nptr, t_data *a, char **split)
{
	int			sign;
	int			cnt;
	long long	num;

	sign = 1;
	num = 0;
	cnt = 10;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
		{
			sign = -1;
			cnt++;
		}
		nptr++;
	}
	if (!(*nptr >= '0' && *nptr <= '9'))
		exit_with_error(a, split);
	while (*nptr >= '0' && *nptr <= '9' && cnt-- > 0)
		num = num * 10 + (*nptr++ - '0');
	if (*nptr != '\0' || sign * num > 2147483647 || sign * num < -2147483648)
		exit_with_error(a, split);
	return (sign * num);
}

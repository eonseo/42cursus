/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <yerpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:10:07 by yerpark           #+#    #+#             */
/*   Updated: 2024/03/31 17:05:29 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i = 1;
		n *= (-1);
	}
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*new;
	int		i;
	int		newlen;
	long	num;

	num = (long)n;
	newlen = get_size(num);
	new = (char *)malloc(sizeof(char) * (newlen + 1));
	if (!new)
		return (0);
	i = 0;
	if (num < 0)
	{
		new[0] = '-';
		num *= -1;
	}
	if (num == 0)
		new[0] = '0';
	while (num != 0)
	{
		new[newlen - 1 - i++] = num % 10 + '0';
		num /= 10;
	}
	new[newlen] = '\0';
	return (new);
}

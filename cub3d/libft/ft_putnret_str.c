/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnret_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:10:07 by yerpark           #+#    #+#             */
/*   Updated: 2024/04/24 13:44:33 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnret_char(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putnret_str(char *str)
{
	int	len;

	len = 0;
	if (str == (char *)0)
		return (len = ft_putnret_str("(null)"));
	while (str[len] != '\0')
		len += ft_putnret_char(str[len]);
	return (len);
}

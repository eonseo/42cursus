/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:01:38 by yerpark           #+#    #+#             */
/*   Updated: 2024/04/24 13:43:48 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	casebycase(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putnret_char(va_arg(args, int));
	else if (c == 's')
		len = ft_putnret_str(va_arg(args, char *));
	else if (c == 'p')
		len = ft_putnret_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		len = ft_putnret_nbr(va_arg(args, int));
	else if (c == 'u' || c == 'x' || c == 'X')
		len = ft_putnret_nbrbase(va_arg(args, unsigned int), c);
	else if (c == '%')
		len = ft_putnret_char('%');
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, fmt);
	i = 0;
	len = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
			len += casebycase(fmt[++i], args);
		else
			len += ft_putnret_char(fmt[i]);
		i++;
	}
	va_end(args);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnret_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:14:23 by yerpark           #+#    #+#             */
/*   Updated: 2024/04/24 13:43:56 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnret_nbr(int nbr)
{
	int		len;
	char	digit;

	len = 0;
	if (nbr == -2147483648)
		len = ft_putnret_str("-2147483648");
	else if (nbr < 0)
		len = ft_putnret_char('-') + ft_putnret_nbr(-nbr);
	else if (0 <= nbr && nbr <= 9)
	{
		digit = nbr + '0';
		len += ft_putnret_char(digit);
	}
	else
	{
		len += ft_putnret_nbr(nbr / 10);
		len += ft_putnret_nbr(nbr % 10);
	}
	return (len);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i == 0 || i == 1)
		return (0);
	else
		return (i);
}

int	ft_recursive_nbrbase(unsigned long long nbr, char *base)
{
	int					len;
	unsigned long long	nbase;

	len = 0;
	nbase = (unsigned long long)check_base(base);
	if (nbase == 0)
		return (0);
	if (nbr < nbase)
		len += ft_putnret_char(base[nbr]);
	else
	{
		len += ft_recursive_nbrbase(nbr / nbase, base);
		len += ft_recursive_nbrbase(nbr % nbase, base);
	}
	return (len);
}

int	ft_putnret_nbrbase(unsigned int nbr, char c)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	else if (c == 'u')
		base = "0123456789";
	else
		return (0);
	return (ft_recursive_nbrbase((unsigned long long)nbr, base));
}

int	ft_putnret_ptr(unsigned long long nbr)
{
	char	*hex;
	int		len;

	hex = "0123456789abcdef";
	len = 0;
	if (nbr == 0)
		return (ft_putnret_str("(nil)"));
	else
	{
		len += ft_putnret_str("0x");
		len += ft_recursive_nbrbase(nbr, hex);
		return (len);
	}
}

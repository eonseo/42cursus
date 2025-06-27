/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:56:52 by yerpark           #+#    #+#             */
/*   Updated: 2024/04/24 13:43:30 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_putnret_char(char c);

int	ft_putnret_str(char *str);

int	ft_putnret_nbr(int nbr);

int	ft_putnret_nbrbase(unsigned int nbr, char c);

int	ft_putnret_ptr(unsigned long long nbr);

int	ft_printf(const char *fmt, ...);

#endif

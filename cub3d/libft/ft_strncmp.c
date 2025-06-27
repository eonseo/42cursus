/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <yerpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:11:28 by yerpark           #+#    #+#             */
/*   Updated: 2024/03/25 13:25:28 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmps1;
	unsigned char	*tmps2;

	i = 0;
	tmps1 = (unsigned char *)s1;
	tmps2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((tmps1[i] || tmps2[i]) && (i < n))
	{
		if (tmps1[i] == tmps2[i])
			i++;
		else
			return ((int)(tmps1[i] - tmps2[i]));
	}
	return (0);
}

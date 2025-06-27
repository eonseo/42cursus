/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <yerpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:31:21 by yerpark           #+#    #+#             */
/*   Updated: 2024/03/27 23:25:36 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 1;
			while (big[i + j] && little[j] && (i + j) < len)
			{
				if (big[i + j] == little[j])
					j++;
				else
					break ;
			}
			if (little[j] == '\0' && big[i + j - 1] == little[j - 1])
				return ((char *)(big + i));
		}
		i++;
	}
	return ((char *)0);
}

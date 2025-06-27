/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <yerpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:48:25 by yerpark           #+#    #+#             */
/*   Updated: 2024/03/24 16:49:03 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*new;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!new)
		return (0);
	ft_memset(new, 0, sizeof(char) * (s1len + s2len + 1));
	ft_memmove(new, s1, s1len);
	ft_memmove(new + s1len, s2, s2len);
	new[s1len + s2len] = '\0';
	return (new);
}

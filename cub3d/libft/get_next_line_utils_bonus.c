/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:08:28 by yerpark           #+#    #+#             */
/*   Updated: 2024/07/17 10:44:17 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin_nfree1(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*new;

	s1len = 0;
	s2len = 0;
	while (s1[s1len] != '\0')
		s1len++;
	while (s2[s2len] != '\0')
		s2len++;
	new = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(char) * (s1len + s2len + 1));
	ft_memmove(new, s1, s1len);
	ft_memmove(new + s1len, s2, s2len);
	new[s1len + s2len] = '\0';
	free ((void *)s1);
	s1 = NULL;
	return (new);
}

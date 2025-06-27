/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <yerpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:44:34 by yerpark           #+#    #+#             */
/*   Updated: 2024/03/25 14:26:20 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	setcheck(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	getnewlen(const char *s1, const char *set)
{
	size_t	i;
	size_t	newlen;
	size_t	s1len;

	i = 0;
	s1len = ft_strlen(s1);
	while (setcheck(s1[i], set) == 1 && s1[i])
		i++;
	if (i == s1len)
		return (0);
	else
		newlen = s1len - i;
	i = s1len - 1;
	while (setcheck(s1[i], set) == 1)
		i--;
	newlen -= (s1len - 1 - i);
	return (newlen);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	newlen;

	newlen = getnewlen(s1, set);
	new = (char *)malloc(sizeof(char) * (newlen + 1));
	if (!new)
		return (0);
	if (newlen == 0)
	{
		new[0] = '\0';
		return (new);
	}
	ft_memset(new, 0, sizeof(char) * (newlen + 1));
	i = 0;
	j = 0;
	while (setcheck(s1[i], set) == 1)
		i++;
	while (j < newlen)
	{
		new[j] = s1[i + j];
		j++;
	}
	return (new);
}

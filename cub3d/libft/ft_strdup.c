/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <yerpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:28:50 by yerpark           #+#    #+#             */
/*   Updated: 2024/03/24 19:12:27 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		slen;

	slen = ft_strlen(s);
	new = (char *)malloc(sizeof(char) * (slen + 1));
	if (!new)
		return (0);
	ft_memmove(new, s, slen);
	new[slen] = '\0';
	return (new);
}

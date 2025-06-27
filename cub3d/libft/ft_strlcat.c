/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <yerpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:26:01 by yerpark           #+#    #+#             */
/*   Updated: 2024/03/31 16:53:21 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen + size);
	dstlen = ft_strlen(dst);
	i = 0;
	if (dstlen + 1 <= size)
	{
		while (src[i] && dstlen + i + 1 < size)
		{
			dst[dstlen + i] = src[i];
			i++;
		}
		dst[dstlen + i] = '\0';
		return (srclen + dstlen);
	}
	else
		return (srclen + size);
}

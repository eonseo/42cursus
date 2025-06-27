/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <yerpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:03:27 by yerpark           #+#    #+#             */
/*   Updated: 2024/03/14 22:47:02 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char	*start;
	int		i;

	i = 0;
	start = (char *)str;
	while (str[i] != '\0')
		i++;
	if ((unsigned char)c == '\0')
		return (start + i);
	while (i >= 0)
	{
		if (str[i] == (unsigned char)c)
			return (start + i);
		i--;
	}
	return (0);
}

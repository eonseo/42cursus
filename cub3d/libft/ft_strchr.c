/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <yerpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:56:05 by yerpark           #+#    #+#             */
/*   Updated: 2024/03/15 00:43:26 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	char	*start;
	int		i;

	i = 0;
	start = (char *) str;
	if ((unsigned char)c == '\0')
	{
		while (str[i] != '\0')
			i++;
		return (start + i);
	}
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return (start + i);
		else
			i++;
	}
	return (0);
}

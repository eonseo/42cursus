/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <yerpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:03:08 by yerpark           #+#    #+#             */
/*   Updated: 2024/08/05 00:13:35 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_wrdcnt(const char *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			cnt++;
		}
		while (s[i] == c && s[i])
			i++;
	}
	return (cnt);
}

static int	get_wrdlen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static void	free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free (arr[i]);
		i++;
	}
	free (arr);
}

static int	make_substr(char **arr, char *s, char c, int i)
{
	int	wrdlen;

	wrdlen = get_wrdlen(s, c);
	arr[i] = (char *)malloc(sizeof(char) * wrdlen + 1);
	if (!arr[i])
	{
		free_all(arr);
		return (0);
	}
	ft_strlcpy(arr[i], s, wrdlen + 1);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		wrdcnt;
	int		arr_i;
	char	**result;
	char	*tmp;

	if (s == NULL)
		return (NULL);
	tmp = (char *)s;
	wrdcnt = get_wrdcnt(tmp, c);
	result = (char **)malloc(sizeof(char *) * (wrdcnt + 1));
	if (!result)
		return (0);
	arr_i = 0;
	while (arr_i < wrdcnt)
	{
		while (*tmp == c && *tmp)
			tmp++;
		if (make_substr(result, tmp, c, arr_i) == 0)
			return (0);
		tmp += get_wrdlen(tmp, c);
		arr_i++;
	}
	result[arr_i] = 0;
	return (result);
}

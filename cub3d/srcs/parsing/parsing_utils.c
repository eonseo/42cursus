/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:38:28 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/24 14:10:00 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	remove_newline_from_str(char **str)
{
	int		len;
	char	*new_str;

	if (ft_strchr(*str, '\n') == NULL)
		return ;
	len = ft_strlen(*str);
	if ((*str)[len - 1] != '\n')
		return ;
	new_str = ft_substr(*str, 0, len - 1);
	free (*str);
	*str = new_str;
}

int	remove_space(char *line, int start)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[start + i] == ' ' && line[start + i] != '\0')
		i++;
	return (i);
}

char	*skip_newline(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && ft_strncmp(line, "\n", 2) == 0)
	{
		free (line);
		line = get_next_line(fd);
	}
	if (!line)
		return (NULL);
	return (line);
}

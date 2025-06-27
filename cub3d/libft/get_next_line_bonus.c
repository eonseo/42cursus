/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:08:39 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/26 11:41:28 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*check_storage(char **storage)
{
	char	*nextline;
	char	*tmp;
	int		i;

	if (*storage == NULL)
		return (NULL);
	if (ft_strchr(*storage, '\n') != NULL)
	{
		i = 0;
		while ((*storage)[i] != '\n')
			i++;
		nextline = (char *)malloc(sizeof(char) * (i + 1 + 1));
		if (!nextline)
			return (NULL);
		ft_memmove(nextline, *storage, i + 1);
		nextline[i + 1] = '\0';
		tmp = ft_strdup(ft_strchr(*storage, '\n') + 1);
		if (tmp == NULL)
			return (NULL);
		free (*storage);
		*storage = tmp;
		return (nextline);
	}
	else
		return (NULL);
}

ssize_t	read_as_buffsize(int fd, char **storage)
{
	ssize_t	read_check;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	read_check = read(fd, buffer, BUFFER_SIZE);
	if (read_check <= 0)
	{
		free (buffer);
		buffer = NULL;
	}
	else
	{
		buffer[read_check] = '\0';
		if (*storage == NULL)
			*storage = ft_strdup(buffer);
		else
			*storage = ft_strjoin_nfree1(*storage, buffer);
		free (buffer);
		buffer = NULL;
	}
	return (read_check);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*tmp;
	ssize_t		read_check;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	tmp = check_storage(&storage[fd]);
	if (tmp != NULL)
		return (tmp);
	read_check = 1;
	while (read_check > 0)
	{
		read_check = read_as_buffsize(fd, &storage[fd]);
		tmp = check_storage(&storage[fd]);
		if (tmp != NULL)
			return (tmp);
	}
	if (storage[fd] != NULL)
	{
		tmp = ft_strdup(storage[fd]);
		free (storage[fd]);
		storage[fd] = NULL;
		return (tmp);
	}
	return (NULL);
}

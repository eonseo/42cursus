/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:38:21 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/24 13:59:05 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

t_params	*init_params(void)
{
	t_params	*params;

	params = (t_params *)malloc(sizeof(t_params));
	if (!params)
		return (NULL);
	params->map_raw = NULL;
	params->map_h = 0;
	params->map_w = 0;
	params->north_path = NULL;
	params->south_path = NULL;
	params->west_path = NULL;
	params->east_path = NULL;
	params->floor = -1;
	params->ceiling = -1;
	return (params);
}

int	got_six_info(t_params *params)
{
	if (params->north_path == NULL)
		return (NO);
	if (params->south_path == NULL)
		return (NO);
	if (params->west_path == NULL)
		return (NO);
	if (params->east_path == NULL)
		return (NO);
	if (params->floor == -1)
		return (NO);
	if (params->ceiling == -1)
		return (NO);
	return (YES);
}

int	read_file(t_params *params, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (STOP);
	while (line)
	{
		if (pre_map_parser(params, line) == STOP)
		{
			free (line);
			return (free_params(params));
		}
		free (line);
		if (got_six_info(params) == YES)
			break ;
		line = get_next_line(fd);
	}
	if (map_parser(params, fd) == STOP)
		return (free_params(params));
	return (CONTINUE);
}

void	gnl_cleaner(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free (line);
	}
}

t_params	*file_parsing(char *file)
{
	int			fd;
	t_params	*params;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n");
		return (NULL);
	}
	params = init_params();
	if (!params)
		return (NULL);
	if (read_file(params, fd) == STOP)
	{
		gnl_cleaner(fd);
		close (fd);
		printf("Error\n");
		return (NULL);
	}
	return (params);
}

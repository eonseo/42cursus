/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_and_backup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:38:15 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/24 13:49:53 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static int	is_map_char(char c)
{
	if (c == ' ' || c == '1' || c == '0')
		return (YES);
	else if (c == 'N' || c == 'S')
		return (YES);
	else if (c == 'E' || c == 'W')
		return (YES);
	else
		return (NO);
}

int	check_map_line(t_params *params, char *line, t_mapstr **mapstr)
{
	int	i;

	if (backup_mapstr(line, mapstr) == STOP)
		return (STOP);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n' && line[i + 1] == '\0')
			break ;
		else if (is_map_char(line[i]) == NO)
			return (STOP);
		i++;
	}
	if (i != 0 && i > params->map_w)
		params->map_w = i;
	return (CONTINUE);
}

int	alphabet_cnt_check(t_mapstr *lst, int line_cnt)
{
	int			cnt;
	int			i;
	int			j;
	t_mapstr	*curr;

	if (!lst)
		return (STOP);
	cnt = 0;
	i = -1;
	curr = lst;
	while (++i < line_cnt + 1)
	{
		j = -1;
		while (curr->line[++j] != '\0')
		{
			if (curr->line[j] == 'S' || curr->line[j] == 'N'\
					|| curr->line[j] == 'W' || curr->line[j] == 'E')
				cnt++;
		}
		curr = curr->next;
	}
	if (cnt != 1)
		return (STOP);
	return (CONTINUE);
}

int	check_map_and_backup(t_params *params, int fd, t_mapstr **mapstr)
{
	char	*line;
	int		line_cnt;

	line = skip_newline(fd);
	if (!line)
		return (STOP);
	line_cnt = 0;
	while (line)
	{
		if (check_map_line(params, line, mapstr) == STOP)
		{
			free (line);
			return (STOP);
		}
		line_cnt++;
		free (line);
		line = get_next_line(fd);
	}
	if (line_cnt == 0)
		return (STOP);
	if (alphabet_cnt_check(*mapstr, line_cnt) == STOP)
		return (STOP);
	params->map_h = line_cnt;
	return (CONTINUE);
}

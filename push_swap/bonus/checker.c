/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 22:51:16 by eonoh             #+#    #+#             */
/*   Updated: 2024/07/25 22:09:36 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

int	ft_strcmp(char *line, char *s)
{
	while (*line && *s)
	{
		if (*line != *s)
			return (*line - *s);
		line++;
		s++;
	}
	return (*line - *s);
}

int	find_command(char *line, t_data *a, t_data *b, char bflag)
{
	if (ft_strcmp(line, "sa\n") == 0)
		swap(a, 'a', bflag);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap(b, 'b', bflag);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b, bflag);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b, bflag);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b, bflag);
	else if (ft_strcmp(line, "ra\n") == 0)
		rotate(a, 'a', bflag);
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate(b, 'b', bflag);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b, bflag);
	else if (ft_strcmp(line, "rra\n") == 0)
		reverse_rotate(a, 'a', bflag);
	else if (ft_strcmp(line, "rrb\n") == 0)
		reverse_rotate(b, 'b', bflag);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b, bflag);
	else
		return (1);
	return (0);
}

void	checker(t_data *a, t_data *b, char bflag)
{
	char	*line;
	int		size;

	line = get_next_line(0);
	size = 0;
	while (line != NULL)
	{
		if (find_command(line, a, b, bflag) == 1)
		{
			free_node(a);
			free_node(b);
			free(line);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
		size++;
	}
	free(line);
}

int	main(int argc, char *argv[])
{
	t_data	a;
	t_data	b;
	int		origin_size;

	if (argc < 2 || !argv)
		exit(1);
	a.head = NULL;
	b.head = NULL;
	check_argv(argc, argv, &a);
	origin_size = ft_lstsize(a.head);
	get_rank(&a);
	checker(&a, &b, 'b');
	if (ft_lstsize(a.head) == origin_size && is_increasing_case(&a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_node(&a);
	free_node(&b);
	exit(0);
}

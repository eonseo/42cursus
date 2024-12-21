/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 03:25:04 by eonoh             #+#    #+#             */
/*   Updated: 2024/07/25 21:11:26 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_duplicate(int num, t_data *a, char **argv)
{
	t_list	*tmp;

	tmp = a->head;
	while (tmp)
	{
		if (num == tmp->content)
			exit_with_error(a, argv);
		tmp = tmp->next;
	}
}

void	one_argv_case(char *s, t_data *a)
{
	char	**split;
	int		i;
	int		num;
	int		size;

	i = 0;
	size = 0;
	split = ft_split(s, ' ');
	if (split[0] == NULL)
		exit_with_error(a, split);
	while (split[size])
	{
		num = ft_atoi(split[size], a, split);
		is_duplicate(num, a, split);
		ft_lstadd_back(&(a->head), ft_lstnew(num));
		size++;
	}
	while (i < size)
		free(split[i++]);
	free(split);
}

void	check_argv(int argc, char **argv, t_data *a)
{
	int			i;
	int			num;

	i = 1;
	if (argc == 2)
		one_argv_case(argv[1], a);
	else
	{
		while (argv[i])
		{
			num = ft_atoi(argv[i], a, NULL);
			is_duplicate(num, a, NULL);
			ft_lstadd_back(&(a->head), ft_lstnew(num));
			i++;
		}
	}
}

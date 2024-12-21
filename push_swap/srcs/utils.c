/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 00:35:34 by eonoh             #+#    #+#             */
/*   Updated: 2024/07/25 21:12:59 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_error(t_data *a, char **s)
{
	free_table(s);
	free_node(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_node(t_data *a)
{
	t_list	*tmp;

	while (a->head)
	{
		tmp = a->head->next;
		free(a->head);
		a->head = tmp;
	}
}

void	free_table(char **s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
			free(s[i++]);
	}
	free(s);
}

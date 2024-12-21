/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:54:06 by eonoh             #+#    #+#             */
/*   Updated: 2024/07/22 20:36:24 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_data *stack, char sflag, char bflag)
{
	t_list	*tmp;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	tmp = stack->head->next;
	stack->head->next = tmp->next;
	tmp->next = stack->head;
	stack->head = tmp;
	if (bflag == 'm')
	{
		if (sflag == 'a')
			write(1, "sa\n", 3);
		else if (sflag == 'b')
			write(1, "sb\n", 3);
	}
}

void	ss(t_data *a, t_data *b, char bflag)
{
	swap(a, 's', bflag);
	swap(b, 's', bflag);
	if (bflag == 'm')
		write(1, "ss\n", 3);
}

void	pa(t_data *a, t_data *b, char bflag)
{
	t_list	*tmp;

	if (b->head == NULL)
		return ;
	tmp = b->head->next;
	ft_lstadd_front(&(a->head), b->head);
	b->head = tmp;
	if (bflag == 'm')
		write(1, "pa\n", 3);
}

void	pb(t_data *a, t_data *b, char bflag)
{
	t_list	*tmp;

	if (a->head == NULL)
		return ;
	tmp = a->head->next;
	ft_lstadd_front(&(b->head), a->head);
	a->head = tmp;
	if (bflag == 'm')
		write(1, "pb\n", 3);
}

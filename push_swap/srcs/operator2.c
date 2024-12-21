/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 23:31:08 by eonoh             #+#    #+#             */
/*   Updated: 2024/07/22 20:30:55 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_data *stack, char sflag, char bflag)
{
	t_list	*tmp;

	if (stack->head == NULL)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	tmp->next = NULL;
	ft_lstadd_back(&(stack->head), tmp);
	if (bflag == 'm')
	{
		if (sflag == 'a')
			write(1, "ra\n", 3);
		else if (sflag == 'b')
			write(1, "rb\n", 3);
	}
}

void	rr(t_data *a, t_data *b, char bflag)
{
	rotate(a, 'r', bflag);
	rotate(b, 'r', bflag);
	if (bflag == 'm')
		write(1, "rr\n", 3);
}

void	reverse_rotate(t_data *stack, char sflag, char bflag)
{
	t_list	*tmp;

	if (stack->head == NULL)
		return ;
	tmp = stack->head;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	ft_lstadd_front(&(stack->head), ft_lstlast(stack->head));
	tmp->next = NULL;
	if (bflag == 'm')
	{
		if (sflag == 'a')
			write(1, "rra\n", 4);
		else if (sflag == 'b')
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_data *a, t_data *b, char bflag)
{
	if (a->head == NULL || b->head == NULL)
		return ;
	reverse_rotate(a, 'r', bflag);
	reverse_rotate(b, 'r', bflag);
	if (bflag == 'm')
		write(1, "rrr\n", 4);
}

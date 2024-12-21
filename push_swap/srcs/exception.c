/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:01:08 by eonoh             #+#    #+#             */
/*   Updated: 2024/07/22 20:28:19 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handling_three(t_data *a, char bflag)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	tmp1 = a->head;
	tmp2 = a->head->next;
	tmp3 = tmp2->next;
	if (tmp1->rank == 0 && tmp2->rank == 2 && tmp3->rank == 1)
	{
		reverse_rotate(a, 'a', bflag);
		swap(a, 'a', bflag);
	}
	else if (tmp1->rank == 1 && tmp2->rank == 0 && tmp3->rank == 2)
		swap(a, 'a', bflag);
	else if (tmp1->rank == 1 && tmp2->rank == 2 && tmp3->rank == 0)
		reverse_rotate(a, 'a', bflag);
	else if (tmp1->rank == 2 && tmp2->rank == 0 && tmp3->rank == 1)
		rotate(a, 'a', bflag);
	else if (tmp1->rank == 2 && tmp2->rank == 1 && tmp3->rank == 0)
	{
		swap(a, 'a', bflag);
		reverse_rotate(a, 'a', bflag);
	}
}

void	handling_five(t_data *a, t_data *b, char bflag)
{
	int	cnt;

	cnt = 0;
	while (cnt < 2)
	{
		if (a->head->rank == 3 || a->head->rank == 4)
		{
			pb(a, b, bflag);
			cnt++;
		}
		else
			rotate(a, 'a', bflag);
	}
	if (b->head->rank != 4)
		swap(b, 'b', bflag);
	handling_three(a, bflag);
	pa(a, b, bflag);
	pa(a, b, bflag);
	rotate(a, 'a', bflag);
	rotate(a, 'a', bflag);
}

void	is_descending_case(t_data *a, char bflag)
{
	t_list	*tmp;
	int		size;
	int		des;
	int		cnt;

	if (ft_lstsize(a->head) < 100)
		return ;
	tmp = a->head;
	des = 0;
	size = ft_lstsize(a->head);
	while (tmp->next)
	{
		if (tmp->rank > tmp->next->rank)
			des++;
		tmp = tmp->next;
	}
	if (des >= (size / 3) * 2)
	{
		cnt = 0;
		size = get_chunk(size);
		while (cnt++ < size)
			reverse_rotate(a, 'a', bflag);
	}
}

int	is_increasing_case(t_data *a)
{
	t_list	*tmp;
	int		des;
	int		num;

	tmp = a->head;
	num = a->head->content;
	des = 0;
	while (tmp->next)
	{
		if (tmp->next->content < num)
			des++;
		tmp = tmp->next;
		num = tmp->content;
	}
	if (des == 0)
		return (1);
	return (0);
}

int	handling_exception(t_data *a, t_data *b, char bflag)
{
	int	size;

	size = ft_lstsize(a->head);
	if (bflag == 'm' && is_increasing_case(a) == 1)
	{
		free_node(a);
		exit(1);
	}
	if (size == 3)
	{
		handling_three(a, bflag);
		return (0);
	}
	else if (size == 5)
	{
		handling_five(a, b, bflag);
		return (0);
	}
	is_descending_case(a, bflag);
	return (1);
}

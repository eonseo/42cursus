/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hourglass.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:33:04 by eonoh             #+#    #+#             */
/*   Updated: 2024/07/22 20:08:49 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_rank(t_data *stack)
{
	t_list	*rtmp;
	t_list	*ctmp;

	ctmp = stack->head;
	while (ctmp)
	{
		ctmp->rank = 0;
		rtmp = stack->head;
		while (rtmp)
		{
			if (rtmp->content < ctmp->content)
			{
				ctmp->rank ++;
				stack->rank_max = ctmp->rank;
			}
			rtmp = rtmp->next;
		}
		ctmp = ctmp->next;
	}
}

int	get_chunk(int size)
{
	return ((0.000000053 * (size * size)) + (0.03 * (size)) + 14.5);
}

void	move_to_b(t_data *a, t_data *b, char bflag)
{
	int	chunk_max;
	int	chunk_min;

	chunk_max = get_chunk(ft_lstsize(a->head));
	chunk_min = 0;
	while (a->head)
	{
		if (a->head->rank >= chunk_min && a->head->rank <= chunk_max)
		{
			pb(a, b, bflag);
			chunk_min++;
			chunk_max++;
		}
		else if (a->head->rank <= chunk_min)
		{
			pb(a, b, bflag);
			rotate(b, 'b', bflag);
			chunk_min++;
			chunk_max++;
		}
		else
			rotate(a, 'a', bflag);
	}
}

int	get_cost(t_data *b, int rank_max)
{
	int		rcount;
	int		idx;
	t_list	*tmp;

	tmp = b->head;
	idx = (ft_lstsize(b->head) + 1) / 2;
	rcount = 0;
	while (idx-- > 0)
	{
		if (tmp->rank == rank_max)
			return (rcount);
		rcount++;
		tmp = tmp->next;
	}
	return (-1);
}

void	move_to_a(t_data *a, t_data *b, char bflag)
{
	int		rank_max;
	int		cost;

	rank_max = ft_lstsize(b->head) - 1;
	while (rank_max >= 0)
	{
		cost = get_cost(b, rank_max);
		if (cost != -1)
		{
			while (b->head->rank != rank_max)
				rotate(b, 'b', bflag);
			pa(a, b, bflag);
		}
		else
		{
			while (b->head->rank != rank_max)
				reverse_rotate(b, 'b', bflag);
			pa(a, b, bflag);
		}
		rank_max--;
	}
}

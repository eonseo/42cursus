/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 00:33:37 by eonoh             #+#    #+#             */
/*   Updated: 2024/07/23 00:25:53 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	a;
	t_data	b;

	if (argc < 2 || !argv)
		exit(1);
	a.head = NULL;
	b.head = NULL;
	check_argv(argc, argv, &a);
	get_rank(&a);
	if (handling_exception(&a, &b, 'm') == 0)
	{
		free_node(&a);
		exit(0);
	}
	move_to_b(&a, &b, 'm');
	move_to_a(&a, &b, 'm');
	free_node(&a);
	exit(0);
}

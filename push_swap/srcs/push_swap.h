/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 03:00:48 by eonoh             #+#    #+#             */
/*   Updated: 2024/07/26 17:09:08 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../get_next_line/mandatory/get_next_line.h"

# include <stdlib.h>
# include <stdio.h>

// utils.c
void	exit_with_error(t_data *a, char **split);
void	free_node(t_data *a);
void	free_table(char **s);

// check_argv.c
void	is_duplicate(int num, t_data *a, char **argv);
void	one_argv_case(char *s, t_data *a);
void	check_argv(int argc, char **argv, t_data *a);

// operator1.c
void	swap(t_data *stack, char cflag, char bflag);
void	ss(t_data *a, t_data *b, char bflag);
void	pa(t_data *a, t_data *b, char bflag);
void	pb(t_data *a, t_data *b, char bflag);

// operator2.c
void	rotate(t_data *stack, char cflag, char bflag);
void	rr(t_data *a, t_data *b, char bflag);
void	reverse_rotate(t_data *stack, char cflag, char bflag);
void	rrr(t_data *a, t_data *b, char bflag);

// hourglass.c
void	get_rank(t_data *stack);
int		get_chunk(int size);
void	move_to_b(t_data *a, t_data *b, char bflag);
void	move_to_a(t_data *a, t_data *b, char bflag);
int		get_cost(t_data *b, int rank_max);

// exception.c
void	handling_three(t_data *a, char bflag);
void	handling_five(t_data *a, t_data *b, char bflag);
int		handling_exception(t_data *a, t_data *b, char bflag);
int		is_increasing_case(t_data *a);
void	is_descending_case(t_data *a, char bflag);

// bonus/checker.c
int		ft_strcmp(char *line, char *s);
int		find_command(char *line, t_data *a, t_data *b, char bflag);
void	checker(t_data *a, t_data *b, char bflag);

#endif
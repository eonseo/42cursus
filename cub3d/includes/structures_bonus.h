/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:28:16 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/25 21:31:08 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_BONUS_H
# define STRUCTURES_BONUS_H

# include "values.h"
# include "structures.h"

typedef struct s_bonus
{
	int			mouse_x;
	int			mini_map_flag;
	t_config	*config;
}			t_bonus;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:11:32 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/25 21:31:36 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_BONUS_H
# define FUNCTIONS_BONUS_H

# include "structures_bonus.h"

int		handle_key_bonus(int keycode, t_bonus *bonus);
int		handle_mouse(int x, int y, t_bonus *bonus);
void	draw_full_cell(int row, int col, t_config *config);
void	draw_empty_cell(int row, int col, t_config *config);
void	draw_map_grid(t_config *config);
void	draw_minimap_ray(t_config *config, t_dir ray);
void	mini_map(t_config *config);

#endif

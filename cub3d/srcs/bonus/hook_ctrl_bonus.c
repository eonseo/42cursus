/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   hook_ctrl_bonus.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>	   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/25 21:09:50 by eonoh			 #+#	#+#			 */
/*   Updated: 2025/03/25 21:09:59 by eonoh			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/cub_bonus.h"

int	handle_mouse(int x, int y, t_bonus *bonus)
{
	double	diff;

	(void)y;
	diff = bonus->mouse_x - x;
	if (fabs(diff) < WINDOW_WIDTH / 45)
		return (0);
	bonus->config->pov.angle += diff / 2;
	make_player_vector(bonus->config);
	cub3d(bonus->config);
	if (bonus->mini_map_flag == 1)
		mini_map(bonus->config);
	bonus->mouse_x = x;
	return (1);
}

int	handle_key_bonus(int keycode, t_bonus *bonus)
{
	if (keycode == KEY_ESCAPE)
		close_all(bonus->config);
	else if (keycode == XK_W || keycode == XK_A \
			|| keycode == XK_S || keycode == XK_D)
		handle_movement(keycode, bonus->config);
	else if (keycode == XK_LEFT || keycode == XK_RIGHT)
		handle_angle(keycode, bonus->config);
	else if (keycode == XK_M)
	{
		if (bonus->mini_map_flag == 0)
			bonus->mini_map_flag = 1;
		else
			bonus->mini_map_flag = 0;
	}
	cub3d(bonus->config);
	if (bonus->mini_map_flag == 1)
		mini_map(bonus->config);
	return (0);
}

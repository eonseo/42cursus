/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:28:11 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/25 21:43:56 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structures.h"

void		cub3d(t_config *config);
t_line		*init_line(t_dot start, t_dot end);
void		dda_line(t_dot start, t_dot end, t_config *config);
void		draw_horizon_line(t_config *config, int i, int j);
void		draw_vertical_line(t_config *config, int i, int j);
void		put_map_grid_to_img(t_config *config);
void		draw_player(t_config *config);
void		free_texture_with_pre_count(t_config *config, int count);
void		free_texture_with_count(t_config *config, int count);
int			free_config(t_config *config);
void		set_delta(t_dir *delta, int keycode, t_config *config);
void		handle_movement(int keycode, t_config *config);
void		handle_angle(int keycode, t_config *config);
int			handle_key(int keycode, t_config *config);
int			close_all(t_config *config);
void		put_pixel_in_image(t_img *img, int x, int y, int color);
t_img		*init_img(t_config *config);
t_config	*init_config(t_params *params);
void		init_dda_setting1(t_config *config, t_dir ray, t_dda *dda);
void		init_dda_setting2(t_dir ray, t_dda *dda);
int			load_tex(t_config *config, t_tex *texture, char *path, int idx);
int			initialize_texture(t_config *config);
int			check_angle(char val);
void		make_player_vector(t_config *config);
void		init_player_pov(t_config *config);
double		get_dist_with_dda(t_config *config, t_dir ray, t_dda *dda);
void		draw_ceiling_and_floor(t_config *config, t_dot tmp);
void		draw_vertical_line_with_dist(t_config *config, \
			t_dir ray, int win_idx);
void		raycasting(t_config *config);
void		setup_mapinfo(t_config *config);
double		return_abs(double a);
double		angle_to_radian(double degree);
double		radian_to_degree(double radian);
int			is_thisdot_in_scaled_wallarea(t_dot dot, t_config *config);
int			is_thisdot_in_wallarea(t_dot dot, t_config *config);
double		get_wall_hit_ratio(t_config *config, t_dda *dda, t_dir *ray);
int			find_x_pos_on_tex(t_config *config, t_dda *dda, t_dir *ray);
int			get_draw_start(t_dda *dda);
int			get_draw_end(t_dda *dda);
int			find_color_in_texture(t_config *config, t_dda *dda, int y);
void		draw_texture_line(t_config *config, t_dda *dda);
int			set_wall_direction(t_dda *dda, t_dir *ray);
void		draw_texture(t_config *config, t_dda *dda, t_dir *ray);
int			check_extension(char *filename);
int			check_argv(int ac, char **av);
int			check_map_line(t_params *params, char *line, t_mapstr **mapstr);
int			alphabet_cnt_check(t_mapstr *lst, int line_cnt);
int			check_map_and_backup(t_params *params, int fd, t_mapstr **mapstr);
int			floor_parser(t_params *params, char **split);
int			ceiling_parser(t_params *params, char **split);
int			north_parser(t_params *params, char **split);
int			south_parser(t_params *params, char **split);
int			west_parser(t_params *params, char **split);
int			east_parser(t_params *params, char **split);
t_params	*init_params(void);
int			got_six_info(t_params *params);
int			read_file(t_params *params, int fd);
t_params	*file_parsing(char *file);
int			free_split(char ***split, int idx);
int			free_mapstr(t_mapstr *mapstr);
int			free_mapraw(t_coord **map, int map_h);
int			free_params(t_params *params);
int			make_map_into_arr(t_params *params, t_mapstr *mapstr);
int			check_neighbor(t_coord **map, int x, int y);
int			map_border_check(t_params *params);
int			map_parser(t_params *params, int fd);
void		mapstr_addback(t_mapstr **lst, t_mapstr *newstr);
int			backup_mapstr(char *line, t_mapstr **mapstr);
void		remove_newline_from_str(char **str);
int			remove_space(char *line, int start);
char		*skip_newline(int fd);
int			process_by_type(t_params *params, char **split);
int			pre_map_parser(t_params *params, char *line);

#endif

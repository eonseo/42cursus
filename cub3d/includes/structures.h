/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:28:21 by yerpark           #+#    #+#             */
/*   Updated: 2025/03/25 21:30:51 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "values.h"

enum{
	STOP,
	CONTINUE
};

enum{
	YES,
	NO
};

enum{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

typedef struct s_dot{
	double	x;
	double	y;
	int		color;
}			t_dot;

typedef struct s_coord{
	char	val;
	int		amihere;
	t_dot	pos;
}			t_coord;

typedef struct s_mapstr{
	char			*line;
	struct s_mapstr	*prev;
	struct s_mapstr	*next;
}					t_mapstr;

typedef struct s_params{
	t_coord		**map_raw;
	int			map_h;
	int			map_w;
	char		*north_path;
	char		*south_path;
	char		*west_path;
	char		*east_path;
	int			floor;
	int			ceiling;
}			t_params;

typedef struct s_dir{
	double	dx;
	double	dy;
}				t_dir;

typedef struct s_dda{
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	int		map_x;
	int		map_y;
	double	pos_x;
	double	pos_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		wall_direction;
	double	tex_w;
	double	distance;
	double	vertical_line;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	double	hit_ratio;
	int		tex_x;
	int		tex_start_y;
	double	step;
	t_dot	tmp;
	double	rrr;
}			t_dda;

typedef struct s_line{
	t_dot	start;
	t_dot	end;
	int		step;
	double	dx;
	double	dy;
	double	inc_x;
	double	inc_y;
}			t_line;

typedef struct s_img{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}		t_img;

typedef struct s_pov{
	t_dot	location;
	double	angle;
	double	dirx;
	double	diry;
	double	camx;
	double	camy;
}			t_pov;

typedef struct s_tex {
	char	*path;
	void	*tex_ptr;
	void	*tex_data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}			t_tex;

typedef struct s_config{
	t_params	*params;
	t_tex		texture[4];
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_img		*img_data;
	t_pov		pov;
	int			cell_size;
}				t_config;

#endif

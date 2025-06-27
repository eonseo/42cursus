NAME = cub3D
MLX = minilibx-linux/libmlx_Linux.a
LFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LBFLAGS = -lmlx -lX11 -lXext -lm

LFTDIR = libft
MLXDIR = minilibx-linux
SRCSDIR = srcs/
OBJSDIR = objs/

MAIN_FILE = main.c

MAIN_FILE_BONUS = main_bonus.c

FILE = parsing/check_argv.c \
	parsing/check_map_and_backup.c \
	parsing/color_parser.c \
	parsing/direction_parser.c \
	parsing/file_parsing.c \
	parsing/free_parsing.c \
	parsing/make_map_into_arr.c \
	parsing/map_parser.c \
	parsing/parsing_utils.c \
	parsing/pre_map_parser.c \
	parsing/mapstr_ctrl.c \
	graphic/init_config.c \
	graphic/dda_line.c \
	graphic/image_ctrl.c \
	graphic/utils.c \
	graphic/player.c \
	graphic/cub3d.c \
	graphic/hook_ctrl.c \
	graphic/free_config.c \
	graphic/wall_collision.c \
	graphic/raycasting.c \
	graphic/setup_mapinfo.c \
	graphic/init_dda_setting.c \
	graphic/init_textures.c \
	graphic/texture_draw.c \
	graphic/texture_rendering_info.c

FILE_BONUS = bonus/mini_map.c \
			bonus/hook_ctrl_bonus.c \

SRCS = $(addprefix $(SRCSDIR), $(FILE))
OBJS = $(SRCS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)

MAIN_SRC = $(addprefix $(SRCSDIR), $(MAIN_FILE))
MAIN_OBJ = $(MAIN_SRC:$(SRCSDIR)%.c=$(OBJSDIR)%.o)
MAIN_SRC_BONUS = $(addprefix $(SRCSDIR), $(MAIN_FILE_BONUS))
MAIN_OBJ_BONUS = $(MAIN_SRC_BONUS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)

SRCS_BONUS = $(addprefix $(SRCSDIR), $(FILE_BONUS))
OBJS_BONUS = $(SRCS_BONUS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)

ifdef WITH_BONUS
	OBJECTS = $(OBJS) $(OBJS_BONUS) $(MAIN_OBJ_BONUS)
else
	OBJECTS = $(OBJS) $(MAIN_OBJ)
endif

all : $(NAME)

$(NAME) : $(OBJECTS) $(MLX) $(LFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LBFLAGS) -L$(MLXDIR) -lmlx $(LFT)

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -g -c -o $@ $<

$(MLX) :
	@make -C $(MLXDIR)

$(LFT):
	@make -C $(LFTDIR)

bonus: $(OBJSDIR_BONUS)
	@make WITH_BONUS=1 all

clean :
	rm -rf $(OBJSDIR)
	make clean -C $(LFTDIR)/

fclean : clean
	rm -rf $(NAME)
	make fclean -C $(LFTDIR)/
	make clean -C $(MLXDIR)/

re : fclean all

.PHONY: all re clean fclean bonus
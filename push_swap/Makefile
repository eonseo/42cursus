CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

SRC = ./srcs/push_swap.c \
		./srcs/utils.c \
		./srcs/check_argv.c \
		./srcs/operator1.c \
		./srcs/operator2.c \
		./srcs/hourglass.c \
		./srcs/exception.c
BSRC = ./get_next_line/mandatory/get_next_line.c \
		./get_next_line/mandatory/get_next_line_utils.c \
		./bonus/checker.c \
		./srcs/utils.c \
		./srcs/check_argv.c \
		./srcs/operator1.c \
		./srcs/operator2.c \
		./srcs/hourglass.c \
		./srcs/exception.c
SOBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)
MTARGET = push_swap
BTARGET = checker

ifndef BONUS
OBJS = $(SOBJ)
else
OBJS = $(BOBJ)
endif

ifndef BONUS
TARGET = $(MTARGET)
else
TARGET = $(BTARGET)
endif

all: $(TARGET)

$(TARGET): $(OBJS)
	@make -C ./libft
	@$(CC) $(CFLAGS) -o $@ $(OBJS) ./libft/libft.a

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I ./ 

bonus:
	@make BONUS=1 all

clean:
	@make -C ./libft clean
	@$(RM) $(OBJS)

fclean: clean
	@make -C ./libft fclean
	@$(RM) $(TARGET)

re: fclean all

.PHONY: all clean fclean re

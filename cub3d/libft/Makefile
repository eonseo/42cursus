# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yerpark <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 20:14:51 by yerpark           #+#    #+#              #
#    Updated: 2024/08/02 07:54:36 by yerpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC
NAME = libft.a
SOURCES = ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strncmp.c\
	ft_memcmp.c\
	ft_atoi.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_calloc.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_strlen.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strnstr.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	get_next_line_bonus.c\
	get_next_line_utils_bonus.c\
	ft_realloc.c\
	ft_printf.c\
	ft_putnret_nbr.c\
	ft_putnret_str.c\
	
SOURCES_BONUS = ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c

OBJS = $(SOURCES:.c=.o)
OBJS_BONUS = $(SOURCES_BONUS:.c=.o)

ifdef WITH_BONUS
	OBJECTS = $(OBJS) $(OBJS_BONUS)
else
	OBJECTS = $(OBJS)
endif

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -rcs $@ $^

bonus:
	@make WITH_BONUS=1 all 

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -g

clean: 
	@rm -f $(OBJS) $(OBJS_BONUS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

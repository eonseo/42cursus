/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:07:17 by yerpark           #+#    #+#             */
/*   Updated: 2024/05/12 16:30:42 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	*ft_memset(void *dest, int c, size_t count);

void	*ft_memmove(void *dest, const void *src, size_t n);

char	*ft_strjoin_nfree1(char const *s1, char const *s2);

char	*ft_strdup(const char *s);

char	*ft_strchr(const char *str, int c);

char	*get_next_line(int fd);

char	*check_storage(char **storage);

ssize_t	read_as_buffsize(int fd, char **storage);

#endif

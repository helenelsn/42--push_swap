/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:17:36 by hlesny            #+#    #+#             */
/*   Updated: 2022/11/28 17:45:02 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <strings.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_substr(char *str, int len);
int		parse_buffer(char *buffer);
char	*ft_strncat(char *line, char *buffer, int len);
char	*strncat2(char *line, char *buffer, int len);
void	save_buffer(char *buffer, int len);
char	*get_line(int fd, char *buffer, char *line, int index_n);

#endif
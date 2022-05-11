/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:11:30 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/11 12:34:02 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "struct.h"

char	*get_next_line(int fd);
char	*str_to_out(char *str);
char	*next_str(char *str);
char	*read_line(int fd, char *str);
int		ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);

#endif

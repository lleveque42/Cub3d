/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:59:40 by arudy             #+#    #+#             */
/*   Updated: 2022/05/11 23:57:50 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "struct.h"

int			ft_atoll(char *n);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_atoi(char *nptr);
int			ft_is_whitespace(int c);
int			ft_strcmp(char *s1, char *s2);
int			ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_bzero(void *s, size_t n);
void		ft_putstr_fd(char *s, int fd);
void		free_strs(char **strs, t_data *data);
char		*ft_strchr(char *s, int c);
char		*ft_itoa(int n, t_data *data);
char		*ft_strdup(char *s, t_data *data);
char		*ft_strcdup(char *s, char c, t_data *data);
void		*ft_calloc(size_t nmemb, size_t size, t_data *data);
char		*ft_strjoin(char *s1, char *s2, t_data *data);
char		*ft_strldup(char *s, size_t size, t_data *data);
char		**ft_split(char const *s, char c, t_data *data);
char		*ft_strjoin_char(char *s, char c, t_data *data);
char		*ft_substr(char const *s, unsigned int start, size_t len, \
t_data *data);
size_t		ft_strlen(const char *str);

#endif

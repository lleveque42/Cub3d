/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:28:53 by lleveque          #+#    #+#             */
/*   Updated: 2022/06/01 01:45:47 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "struct.h"

int		ft_exit_esc(t_data *data);
int		ft_exit(t_data *data, char *msg, int value);
int		create_trgb(int t, int r, int g, int b);
void	free_all(t_data *data);
void	init_null_1(t_data *data);
void	init_null_2(t_data *data);
void	init_null_3(t_data *data);
void	init_null_4(t_data *data);
void	ft_free(void *ptr, t_data *data);
void	ft_free_garbage(t_garbage *garbage);
void	*ft_malloc(size_t size, t_data *data);
void	pixel_put(t_data *data, int x, int y, int color);
void	ft_exit_message(char *msg, t_data *data, int value);
void	ft_exit_perror(char *s, t_data *data, int exit_value);
void	ft_exit_rgb_error(char c, char *msg, t_data *data, int value);
void	ft_exit_texture_error(char *id, char *msg, t_data *data, int value);
void	ft_exit_invalid_file(char *file, char *msg, t_data *data, int value);
char	*get_next_line(int fd, t_data *data);
t_data	*init_data(char *input);

#endif

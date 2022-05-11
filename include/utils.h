/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:28:53 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/11 12:22:04 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "struct.h"

void	free_all(t_data *data);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_free(void *ptr, t_data *data);
void	*ft_malloc(size_t size, t_data *data);
t_data	*init_data(char *input);

#endif

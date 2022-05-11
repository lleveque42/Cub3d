/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:28:53 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/11 11:30:58 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	free_all(t_data *data);
void	ft_free(void *ptr, t_data *data);
void	*ft_malloc(size_t size, t_data *data);
t_data	*init_data(char *input);

#endif

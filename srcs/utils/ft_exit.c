/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:13:23 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/12 11:14:24 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_exit_message(char *msg, t_data *data, int value)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	free_all(data);
	exit(value);
}

void	ft_exit_invalid_file(char *file, char *msg, t_data *data, int value)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	free_all(data);
	exit(value);
}

void	ft_exit_texture_error(char *id, char *msg, t_data *data, int value)
{
	ft_putstr_fd("Error\nIdentifier ", 2);
	ft_putstr_fd(id, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	free_all(data);
	exit(value);
}

void	ft_exit_rgb_error(char c, char *msg, t_data *data, int value)
{
	ft_putstr_fd("Error\n", 2);
	write(2, &c, 1);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	free_all(data);
	exit(value);
}

void	ft_exit(t_data *data, int exit_value)
{
	free_all(data);
	exit(exit_value);
}

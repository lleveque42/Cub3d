/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:28:30 by arudy             #+#    #+#             */
/*   Updated: 2022/05/12 01:40:42 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	scan_buff(t_data *data, char *buff)
{
	if (!data->filled && !textures_all_filled(data))
	{
		while (*buff && ft_is_whitespace(*buff))
			buff++;
		if (is_texture(buff, data))
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd(data->filename, 2);
			ft_putstr_fd(" is invalid\n", 2);
			ft_exit(data, 1);
		}
		data->map_fd->begin++;
	}
	else if (data->map_fd->height == 0)
	{
		while (*buff && ft_is_whitespace(*buff))
			buff++;
		if (*buff && *buff != '\n')
			data->map_fd->height++;
		else
			data->map_fd->begin++;
	}
	else
		data->map_fd->height++;
}

void	fill_map(t_data *data)
{
	char	*buff;

	while (1)
	{
		buff = get_next_line(data->in_fd, data);
		if (!buff)
			break ;
		scan_buff(data, buff);
		ft_free(buff, data);
	}
}

int	parsing(t_data *data)
{
	fill_map(data);
	if (!textures_all_filled(data))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(data->filename, 2);
		ft_putstr_fd(" file not valid\n", 2);
	}
	return (0);
}

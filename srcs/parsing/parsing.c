/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:28:30 by arudy             #+#    #+#             */
/*   Updated: 2022/05/11 18:39:56 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	scan_buff(t_data *data, char *buff)
{
	if (!textures_all_filled(data))
	{
		while (ft_is_whitespace(*buff))
			buff++;
		is_texture(buff, data);
	}
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
	ft_free(buff, data);
}

int	parsing(t_data *data)
{
	fill_map(data);
	printf("NO : %s\n", data->texture->no_path);
	printf("SO : %s\n", data->texture->so_path);
	printf("EA : %s\n", data->texture->ea_path);
	printf("WE : %s\n", data->texture->we_path);
	return (0);
}

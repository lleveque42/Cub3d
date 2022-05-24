/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:58:41 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/24 17:08:15 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	find_player_data(char **s, int x, int y, t_data *data)
{
	if (data->player->dir)
		ft_exit_message("Map is invalid: only 1 player", data, 1);
	data->player->dir = s[y][x];
	data->player->x = x + 0.5;
	data->player->y = y + 0.5;
	data->player->old_y = data->player->y;
	data->player->old_x = data->player->x;
	if (data->player->dir == 'N')
		data->player->angle = 3 * PI / 2;
	else if (data->player->dir == 'S')
		data->player->angle = PI / 2;
	else if (data->player->dir == 'E')
		data->player->angle = 0;
	else if (data->player->dir == 'W')
		data->player->angle = PI;
	data->player->dir_x = cos(data->player->angle) * 5;
	data->player->dir_y = sin(data->player->angle) * 5;
	data->player->old_dx = data->player->dir_x;
	data->player->old_dy = data->player->dir_y;
	data->ray->plane_x = 0;
	data->ray->plane_y = 0.66;
	data->player->change = 1;
}

int	check_line(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		if (!ft_is_whitespace(buff[i]))
			return (1);
		i++;
	}
	return (0);
}

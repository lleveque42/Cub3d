/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:58:41 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/16 19:25:46 by lleveque         ###   ########.fr       */
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
	if (s[y][x] == 'N')
		data->player->angle = 3 * PI / 2;
	else if (s[y][x] == 'S')
		data->player->angle = PI / 2;
	else if (s[y][x] == 'E')
		data->player->angle = 0;
	else if (s[y][x] == 'W')
		data->player->angle = PI;
	data->player->dx = cos(data->player->angle) * 5;
	data->player->dy = sin(data->player->angle) * 5;
	data->player->old_dx = data->player->dx;
	data->player->old_dy = data->player->dy;
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

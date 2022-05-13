/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:58:41 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/13 17:13:59 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	find_player_data(char **s, int x, int y, t_data *data)
{
	if (data->player->dir)
		ft_exit_message("Map is invalid: only 1 player", data, 1);
	data->player->dir = s[y][x];
	data->player->x = x;
	data->player->y = y;
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

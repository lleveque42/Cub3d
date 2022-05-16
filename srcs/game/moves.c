/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:03:37 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/16 16:13:35 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_forward(t_data *data)
{
	// int y_copy = data->player->y;
	// int x_copy = data->player->x;
	// float res;
	// res = y_copy - data->player->y - 0.1;
	// if (res <= 0 && data->map[y_copy][x_copy] != '1')
		data->player->y -= SPEED_TEST;
	// if ()
}

void	move_backward(t_data *data)
{
	// int y_copy = data->player->y;
	// int x_copy = data->player->x;
	// float res;
	// res = y_copy - data->player->y + 0.1;
	// if (res <= 0 && data->map[y_copy + 1][x_copy] != '1')
		data->player->y += SPEED_TEST;
}

void	move_right(t_data *data)
{
	// int y_copy = data->player->y;
	// int x_copy = data->player->x;
	// float res;
	// res = x_copy - data->player->x + 0.1;
	// if (res <= 0 && data->map[y_copy][x_copy + 1] != '1')
		data->player->x += SPEED_TEST;
}

void	move_left(t_data *data)
{
	// int y_copy = data->player->y;
	// int x_copy = data->player->x;
	// float res;
	// res = x_copy - data->player->x - 0.1;
	// if (res <= 0 && data->map[y_copy][x_copy] != '1')
		data->player->x -= SPEED_TEST;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:03:37 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/24 14:09:37 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_forward(t_data *data)
{
	if (data->map[(int)(data->player->y / TILE_SIZE)][(int)((data->player->x + data->player->dir_x * SPEED_TEST) / TILE_SIZE)] != '1')
	{
		data->player->x += data->player->dir_x * SPEED_TEST;
		data->player->change = 1;
	}
	if (data->map[(int)((data->player->y + data->player->dir_y + 1 * SPEED_TEST) / TILE_SIZE)][(int)(data->player->x / TILE_SIZE)] != '1')
	{
		data->player->y += data->player->dir_y * SPEED_TEST;
		data->player->change = 1;
	}

}

void	move_backward(t_data *data)
{
	if (data->map[(int)(data->player->y / TILE_SIZE)][(int)((data->player->x - data->player->dir_x * SPEED_TEST) / TILE_SIZE)] != '1')
	{
		data->player->x -= data->player->dir_x * SPEED_TEST;
		data->player->change = 1;
	}
	if (data->map[(int)((data->player->y - data->player->dir_y * SPEED_TEST) / TILE_SIZE)][(int)(data->player->x / TILE_SIZE)] != '1')
	{
		data->player->y -= data->player->dir_y * SPEED_TEST;
		data->player->change = 1;
	}
}

void	move_right(t_data *data)
{
	if (data->map[(int)((data->player->y - -data->player->dir_x * SPEED_TEST) / TILE_SIZE)][(int)(data->player->x / TILE_SIZE)] != '1')
	{
		data->player->y -= -data->player->dir_x * SPEED_TEST;
		data->player->change = 1;
	}
	if (data->map[(int)((data->player->y) / TILE_SIZE)][(int)((data->player->x - data->player->dir_y * SPEED_TEST) / TILE_SIZE)] != '1')
	{
		data->player->x -= data->player->dir_y * SPEED_TEST;
		data->player->change = 1;
	}
}

void	move_left(t_data *data)
{
	if (data->map[(int)((data->player->y + -data->player->dir_x * SPEED_TEST) / TILE_SIZE)][(int)(data->player->x / TILE_SIZE)] != '1')
	{
		data->player->y += -data->player->dir_x * SPEED_TEST;
		data->player->change = 1;
	}
	if (data->map[(int)((data->player->y) / TILE_SIZE)][(int)((data->player->x + data->player->dir_y * SPEED_TEST) / TILE_SIZE)] != '1')
	{
		data->player->x += data->player->dir_y * SPEED_TEST;
		data->player->change = 1;
	}
}

void	get_pos(t_data *data)
{
	data->player->old_y = data->player->y;
	data->player->old_x = data->player->x;
	if (data->key->w_pressed == 1)
		move_forward(data);
	if (data->key->s_pressed == 1)
		move_backward(data);
	if (data->key->a_pressed == 1)
		move_left(data);
	if (data->key->d_pressed == 1)
		move_right(data);
	if (data->key->la_pressed == 1)
		rotate_left(data);
	if (data->key->lr_pressed == 1)
		rotate_right(data);
}

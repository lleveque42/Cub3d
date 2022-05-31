/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:03:37 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/31 14:05:17 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_forward(t_data *data)
{
	if (data->map[(int)(data->player->x + (data->player->dir_x
			* SPEED_TEST))][(int)data->player->y] != '1')
	{
		data->player->x += data->player->dir_x * SPEED_TEST;
		data->player->change = 1;
	}
	if (data->map[(int)data->player->x][(int)(data->player->y
		+ data->player->dir_y * SPEED_TEST)] != '1')
	{
		data->player->y += data->player->dir_y * SPEED_TEST;
		data->player->change = 1;
	}
}

void	move_backward(t_data *data)
{
	if (data->map[(int)(data->player->x - data->player->dir_x * SPEED_TEST)]
		[(int)data->player->y] != '1')
	{
		data->player->x -= data->player->dir_x * SPEED_TEST;
		data->player->change = 1;
	}
	if (data->map[(int)data->player->x][(int)(data->player->y
		- data->player->dir_y * SPEED_TEST)] != '1')
	{
		data->player->y -= data->player->dir_y * SPEED_TEST;
		data->player->change = 1;
	}
}

void	move_right(t_data *data)
{
	if (data->map[(int)(data->player->x + (data->player->dir_y * SPEED_TEST))]
		[(int)data->player->y] != '1')
	{
		data->player->x += data->player->dir_y * SPEED_TEST;
		data->player->change = 1;
	}
	if (data->map[(int)data->player->x][(int)(data->player->y
		- (data->player->dir_x * SPEED_TEST))] != '1')
	{
		data->player->y -= data->player->dir_x * SPEED_TEST;
		data->player->change = 1;
	}
}

void	move_left(t_data *data)
{
	if (data->map[(int)(data->player->x - data->player->dir_y * SPEED_TEST)]
		[(int)data->player->y] != '1')
	{
		data->player->x -= data->player->dir_y * SPEED_TEST;
		data->player->change = 1;
	}
	if (data->map[(int)data->player->x][(int)(data->player->y
		+ data->player->dir_x * SPEED_TEST)] != '1')
	{
		data->player->y += data->player->dir_x * SPEED_TEST;
		data->player->change = 1;
	}
}

void	get_pos(t_data *data)
{
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

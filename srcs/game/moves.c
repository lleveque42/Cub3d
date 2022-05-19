/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:03:37 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/19 15:17:06 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_forward(t_data *data)
{
	if (data->map[(int)(data->player->y / 64)][(int)((data->player->x + data->player->dir_x * SPEED_TEST) / 64)] != '1')
	{
		data->player->x += data->player->dir_x * SPEED_TEST;
		data->player->change = 1;
	}
	if (data->map[(int)((data->player->y + data->player->dir_y + 1 * SPEED_TEST) / 64)][(int)(data->player->x / 64)] != '1')
	{
		data->player->y += data->player->dir_y * SPEED_TEST;
		data->player->change = 1;
	}

}

void	move_backward(t_data *data)
{

	if (data->map[(int)(data->player->y / 64)][(int)((data->player->x - data->player->dir_x * SPEED_TEST) / 64)] != '1')
	{
		data->player->x -= data->player->dir_x * SPEED_TEST;
		data->player->change = 1;
	}

	if (data->map[(int)((data->player->y - data->player->dir_y * SPEED_TEST) / 64)][(int)(data->player->x / 64)] != '1')
	{
		data->player->y -= data->player->dir_y * SPEED_TEST;
		data->player->change = 1;
	}
}

void	move_right(t_data *data)
{
	printf("right\n");
	printf("dir x %f\n", data->player->dir_x + (2 * PI) * 5);
	printf("dir y %f\n", data->player->dir_y + (2 * PI) * 5);
	data->player->x += (data->player->dir_x + (2 * PI) * 5) * SPEED_TEST;
	data->player->y += (data->player->dir_y + (2 * PI) * 5) * SPEED_TEST;
	data->player->change = 1;
}

void	move_left(t_data *data)
{
	printf("left\n");
	printf("dir x %f\n", data->player->dir_x - cos(2 * PI) * 5);
	printf("dir y %f\n", data->player->dir_y - cos(2 * PI) * 5);
	data->player->x += (data->player->dir_x - cos(2 * PI) * 5) * SPEED_TEST;
	data->player->y += (data->player->dir_y - cos(2 * PI) * 5) * SPEED_TEST;
	data->player->change = 1;
}

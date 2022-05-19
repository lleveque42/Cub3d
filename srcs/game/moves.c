/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:03:37 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/19 12:33:27 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_forward(t_data *data)
{
	printf("%d\n", (int)data->player->x);
	printf("%f\n", data->player->dir_x);
	printf("%d\n", (int)data->player->y);
	printf("%f\n", data->player->dir_y);
	if (data->map[(int)(data->player->y / 64)][(int)((data->player->x + data->player->dir_x + 1 * SPEED_TEST) / 64)] != '1' \
		&& data->map[(int)(data->player->y / 64)][(int)((data->player->x + data->player->dir_x - 1  * SPEED_TEST) / 64)] != '1')
	{
		data->player->x += data->player->dir_x * SPEED_TEST;
		data->player->change = 1;
	}
	// else if (data->map[(int)(data->player->y / 64)][(int)(data->player->x / 64)] == '1'
	// 		&& (((data->map[(int)(data->player->y / 64)][(int)((data->player->x + 1 + data->player->dir_x * SPEED_TEST) / 64)] != '1'))
	// 		|| ((data->map[(int)(data->player->y / 64)][(int)((data->player->x - 1 + data->player->dir_x * SPEED_TEST) / 64)] != '1'))))
	// {
	// 	data->player->x += data->player->dir_x * SPEED_TEST;
	// 	data->player->change = 1;
	// }
	if (data->map[(int)((data->player->y + data->player->dir_x + 1 * SPEED_TEST) / 64)][(int)(data->player->x / 64)] != '1'
		&& data->map[(int)((data->player->y + data->player->dir_x - 1 * SPEED_TEST) / 64)][(int)(data->player->x / 64)] != '1')
	{
		data->player->y += data->player->dir_y * SPEED_TEST;
		data->player->change = 1;
	}
	// else if (data->map[(int)(data->player->y / 64)][(int)(data->player->x / 64)] == '1'
	// 		&& ((data->map[(int)((data->player->y - 1 + data->player->dir_x * SPEED_TEST) / 64)][(int)(data->player->x / 64)] != '1')
	// 		|| data->map[(int)((data->player->y + 1 + data->player->dir_x * SPEED_TEST) / 64)][(int)(data->player->x / 64)] != '1'))
	// {
	// 	data->player->y += data->player->dir_y * SPEED_TEST;
	// 	data->player->change = 1;
	// }
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
	// (void)data;
	data->player->x += (data->player->dir_x + PI / 2) * SPEED_TEST;
	data->player->y += (data->player->dir_y + PI / 2) * SPEED_TEST;
}

void	move_left(t_data *data)
{
	(void)data;
	data->player->x += (data->player->dir_x - PI / 2) * SPEED_TEST;
	data->player->y += (data->player->dir_y - PI / 2) * SPEED_TEST;
}

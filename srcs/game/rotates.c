/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:06:08 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/19 11:14:11 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rotate_right(t_data *data)
{
	data->player->old_dx = data->player->dir_x;
	data->player->old_dy = data->player->dir_y;
	data->player->angle += ROTATE_SPEED_TEST;
	if (data->player->angle > 2 * PI)
		data->player->angle -= 2 * PI;
	data->player->dir_x = cos(data->player->angle) * 5;
	data->player->dir_y = sin(data->player->angle) * 5;
	data->player->change = 1;
}

void	rotate_left(t_data *data)
{
	data->player->old_dx = data->player->dir_x;
	data->player->old_dy = data->player->dir_y;
	data->player->angle -= ROTATE_SPEED_TEST;
	if (data->player->angle < 0)
		data->player->angle += 2 * PI;
	data->player->dir_x = cos(data->player->angle) * 5;
	data->player->dir_y = sin(data->player->angle) * 5;
	data->player->change = 1;
}

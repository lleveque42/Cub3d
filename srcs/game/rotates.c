/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:06:08 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/17 15:05:29 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rotate_right(t_data *data)
{
	data->player->old_dx = data->player->dx;
	data->player->old_dy = data->player->dy;
	data->player->angle += ROTATE_SPEED_TEST;
	if (data->player->angle > 2 * PI)
		data->player->angle -= 2 * PI;
	data->player->dx = cos(data->player->angle) * 5;
	data->player->dy = sin(data->player->angle) * 5;
}

void	rotate_left(t_data *data)
{
	data->player->old_dx = data->player->dx;
	data->player->old_dy = data->player->dy;
	data->player->angle -= ROTATE_SPEED_TEST;
	if (data->player->angle < 0)
		data->player->angle += 2 * PI;
	data->player->dx = cos(data->player->angle) * 5;
	data->player->dy = sin(data->player->angle) * 5;
}

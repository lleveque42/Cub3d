/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:06:08 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/24 15:19:39 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rotate_right(t_data *data)
{
	double	old_plane_x;

	old_plane_x = data->ray->plane_x;
	data->player->old_dx = data->player->dir_x;
	data->player->old_dy = data->player->dir_y;
	data->player->dir_x = data->player->dir_x * cos(ROT_SPEED) - data->player->dir_y * sin(ROT_SPEED);
	data->player->dir_y = data->player->old_dx * sin(ROT_SPEED) + data->player->dir_y * cos(ROT_SPEED);
	data->ray->plane_x = data->ray->plane_x * cos(ROT_SPEED) - data->ray->plane_y * sin(ROT_SPEED);
	data->ray->plane_y = old_plane_x * sin(ROT_SPEED) + data->ray->plane_y * cos(ROT_SPEED);
	data->player->change = 1;
}

void	rotate_left(t_data *data)
{
	double	old_plane_x;

	old_plane_x = data->ray->plane_x;
	data->player->old_dx = data->player->dir_x;
	data->player->old_dy = data->player->dir_y;
	data->player->dir_x = data->player->dir_x * cos(-ROT_SPEED) - data->player->dir_y * sin(-ROT_SPEED);
	data->player->dir_y = data->player->old_dx * sin(-ROT_SPEED) + data->player->dir_y * cos(-ROT_SPEED);
	data->ray->plane_x = data->ray->plane_x * cos(-ROT_SPEED) - data->ray->plane_y * sin(-ROT_SPEED);
	data->ray->plane_y = old_plane_x * sin(-ROT_SPEED) + data->ray->plane_y * cos(-ROT_SPEED);
	data->player->change = 1;
}

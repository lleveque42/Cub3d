/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:26:54 by arudy             #+#    #+#             */
/*   Updated: 2022/05/25 14:53:14 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// Calculate ray pos & dir
void	ray_dir(t_data *data, int x)
{
	data->ray->camera_x = 2 * (float)x / (float)SCREEN_W - 1;
	data->ray->dir_x = data->player->dir_x + data->ray->plane_x \
		* data->ray->camera_x;
	data->ray->dir_y = data->player->dir_y + data->ray->plane_y \
		* data->ray->camera_x;
	data->ray->map_x = (int)data->player->x;
	data->ray->map_y = (int)data->player->y;
}

// Calculate side dist
void	calc_delta(t_data *data)
{
	if (data->ray->dir_x == 0)
		data->ray->ddx = 1e30;
	else
		data->ray->ddx = sqrt(1 + (data->ray->dir_y * data->ray->dir_y) \
		/ (data->ray->dir_x * data->ray->dir_x));
	if (data->ray->dir_y == 0)
		data->ray->ddy = 1e30;
	else
		data->ray->ddy = sqrt(1 + (data->ray->dir_x * data->ray->dir_x) \
		/ (data->ray->dir_y * data->ray->dir_y));
}

// Calculate step & side dist
void	calc_steps(t_data *data)
{
	calc_delta(data);
	if (data->ray->dir_x < 0)
	{
		data->ray->step_x = -1;
		data->ray->sdx = (data->player->x - data->ray->map_x) * data->ray->ddx;
	}
	else
	{
		data->ray->step_x = 1;
		data->ray->sdx = (data->ray->map_x + 1.0 - data->player->x) \
		* data->ray->ddx;
	}
	if (data->ray->dir_y < 0)
	{
		data->ray->step_y = -1;
		data->ray->sdy = (data->player->y - data->ray->map_y) * data->ray->ddy;
	}
	else
	{
		data->ray->step_y = 1;
		data->ray->sdy = (data->ray->map_y + 1.0 - data->player->y) \
		* data->ray->ddy;
	}
}

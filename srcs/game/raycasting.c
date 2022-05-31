/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:26:54 by arudy             #+#    #+#             */
/*   Updated: 2022/05/31 14:21:14 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// Calculate ray pos & dir
void	ray_dir(t_data *data, int x)
{
	data->ray->camera_x = 2 * x / (float)SCREEN_W - 1;
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
	if (data->ray->dir_y == 0)
		data->ray->ddx = 0;
	else if (data->ray->dir_x == 0)
		data->ray->ddx = 1;
	else
		data->ray->ddx = sqrt(1 + (data->ray->dir_y * data->ray->dir_y) \
		/ (data->ray->dir_x * data->ray->dir_x));
	if (data->ray->dir_x == 0)
		data->ray->ddy = 0;
	else if (data->ray->dir_y == 0)
		data->ray->ddy = 1;
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

// Perform the algo to check when & where a ray hit a wall
void	ray_hit_wall_pos(t_data *data)
{
	data->ray->hit = 0;
	while (data->ray->hit == 0)
	{
		if (data->ray->sdx < data->ray->sdy)
		{
			data->ray->sdx += data->ray->ddx;
			data->ray->map_x += data->ray->step_x;
			data->ray->side = 0;
		}
		else
		{
			data->ray->sdy += data->ray->ddy;
			data->ray->map_y += data->ray->step_y;
			data->ray->side = 1;
		}
		if (data->map[data->ray->map_x][data->ray->map_y] == '1')
			data->ray->hit = 1;
	}
}

// Calculate dist on cam direction, (sort of avoid fisheye effect)
// Calculate height of the line to draw & and coord of pixels to fill
void	calc_line_height(t_data *data)
{
	if (data->ray->side == 0)
		data->ray->pwd = ((float)data->ray->map_x - data->player->x \
		+ (1 - (float)data->ray->step_x) / 2) / data->ray->dir_x;
	else
		data->ray->pwd = ((float)data->ray->map_y - data->player->y \
		+ (1 - (float)data->ray->step_y) / 2) / data->ray->dir_y;
	data->ray->line_h = (int)(SCREEN_H / data->ray->pwd);
	data->ray->draw_start = -data->ray->line_h / 2 + SCREEN_H / 2;
	if (data->ray->draw_start < 0)
		data->ray->draw_start = 0;
	data->ray->draw_end = data->ray->line_h / 2 + SCREEN_H / 2;
	if (data->ray->draw_end >= SCREEN_H || data->ray->draw_end < 0)
		data->ray->draw_end = SCREEN_H - 1;
}

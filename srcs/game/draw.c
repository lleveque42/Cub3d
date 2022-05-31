/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:22:58 by arudy             #+#    #+#             */
/*   Updated: 2022/05/31 14:25:48 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_ceiling(t_data *data, int x)
{
	int	y;

	y = 0;
	while (y < data->ray->draw_start - 1)
	{
		data->mlx->addr[y * SCREEN_W + x] = data->c_color;
		y++;
	}
}

void	draw_texture(t_data *data, int x)
{
	int	y;

	y = data->ray->draw_start - 1;
	while (++y <= data->ray->draw_end)
	{
		data->ray->text_y = (int)data->ray->text_pos
			& (data->texture[data->ray->text_num].h - 1);
		data->ray->text_pos += data->ray->step;
		if (y < SCREEN_H && x < SCREEN_W)
		{
			data->mlx->addr[y * SCREEN_W + x]
				= data->texture[data->ray->text_num].addr[data->ray->text_y
				* data->texture[data->ray->text_num].w + data->ray->text_x];
		}
	}
}

void	draw_floor(t_data *data, int x)
{
	int	y;

	y = data->ray->draw_end + 1;
	while (y < SCREEN_H)
	{
		data->mlx->addr[y * SCREEN_W + x] = data->f_color;
		y++;
	}
}

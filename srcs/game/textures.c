/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:08:01 by arudy             #+#    #+#             */
/*   Updated: 2022/05/30 16:24:26 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_texture_data(t_data *data, int n)
{
	if (data->ray->side == 0)
		data->ray->wall_x = data->player->y + data->ray->pwd \
			* data->ray->dir_y;
	else
		data->ray->wall_x = data->player->x + data->ray->pwd \
			* data->ray->dir_x;
	data->ray->wall_x -= floor((data->ray->wall_x));
	data->ray->text_x = (int)(data->ray->wall_x * (float)data->texture[n].w);
	// if (data->ray->side == 0 && data->ray->dir_x > 0)
		//  data->ray->text_x = data->texture[n].w - data->ray->text_x - 1;
	// if (data->ray->side == 1 && data->ray->dir_y < 0)
		//  data->ray->text_x = data->texture[n].w - data->ray->text_x - 1;
	data->ray->step = 1.0 * (float)data->texture[n].h / data->ray->line_h;
	data->ray->text_pos = (data->ray->draw_start - SCREEN_H / 2 +
			data->ray->line_h / 2) *  data->ray->step;
}

void	find_texture_orientation(t_data *data)
{
	if (data->ray->side)
	{
		if (data->ray->dir_y < 0)
			data->ray->text_num = 0;
		else
			data->ray->text_num = 1;
	}
	else
	{
		if (data->ray->dir_x < 0)
			data->ray->text_num = 3;
		else
			data->ray->text_num = 2;
	}
}

void	get_color(t_data *data, int x)
{
	int	side;
	(void)x;
	find_texture_orientation(data);
	side = data->ray->text_num;
	if (side == 0)
		get_texture_data(data, 0);
	else if (side == 1)
		get_texture_data(data, 1);
	else if (side == 2)
		get_texture_data(data, 2);
	else
		get_texture_data(data, 3);
}

void	get_textures(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (++i < 4)
	{
		data->texture[i].img = mlx_xpm_file_to_image(data->mlx->ptr, \
		data->texture[i].path, &data->texture[i].w, &data->texture[i].h);
		if (!data->texture[i].img)
			ft_exit_message("XPM image reading has failed", data, 1);
		data->texture[i].addr = (char *)mlx_get_data_addr \
			(data->texture[i].img, &data->texture[i].bpp, \
			&data->texture[i].line_length, &data->texture[i].endian);
		y = -1;
		while (++y < data->texture[i].h)
		{
			x = -1;
			while (++x < data->texture[i].w)
				data->texture[i].addr[data->texture[i].w * y + x] = (char)RED;
		}
		// mlx_destroy_image(data->mlx->ptr, data->texture[i].img);
	}
}

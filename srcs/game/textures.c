/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:08:01 by arudy             #+#    #+#             */
/*   Updated: 2022/05/31 15:05:01 by arudy            ###   ########.fr       */
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
	if (data->ray->side == 0 && data->ray->dir_x > 0)
		data->ray->text_x = data->texture[n].w - data->ray->text_x - 1;
	if (data->ray->side == 1 && data->ray->dir_y < 0)
		data->ray->text_x = data->texture[n].w - data->ray->text_x - 1;
	data->ray->step = 1.0 * (float)data->texture[n].h / data->ray->line_h;
	data->ray->text_pos = (data->ray->draw_start - SCREEN_H / 2
			+ data->ray->line_h / 2) * data->ray->step;
}

void	get_color(t_data *data)
{
	if (data->ray->side)
	{
		if (data->ray->dir_y < 0)
			data->ray->text_num = 2;
		else
			data->ray->text_num = 3;
	}
	else
	{
		if (data->ray->dir_x < 0)
			data->ray->text_num = 0;
		else
			data->ray->text_num = 1;
	}
	get_texture_data(data, data->ray->text_num);
}

void	get_textures(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		data->texture[i].img = mlx_xpm_file_to_image(data->mlx->ptr, \
		data->texture[i].path, &data->texture[i].w, &data->texture[i].h);
		if (!data->texture[i].img)
			ft_exit(data, "XPM image reading has failed", 1);
		data->texture[i].addr = (int *)mlx_get_data_addr \
			(data->texture[i].img, &data->texture[i].bpp, \
			&data->texture[i].line_length, &data->texture[i].endian);
		if (!data->texture[i].addr)
			ft_exit(data, "XPM address reading has failed", 1);
	}
}

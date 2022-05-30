/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:08:01 by arudy             #+#    #+#             */
/*   Updated: 2022/05/30 10:57:47 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_texture_data(t_data *data, int x, int n)
{
	int	y;
	char *dst;

	if (data->ray->side == 0)
		data->ray->wall_x = data->player->y + data->ray->pwd \
			* data->ray->dir_y;
	else
		data->ray->wall_x = data->player->x + data->ray->pwd \
			* data->ray->dir_x;
	data->ray->wall_x -= floor(data->ray->wall_x);
	 data->texture[n].text_x = (int)(data->ray->wall_x * (float)data->texture[n].w);
	if (data->ray->side == 0 && data->ray->dir_x > 0)
		 data->texture[n].text_x = data->texture[n].w -  data->texture[n].text_x - 1;
	if (data->ray->side == 1 && data->ray->dir_y < 0)
		 data->texture[n].text_x = data->texture[n].w -  data->texture[n].text_x - 1;
	 data->texture[n].step = (float)data->texture[n].h / data->ray->line_h;
	 data->texture[n].text_pos = (data->ray->draw_start - SCREEN_H / 2 +
			data->ray->line_h / 2) *  data->texture[n].step;
	y = data->ray->draw_start - 1;
	while (++y <= data->ray->draw_end)
	{
		 data->texture[n].text_y = (int) data->texture[n].text_pos &
			(data->texture[n].h - 1);
		data->texture[n].text_pos +=  data->texture[n].step;
		dst = data->mlx->addr + (y * data->mlx->line_length)
			+ (x * data->mlx->bpp / 8);
		*(unsigned int *)dst = data->texture[n].addr[data->texture[n].text_y *
					data->texture[n].line_length +  data->texture[n].text_x * data->mlx->bpp / 8];
	}
	return (y);
}

int	find_texture_orientation(t_data *data)
{
	int side;

	side = 0;
	if (data->ray->side == 0)
	{
		if (data->ray->dir_x < 0)
			side = 4;
		else
			side = 3;
	}
	else
	{
		if (data->ray->dir_y < 0)
			side = 1;
		else
			side = 2;
	}
	return (side);
}

int	get_color(t_data *data, int x)
{
	int	side;

	side = find_texture_orientation(data);
	if (side == 1)
		return (get_texture_data(data, x, 0));
	else if (side == 2)
		return (get_texture_data(data, x, 1));
	else if (side == 3)
		return (get_texture_data(data, x, 2));
	else
		return (get_texture_data(data, x, 3));
	return (0);
}

void	get_texture_addr(t_data *data)
{
	data->texture[0].addr = (char *)mlx_get_data_addr \
		(data->texture[0].img, &data->texture[0].bpp, \
		&data->texture[0].line_length, &data->texture[0].endian);
	data->texture[1].addr = (char *)mlx_get_data_addr \
		(data->texture[1].img, &data->texture[1].bpp, \
		&data->texture[1].line_length, &data->texture[1].endian);
	data->texture[2].addr = (char *)mlx_get_data_addr \
		(data->texture[2].img, &data->texture[2].bpp, \
		&data->texture[2].line_length, &data->texture[2].endian);
	data->texture[3].addr = (char *)mlx_get_data_addr \
		(data->texture[3].img, &data->texture[3].bpp, \
		&data->texture[3].line_length, &data->texture[3].endian);
}

void	get_textures(t_data *data)
{
	data->texture[0].img = mlx_xpm_file_to_image(data->mlx->ptr, \
		data->texture[0].path, &data->texture[0].w, &data->texture[0].h);
	if (!data->texture[0].img)
		ft_exit_message("XPM NO image reading has failed", data, 1);
	data->texture[1].img = mlx_xpm_file_to_image(data->mlx->ptr, \
		data->texture[1].path, &data->texture[1].w, &data->texture[1].h);
	if (!data->texture[1].img)
		ft_exit_message("XPM SO image reading has failed", data, 1);
	data->texture[2].img = mlx_xpm_file_to_image(data->mlx->ptr, \
		data->texture[2].path, &data->texture[2].w, &data->texture[2].h);
	if (!data->texture[2].img)
		ft_exit_message("XPM EA image reading has failed", data, 1);
	data->texture[3].img = mlx_xpm_file_to_image(data->mlx->ptr, \
		data->texture[3].path, &data->texture[3].w, &data->texture[3].h);
	if (!data->texture[3].img)
		ft_exit_message("XPM WE image reading has failed", data, 1);
	get_texture_addr(data);
}

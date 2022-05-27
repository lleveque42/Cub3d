/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:08:01 by arudy             #+#    #+#             */
/*   Updated: 2022/05/27 16:02:38 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_texture_data(t_data *data, t_data_texture *texture, int x)
{
	int	y;
	// char *dst;
	// unsigned int	color;
	// unsigned int	*addr_int;

	if (data->ray->side == 0)
		data->ray->wall_x = data->player->y + data->ray->pwd \
			* data->ray->dir_y;
	else
		data->ray->wall_x = data->player->x + data->ray->pwd \
			* data->ray->dir_x;
	data->ray->wall_x -= floor(data->ray->wall_x);
	data->texture->text_x = (int)(data->ray->wall_x * (float)texture->w);
	if (data->ray->side == 0 && data->ray->dir_x > 0)
		data->texture->text_x = texture->w - data->texture->text_x - 1;
	if (data->ray->side == 1 && data->ray->dir_y < 0)
		data->texture->text_x = texture->w - data->texture->text_x - 1;
	data->texture->step = (float)texture->h / data->ray->line_h;
	data->texture->text_pos = (data->ray->draw_start - SCREEN_H / 2 +
			data->ray->line_h / 2) * data->texture->step;
	y = data->ray->draw_start - 1;
	while (++y <= data->ray->draw_end)
	{
		data->texture->text_y = (int)data->texture->text_pos &
			(texture->h - 1);
		data->texture->text_pos += data->texture->step;
		// dst = data->mlx->addr + (y * data->mlx->line_length)
		// 	+ (x * data->mlx->bpp / 8);
		// *(unsigned int *)dst = texture->addr[data->texture->text_x *
		// 			texture->line_length + data->texture->text_y * data->mlx->bpp / 8];
		// addr_int = (unsigned int *)texture->addr;
		// color = *(addr_int + ((data->texture->text_y * texture->h) / texture->w) * (texture->line_length / 4) + ((x * texture->w) / texture->w));
		// dst = data->mlx->addr + (((data->texture->text_y * texture->h) / texture->w) * data->mlx->line_length + ((x * texture->w) / texture->w) * (data->mlx->bpp / 8));
		// *(int *)dst = color;
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
		return (get_texture_data(data, data->texture->no, x));
	else if (side == 2)
		return (get_texture_data(data, data->texture->so, x));
	else if (side == 3)
		return (get_texture_data(data, data->texture->ea, x));
	else
		return (get_texture_data(data, data->texture->we, x));
	return (0);
}

void	get_texture_addr(t_data *data)
{
	data->texture->no->addr = (char *)mlx_get_data_addr \
		(data->texture->no->img, &data->texture->no->bpp, \
		&data->texture->no->line_length, &data->texture->no->endian);
	data->texture->so->addr = (char *)mlx_get_data_addr \
		(data->texture->so->img, &data->texture->so->bpp, \
		&data->texture->so->line_length, &data->texture->so->endian);
	data->texture->ea->addr = (char *)mlx_get_data_addr \
		(data->texture->ea->img, &data->texture->ea->bpp, \
		&data->texture->ea->line_length, &data->texture->ea->endian);
	data->texture->we->addr = (char *)mlx_get_data_addr \
		(data->texture->we->img, &data->texture->we->bpp, \
		&data->texture->we->line_length, &data->texture->we->endian);
}

void	get_textures(t_data *data)
{
	data->texture->no->img = mlx_xpm_file_to_image(data->mlx->ptr, \
		data->texture->no->path, &data->texture->no->w, &data->texture->no->h);
	if (!data->texture->no->img)
		ft_exit_message("XPM NO image reading has failed", data, 1);
	data->texture->so->img = mlx_xpm_file_to_image(data->mlx->ptr, \
		data->texture->so->path, &data->texture->so->w, &data->texture->so->h);
	if (!data->texture->so->img)
		ft_exit_message("XPM SO image reading has failed", data, 1);
	data->texture->ea->img = mlx_xpm_file_to_image(data->mlx->ptr, \
		data->texture->ea->path, &data->texture->ea->w, &data->texture->ea->h);
	if (!data->texture->ea->img)
		ft_exit_message("XPM EA image reading has failed", data, 1);
	data->texture->we->img = mlx_xpm_file_to_image(data->mlx->ptr, \
		data->texture->we->path, &data->texture->we->w, &data->texture->we->h);
	if (!data->texture->we->img)
		ft_exit_message("XPM WE image reading has failed", data, 1);
	get_texture_addr(data);
}

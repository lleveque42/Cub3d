/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:02:26 by arudy             #+#    #+#             */
/*   Updated: 2022/05/17 13:34:17 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	render_minimap(t_data *data)
{
	int		x = 0;
	int		y = 0;
	int		i = 0;
	int		j = 0;

	while (data->map[y])
	{
		x = 0;
		i = 0;
		while (data->map[y][x])
		{
			i += 2;
			if (data->map[y][x] != '1' && data->map[y][x] != ' ')
			{
				while (i < (x + 1) * 100)
				{
					j = y * 100 + 1;
					while (j < (y + 1) * 100 - 1)
					{
						*(unsigned int*)(data->mlx->addr + (j * data->mlx->line_length + i * (data->mlx->bpp / 8))) = 0x00FFFFFF;
						j++;
					}
					i++;
				}
			}
			else if (data->map[y][x] == '1')
			{
				while (i < (x + 1) * 100)
				{
					j = y * 100 + 1;
					while (j < (y + 1) * 100 - 1)
					{
						*(unsigned int*)(data->mlx->addr + (j * data->mlx->line_length + i * (data->mlx->bpp / 8))) = 0x007F7F7F;
						j++;
					}
					i++;
				}
			}
			else
			{
				i += 98;
				j += 99;
			}
			x++;
		}
		y++;
	}
}

void	render_player(t_data *data)
{
	int	x;
	int	y;
	int	i;

	x = (data->player->old_x * 100) - 5;
	y = (data->player->old_y * 100) - 5;
	while (x < (data->player->old_x * 100) + 5)
	{
		y = (data->player->old_y * 100) - 5;
		while (y < (data->player->old_y * 100) + 5)
		{
			*(unsigned int*)(data->mlx->addr + (y * data->mlx->line_length + x * (data->mlx->bpp / 8))) = 0x00FFFFFF;
			y++;
		}
		x++;
	}
	x = (data->player->x * 100) - 5;
	y = (data->player->y * 100) - 5;
	while (x < (data->player->x * 100) + 5)
	{
		y = (data->player->y * 100);
		while (y < (data->player->y * 100) + 5)
		{
			*(unsigned int*)(data->mlx->addr + (y * data->mlx->line_length + x * (data->mlx->bpp / 8))) = 0x00000000;
			y++;
		}
		x++;
	}
	x = (data->player->old_x * 100) - 3;
	y = (data->player->old_y * 100);
	while (x < (data->player->old_x * 100) + 3)
	{
		i = -1;
		while (++i < 20)
			*(unsigned int*)(data->mlx->addr + ((y + (int)data->player->old_dy * i) * data->mlx->line_length + (x + (int)data->player->old_dx * i) * (data->mlx->bpp / 8))) = 0x00FFFFFF;
		x++;
	}
	x = (data->player->x * 100) - 3;
	y = (data->player->y * 100);
	while (x < (data->player->x * 100) + 3)
	{
		i = -1;
		while (++i < 20)
			*(unsigned int*)(data->mlx->addr + ((y + (int)data->player->dy * i) * data->mlx->line_length + (x + (int)data->player->dx * i) * (data->mlx->bpp / 8))) = 0x00000000;
		x++;
	}
}

void	render_ray(t_data *data)
{
	int	x;
	int	y;
	int	i;
	float	a_tan;

	data->ray->angle = data->player->angle;
	data->ray->r = 0;
	while (data->ray->r < 1)
	{
		// check horizontal
		data->ray->dof = 0;
		a_tan = -1 / tan(data->ray->angle);
		if (data->ray->angle < PI) // looking down
		{
			data->ray->y = (((int)data->player->y >> 6) << 6) - 0.0001;
			data->ray->x = (data->player->y - data->ray->y) * a_tan + data->player->x;
			data->ray->yo = -64;
			data->ray->xo = -data->ray->yo * a_tan;
		}
		if (data->ray->angle > PI) // looking up
		{
			data->ray->y = (((int)data->player->y >> 6) << 6) + 64;
			data->ray->x = (data->player->y - data->ray->y) * a_tan + data->player->x;
			data->ray->yo = 64;
			data->ray->xo = -data->ray->yo * a_tan;
		}
		if (data->ray->angle == 0 || data->ray->angle == PI) // looking left or right
		{
			data->ray->x = data->player->x;
			data->ray->y = data->player->y;
			data->ray->dof = 8;
		}
		while (data->ray->dof < 8)
		{
			data->ray->mx = (int)(data->player->x) >> 6;
			data->ray->my = (int)(data->player->y) >> 6;
			printf("mx %d || my %d\n", data->ray->mx, data->ray->my);
			printf("mx %d\n", data->map_fd->width);
			data->ray->mp = data->ray->my * data->map_fd->width + data->ray->mx;
			printf("mp %d\n", data->ray->mp);
			if (data->map[data->ray->my][data->ray->mx] == '1')
				data->ray->dof = 8;
			else
			{
				data->ray->x += data->ray->xo;
				data->ray->y += data->ray->yo;
				data->ray->dof += 1;
			}
			printf("data->map[data->ray->my][data->ray->mx] = %c\n", data->map[data->ray->my][data->ray->mx]);
		}
		x = (data->player->x * 100) - 3;
		y = (data->player->y * 100);
		while (x < (data->player->x * 100) + 3)
		{
			i = -1;
			while (++i < 20)
				*(unsigned int*)(data->mlx->addr + ((y + (int)data->ray->y * i) * data->mlx->line_length + (x + (int)data->ray->x * i) * (data->mlx->bpp / 8))) = 0x00000000;
			printf("yolo2 \n");
			x++;
		}
		data->ray->r++;
	}
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == 119)
		data->key->w_pressed = 0;
	if (keycode == 115)
		data->key->s_pressed = 0;
	if (keycode == 97)
		data->key->a_pressed = 0;
	if (keycode == 100)
		data->key->d_pressed = 0;
	if (keycode == 65363)
		data->key->lr_pressed = 0;
	if (keycode == 65361)
		data->key->la_pressed = 0;
	return (0);
}

int	key_event(int keycode, t_data *data)
{
	if (keycode == 119)
		data->key->w_pressed = 1;
	if (keycode == 115)
		data->key->s_pressed = 1;
	if (keycode == 97)
		data->key->a_pressed = 1;
	if (keycode == 100)
		data->key->d_pressed = 1;
	if (keycode == 65363)
		data->key->lr_pressed = 1;
	if (keycode == 65361)
		data->key->la_pressed = 1;
	if (keycode == 65307)
		ft_exit_esc(data);
	return (0);
}

void	get_pos(t_data *data)
{
	data->player->old_y = data->player->y;
	data->player->old_x = data->player->x;
	if (data->key->w_pressed == 1)
		move_forward(data);
	if (data->key->s_pressed == 1)
		move_backward(data);
	if (data->key->a_pressed == 1)
		move_left(data);
	if (data->key->d_pressed == 1)
		move_right(data);
	if (data->key->la_pressed == 1)
		rotate_left(data);
	if (data->key->lr_pressed == 1)
		rotate_right(data);
}

int	render_image(t_data *data)
{
	get_pos(data);
	// render_minimap(data);
	render_player(data);
	render_ray(data);
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->mlx->img, 0, 0);
	return (0);
}

void	game(t_data *data)
{
	data->mlx->ptr = mlx_init();
	if (!data->mlx->ptr)
		ft_exit(data, "Can't init mlx ptr");
	data->mlx->win = mlx_new_window(data->mlx->ptr, data->map_fd->width * 100, data->map_fd->height * 100, "QubtroiD");
	if (!data->mlx->win)
		ft_exit(data, "Can't init mlx window");
	data->mlx->img = mlx_new_image(data->mlx->ptr, data->map_fd->width * 100, data->map_fd->height * 100);
	if (!data->mlx->img)
		ft_exit(data, "Can't init mlx image");
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, &data->mlx->bpp,
					&data->mlx->line_length, &data->mlx->endian);
	if (!data->mlx->addr)
		ft_exit(data, "Can't init mlx addr");
	render_minimap(data);
	data->mlx->addr_map = ft_strdup(data->mlx->addr, data);
	render_player(data);
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->mlx->img, 0, 0);
	mlx_hook(data->mlx->win, 2, 1, &key_event, data);
	mlx_loop_hook(data->mlx->ptr, &render_image, data);
	mlx_hook(data->mlx->win, 17, 17, &ft_exit_esc, data);
	mlx_hook(data->mlx->win, 3, 10, &key_release, data);
	mlx_loop(data->mlx->ptr);
}

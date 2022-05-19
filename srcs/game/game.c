/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:02:26 by arudy             #+#    #+#             */
/*   Updated: 2022/05/19 14:16:01 by lleveque         ###   ########.fr       */
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
				while (i < (x + 1) * 64)
				{
					j = y * 64 + 1;
					while (j < (y + 1) * 64 - 1)
					{
						data->mlx->addr[(j * data->mlx->line_length) + (i * data->mlx->bpp / 8) + 0] = (WHITE) & 0xFF;
						data->mlx->addr[(j * data->mlx->line_length) + (i * data->mlx->bpp / 8) + 1] = (WHITE >> 8) & 0xFF;
						data->mlx->addr[(j * data->mlx->line_length) + (i * data->mlx->bpp / 8) + 2] = (WHITE >> 16) & 0xFF;
						data->mlx->addr[(j * data->mlx->line_length) + (i * data->mlx->bpp / 8) + 3] = (WHITE >> 24) & 0xFF;
						j++;
					}
					i++;
				}
			}
			else if (data->map[y][x] == '1')
			{
				while (i < (x + 1) * 64)
				{
					j = y * 64 + 1;
					while (j < (y + 1) * 64 - 1)
					{
						data->mlx->addr[(j * data->mlx->line_length) + (i * data->mlx->bpp / 8) + 0] = (GREY) & 0xFF;
						data->mlx->addr[(j * data->mlx->line_length) + (i * data->mlx->bpp / 8) + 1] = (GREY >> 8) & 0xFF;
						data->mlx->addr[(j * data->mlx->line_length) + (i * data->mlx->bpp / 8) + 2] = (GREY >> 16) & 0xFF;
						data->mlx->addr[(j * data->mlx->line_length) + (i * data->mlx->bpp / 8) + 3] = (GREY >> 24) & 0xFF;
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

	(void)i;
	x = data->player->old_x - 5;
	y = data->player->old_y - 5;
	while (x < data->player->old_x + 5)
	{
		y = data->player->old_y - 5;
		while (y < data->player->old_y + 5)
		{

			data->mlx->addr[(y * data->mlx->line_length) + (x * data->mlx->bpp / 8) + 0] = (WHITE) & 0xFF;
			data->mlx->addr[(y * data->mlx->line_length) + (x * data->mlx->bpp / 8) + 1] = (WHITE >> 8) & 0xFF;
			data->mlx->addr[(y * data->mlx->line_length) + (x * data->mlx->bpp / 8) + 2] = (WHITE >> 16) & 0xFF;
			data->mlx->addr[(y * data->mlx->line_length) + (x * data->mlx->bpp / 8) + 3] = (WHITE >> 24) & 0xFF;
			y++;
		}
		x++;
	}
	x = data->player->x - 5;
	y = data->player->y- 5;
	while (x < data->player->x + 5)
	{
		y = data->player->y- 5;
		while (y < data->player->y + 5)
		{
			data->mlx->addr[(y * data->mlx->line_length) + (x * data->mlx->bpp / 8) + 0] = (RED) & 0xFF;
			data->mlx->addr[(y * data->mlx->line_length) + (x * data->mlx->bpp / 8) + 1] = (RED >> 8) & 0xFF;
			data->mlx->addr[(y * data->mlx->line_length) + (x * data->mlx->bpp / 8) + 2] = (RED >> 16) & 0xFF;
			data->mlx->addr[(y * data->mlx->line_length) + (x * data->mlx->bpp / 8) + 3] = (RED >> 24) & 0xFF;
			y++;
		}
		x++;
	}
	x = data->player->old_x;
	y = data->player->old_y;
	i = -1;
	while (++i < 80)
	{
		data->mlx->addr[(((y + (int)data->player->old_dy * i / 5) * data->mlx->line_length) + (x + (int)data->player->old_dx * i / 5) * data->mlx->bpp / 8) + 0] = (WHITE) & 0xFF;
		data->mlx->addr[(((y + (int)data->player->old_dy * i / 5) * data->mlx->line_length) + (x + (int)data->player->old_dx * i / 5) * data->mlx->bpp / 8) + 1] = (WHITE >> 8) & 0xFF;
		data->mlx->addr[(((y + (int)data->player->old_dy * i / 5) * data->mlx->line_length) + (x + (int)data->player->old_dx * i / 5) * data->mlx->bpp / 8) + 2] = (WHITE >> 16) & 0xFF;
		data->mlx->addr[(((y + (int)data->player->old_dy * i / 5) * data->mlx->line_length) + (x + (int)data->player->old_dx * i / 5) * data->mlx->bpp / 8) + 3] = (WHITE >> 24) & 0xFF;
	}
	x = data->player->x;
	y = data->player->y;
	i = -1;
	while (++i < 80)
	{
		data->mlx->addr[(((y + (int)data->player->dir_y * i / 5) * data->mlx->line_length) + (x + (int)data->player->dir_x * i / 5) * data->mlx->bpp / 8) + 0] = (RED) & 0xFF;
		data->mlx->addr[(((y + (int)data->player->dir_y * i / 5) * data->mlx->line_length) + (x + (int)data->player->dir_x * i / 5) * data->mlx->bpp / 8) + 1] = (RED >> 8) & 0xFF;
		data->mlx->addr[(((y + (int)data->player->dir_y * i / 5) * data->mlx->line_length) + (x + (int)data->player->dir_x * i / 5) * data->mlx->bpp / 8) + 2] = (RED >> 16) & 0xFF;
		data->mlx->addr[(((y + (int)data->player->dir_y * i / 5) * data->mlx->line_length) + (x + (int)data->player->dir_x * i / 5) * data->mlx->bpp / 8) + 3] = (RED >> 24) & 0xFF;
	}
}

void	render_ray(t_data *data)
{
	int	x;

	x = 0;
	while (x < 1)
	{
		data->ray->camera_x = 2 * (float)x / (float)data->win_width - 1;
		data->ray->dir_x = data->player->dir_x + data->ray->plane_x * data->ray->camera_x;
		data->ray->dir_y = data->player->dir_y + data->ray->plane_y * data->ray->camera_x;
		// printf("render rayy calcul %f\n", data->player->dir_y + data->ray->plane_x * data->ray->camera_x);
		data->ray->map_x = (int)data->player->x;
		data->ray->map_y = (int)data->player->y;
		if ((int)data->ray->dir_x == 0)
			data->ray->ddx = 1;
		else
			data->ray->ddx = abs(1 / (int)data->ray->dir_x);
		if ((int)data->ray->dir_y == 0)
			data->ray->ddy = 1;
		else
			data->ray->ddy = abs(1 / (int)data->ray->dir_y);
		data->ray->hit = 0;
		if (data->ray->dir_x < 0)
		{
			data->ray->step_x = -1;
			data->ray->sdx = (data->player->x - data->ray->map_x) * data->ray->ddx;
		}
		else
		{
			data->ray->step_x = 1;
			data->ray->sdx = (data->ray->map_x + 1.0 - data->player->x) * data->ray->ddx;
		}
		if (data->ray->dir_y < 0)
		{
			data->ray->step_y = -1;
			data->ray->sdy = (data->player->y - data->ray->map_y) * data->ray->ddy;
		}
		else
		{
			data->ray->step_y = 1;
			data->ray->sdy = (data->ray->map_y + 1.0 - data->player->y) * data->ray->ddy;
		}
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
			if (data->map[data->ray->map_y / 64][data->ray->map_x / 64] == '1')
			{
				data->ray->hit = 1;
				// printf("HIT\n");
				// printf("ddx %f\n", data->ray->ddx);
				// printf("ddy %f\n", data->ray->ddy);
				// printf("sdx %f\n", data->ray->sdx);
				// printf("sdy %f\n", data->ray->sdy);
			}
		}
		x++;
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
	if (data->player->change)
	{
		render_player(data);
		render_ray(data);
		mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->mlx->img, 0, 0);
	}
	data->player->change = 0;
	return (0);
}

char	*create_m(char *s, t_data *data)
{
	int	 i = 1;

	s = ft_strdup(data->map[0], data);
	// s = ft_strjoin(s, "\n", data);
	while (data->map[i])
	{
		s = ft_strjoin(s, ft_strdup(data->map[i], data), data);
		// if (data->map[i + 1] != NULL)
			// s = ft_strjoin(s, "\n", data);
		i++;
	}
	return (s);
}

void	game(t_data *data)
{
	data->m = create_m(data->m, data);

	// printf("end of create m\n");
	data->win_height = data->map_fd->height * 64;
	data->win_width = data->map_fd->width * 64;
	data->mlx->ptr = mlx_init();
	if (!data->mlx->ptr)
		ft_exit(data, "Can't init mlx ptr");
	data->mlx->win = mlx_new_window(data->mlx->ptr, data->win_width, data->win_height, "QubtroiD");
	if (!data->mlx->win)
		ft_exit(data, "Can't init mlx window");
	data->mlx->img = mlx_new_image(data->mlx->ptr, data->map_fd->width * 64, data->map_fd->height * 64);
	if (!data->mlx->img)
		ft_exit(data, "Can't init mlx image");
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, &data->mlx->bpp,
					&data->mlx->line_length, &data->mlx->endian);
	if (!data->mlx->addr)
		ft_exit(data, "Can't init mlx addr");
	// data->win_height = 480;
	// data->win_width = 640;
	// data->mlx->ptr2 = mlx_init();
	// data->mlx->img2 = mlx_new_image(data->mlx->ptr2, data->win_width, data->win_height);
	// data->mlx->win2 = mlx_new_window(data->mlx->ptr2, data->win_width, data->win_height, "QubtroiD");
	// data->mlx->addr2 = mlx_get_data_addr(data->mlx->img2, &data->mlx->bpp2,
	// 				&data->mlx->line_length2, &data->mlx->endian2);
	render_minimap(data);
	render_player(data);
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->mlx->img, 0, 0);
	// mlx_put_image_to_window(data->mlx->ptr2, data->mlx->win2, data->mlx->img2, 0, 0);
	mlx_hook(data->mlx->win, 2, 1, &key_event, data);
	mlx_loop_hook(data->mlx->ptr, &render_image, data);
	mlx_hook(data->mlx->win, 17, 17, &ft_exit_esc, data);
	mlx_hook(data->mlx->win, 3, 10, &key_release, data);
	mlx_loop(data->mlx->ptr);
}

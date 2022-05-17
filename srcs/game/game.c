/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:02:26 by arudy             #+#    #+#             */
/*   Updated: 2022/05/17 18:50:13 by lleveque         ###   ########.fr       */
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
				while (i < (x + 1) * 100)
				{
					j = y * 100 + 1;
					while (j < (y + 1) * 100 - 1)
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
	x = (data->player->old_x * 100) - 5;
	y = (data->player->old_y * 100) - 5;
	while (x < (data->player->old_x * 100) + 5)
	{
		y = (data->player->old_y * 100) - 5;
		while (y < (data->player->old_y * 100) + 5)
		{

			data->mlx->addr[(y * data->mlx->line_length) + (x * data->mlx->bpp / 8) + 0] = (WHITE) & 0xFF;
			data->mlx->addr[(y * data->mlx->line_length) + (x * data->mlx->bpp / 8) + 1] = (WHITE >> 8) & 0xFF;
			data->mlx->addr[(y * data->mlx->line_length) + (x * data->mlx->bpp / 8) + 2] = (WHITE >> 16) & 0xFF;
			data->mlx->addr[(y * data->mlx->line_length) + (x * data->mlx->bpp / 8) + 3] = (WHITE >> 24) & 0xFF;
			y++;
		}
		x++;
	}
	x = (data->player->x * 100) - 5;
	y = (data->player->y * 100) - 5;
	while (x < (data->player->x * 100) + 5)
	{
		y = (data->player->y * 100) - 5;
		while (y < (data->player->y * 100) + 5)
		{
			data->mlx->addr[(y * data->mlx->line_length) + (x * data->mlx->bpp / 8) + 0] = (RED) & 0xFF;
			data->mlx->addr[(y * data->mlx->line_length) + (x * data->mlx->bpp / 8) + 1] = (RED >> 8) & 0xFF;
			data->mlx->addr[(y * data->mlx->line_length) + (x * data->mlx->bpp / 8) + 2] = (RED >> 16) & 0xFF;
			data->mlx->addr[(y * data->mlx->line_length) + (x * data->mlx->bpp / 8) + 3] = (RED >> 24) & 0xFF;
			y++;
		}
		x++;
	}
	// x = (data->player->old_x * 100);
	// y = (data->player->old_y * 100);
	// i = -1;
	// while (++i < 160)
	// {
	// 		data->mlx->addr[(((y + (int)data->player->old_dy * i / 5) * data->mlx->line_length) + (x + (int)data->player->old_dx * i /5 ) * data->mlx->bpp / 8) + 0] = (WHITE) & 0xFF;
	// 		data->mlx->addr[(((y + (int)data->player->old_dy * i / 5) * data->mlx->line_length) + (x + (int)data->player->old_dx * i / 5) * data->mlx->bpp / 8) + 1] = (WHITE >> 8) & 0xFF;
	// 		data->mlx->addr[(((y + (int)data->player->old_dy * i / 5) * data->mlx->line_length) + (x + (int)data->player->old_dx * i / 5) * data->mlx->bpp / 8) + 2] = (WHITE >> 16) & 0xFF;
	// 		data->mlx->addr[(((y + (int)data->player->old_dy * i / 5) * data->mlx->line_length) + (x + (int)data->player->old_dx * i / 5) * data->mlx->bpp / 8) + 3] = (WHITE >> 24) & 0xFF;
	// }
	// x = (data->player->x * 100);
	// y = (data->player->y * 100);
	// i = -1;
	// while (++i < 160)
	// {
	// 		data->mlx->addr[(((y + (int)data->player->dy * i / 5) * data->mlx->line_length) + (x + (int)data->player->dx * i / 5) * data->mlx->bpp / 8) + 0] = (RED) & 0xFF;
	// 		data->mlx->addr[(((y + (int)data->player->dy * i / 5) * data->mlx->line_length) + (x + (int)data->player->dx * i / 5) * data->mlx->bpp / 8) + 1] = (RED >> 8) & 0xFF;
	// 		data->mlx->addr[(((y + (int)data->player->dy * i / 5) * data->mlx->line_length) + (x + (int)data->player->dx * i / 5) * data->mlx->bpp / 8) + 2] = (RED >> 16) & 0xFF;
	// 		data->mlx->addr[(((y + (int)data->player->dy * i / 5) * data->mlx->line_length) + (x + (int)data->player->dx * i / 5) * data->mlx->bpp / 8) + 3] = (RED >> 24) & 0xFF;
	// }
}

void	render_ray(t_data *data)
{
	int	x;
	int	y;
	int	i;
	float	tan_a;

	data->ray->angle = data->player->angle;
	data->ray->r = 0;
	// check horizontal
	data->ray->dof = 0;
	tan_a = -1 / tan(data->ray->angle);
	if (data->ray->angle > PI) // looking up
	{
		data->ray->y = (((int)data->player->y >> 6) << 6) - 0.0001;
		data->ray->x = (data->player->y - data->ray->y) * tan_a + data->player->x;
		data->ray->yo = -64;
		data->ray->xo = -data->ray->yo * tan_a;
	}
	if (data->ray->angle < PI) // looking down
	{
		data->ray->y = (((int)data->player->y >> 6) << 6) + 64;
		data->ray->x = (data->player->y - data->ray->y) * tan_a + data->player->x;
		data->ray->yo = 64;
		data->ray->xo = -data->ray->yo * tan_a;
	}
	if (data->ray->angle == 0 || data->ray->angle == PI) // looking left or right
	{
		data->ray->x = data->player->x;
		data->ray->y = data->player->y;
		data->ray->dof = 8;
	}
	// while (data->ray->dof < 8)
	// {
	// 	data->ray->mx = (int)(data->player->x);
	// 	data->ray->my = (int)(data->player->y);
	// 	data->ray->mp = data->ray->my * data->map_fd->width + data->ray->mx;
	// 	if (data->map[data->ray->my][data->ray->mx] == '1')
	// 		data->ray->dof = 8;
	// 	else
	// 	{
	// 		data->ray->x += data->ray->xo;
	// 		data->ray->y += data->ray->yo;
	// 		data->ray->dof += 1;
	// 		// if (data->ray->yo > 0 && data->ray->x)
	// 	}
	// }
	x = (data->player->x * 100);
	y = (data->player->y * 100);
	(void)x;
	(void)y;
	(void)i;
	// printf("yo %f\n", data->ray->yo);
	// printf("xo %f\n", data->ray->xo);
	// printf("ray x %f\n", data->ray->x);
	// printf("ray mx %d\n", data->ray->mx);
	// printf("ray y %f\n", data->ray->y);
	// printf("ray my %d\n", data->ray->my);
	while (data->ray->my < data->ray->y)
	{
		data->mlx->addr[(((data->ray->my * 100) * data->mlx->line_length) + (data->ray->mx * 100) * data->mlx->bpp / 8) + 0] = (BLACK) & 0xFF;
		data->mlx->addr[(((data->ray->my * 100) * data->mlx->line_length) + (data->ray->mx * 100) * data->mlx->bpp / 8) + 1] = (BLACK >> 8) & 0xFF;
		data->mlx->addr[(((data->ray->my * 100) * data->mlx->line_length) + (data->ray->mx * 100) * data->mlx->bpp / 8) + 2] = (BLACK >> 16) & 0xFF;
		data->mlx->addr[(((data->ray->my * 100) * data->mlx->line_length) + (data->ray->mx * 100) * data->mlx->bpp / 8) + 3] = (BLACK >> 24) & 0xFF;	// i = -1;
		data->ray->my++;
	}
	while (data->ray->my > data->ray->y)
	{
		data->mlx->addr[(((data->ray->my * 100) * data->mlx->line_length) + (data->ray->mx * 100) * data->mlx->bpp / 8) + 0] = (BLACK) & 0xFF;
		data->mlx->addr[(((data->ray->my * 100) * data->mlx->line_length) + (data->ray->mx * 100) * data->mlx->bpp / 8) + 1] = (BLACK >> 8) & 0xFF;
		data->mlx->addr[(((data->ray->my * 100) * data->mlx->line_length) + (data->ray->mx * 100) * data->mlx->bpp / 8) + 2] = (BLACK >> 16) & 0xFF;
		data->mlx->addr[(((data->ray->my * 100) * data->mlx->line_length) + (data->ray->mx * 100) * data->mlx->bpp / 8) + 3] = (BLACK >> 24) & 0xFF;	// i = -1;
		data->ray->my--;
	}
	while (++i < 1)
		*(unsigned int*)(data->mlx->addr + (((int)data->ray->y ) * data->mlx->line_length + (x * (int)data->ray->x) * (data->mlx->bpp / 8))) = BLACK;
		x++;
	}
}

// void	render_ray(t_data *data)
// {
// 	int	x = 0;
// 	float planeX = 0;
// 	float planeY = 0.66;
// 	float cameraX;
// 	while (x < data->win_width)
// 	{
// 		cameraX = 2 * x / (float)data->win_width - 1;
// 		data->ray->x = data->player->dir_x + planeX * cameraX;
// 		data->ray->y = data->player->dir_y + planeY * cameraX;
// 		data->ray->mx = (int)data->player->x;
// 		data->ray->my = (int)data->player->y;
// 		data->ray->ddx = (data->ray->x == 0) ? 1e30 : abs(1 / data->ray->x);
// 		data->ray->ddy = (data->ray->y == 0) ? 1e30 : abs(1 / data->ray->y);
// 		data->ray->hit = 0;
// 		if (data->ray->x < 0)
// 		{
// 			data->ray->step_x = -1;
// 			sideDistX = (posX - mapX) * deltaDistX;
// 		}
// 		else
// 		{
// 			stepX = 1;
// 			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
// 		}
// 		if (data->ray->y < 0)
// 		{
// 			stepY = -1;
// 			sideDistY = (posY - mapY) * deltaDistY;
// 		}
// 		else
// 		{
// 			stepY = 1;
// 			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
// 		}
// 		x++;
// 	}
// }

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
	render_player(data);
	render_ray(data);
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->mlx->img, 0, 0);
	return (0);
}

void	game(t_data *data)
{
	data->mlx->ptr = mlx_init();
	data->win_height = data->map_fd->height * 100;
	data->win_width = data->map_fd->width * 100;
	if (!data->mlx->ptr)
		ft_exit(data, "Can't init mlx ptr");
	data->mlx->win = mlx_new_window(data->mlx->ptr, data->win_width, data->win_height, "QubtroiD");
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
	render_player(data);
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->mlx->img, 0, 0);
	mlx_hook(data->mlx->win, 2, 1, &key_event, data);
	mlx_loop_hook(data->mlx->ptr, &render_image, data);
	mlx_hook(data->mlx->win, 17, 17, &ft_exit_esc, data);
	mlx_hook(data->mlx->win, 3, 10, &key_release, data);
	mlx_loop(data->mlx->ptr);
}

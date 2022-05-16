/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:02:26 by arudy             #+#    #+#             */
/*   Updated: 2022/05/16 15:12:17 by lleveque         ###   ########.fr       */
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
			if (data->map[y][x] == '0' || data->map[y][x] == 'N')
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

	x = (data->player->old_x * 100) - 10;
	y = (data->player->old_y * 100) - 10;
	while (x < (data->player->old_x * 100) + 10)
	{
		y = (data->player->old_y * 100) - 10;
		while (y < (data->player->old_y * 100) + 10)
		{
			*(unsigned int*)(data->mlx->addr + (y * data->mlx->line_length + x * (data->mlx->bpp / 8))) = 0x00FFFFFF;
			y++;
		}
		x++;
	}
	x = (data->player->x * 100) - 10;
	y = (data->player->y * 100) - 10;
	while (x < (data->player->x * 100) + 10)
	{
		y = (data->player->y * 100) - 10;
		while (y < (data->player->y * 100) + 10)
		{
			*(unsigned int*)(data->mlx->addr + (y * data->mlx->line_length + x * (data->mlx->bpp / 8))) = 0x00FF7F7F;
			y++;
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
		printf("pressed\n");
	if (data->key->lr_pressed == 1)
		printf("pressed\n");
}

int	render_image(t_data *data)
{
	get_pos(data);
	// render_minimap(data);
	render_player(data);
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
	render_player(data);
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->mlx->img, 0, 0);
	mlx_hook(data->mlx->win, 2, 1, &key_event, data);
	mlx_loop_hook(data->mlx->ptr, &render_image, data);
	mlx_hook(data->mlx->win, 17, 17, &ft_exit_esc, data);
	mlx_hook(data->mlx->win, 3, 10, &key_release, data);
	mlx_loop(data->mlx->ptr);
}

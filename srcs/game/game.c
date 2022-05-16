/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:02:26 by arudy             #+#    #+#             */
/*   Updated: 2022/05/16 10:28:13 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_minimap(t_data *data)
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
			if (data->map[y][x] == '0')
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
			else if (data->map[y][x] == 'N')
			{
				while (i < (x + 1) * 100)
				{
					j = y * 100 + 1;
					while (j < (y + 1) * 100 - 1)
					{
						if ((j <= ((y * 100) + 40) || j >= ((y * 100) + 60)) || (i <= (x * 100) + 40 || i >= (x * 100 +60)))
							*(unsigned int*)(data->mlx->addr + (j * data->mlx->line_length + i * (data->mlx->bpp / 8))) = 0x00FFFFFF;
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

int	ft_exit(t_data *data)
{
	if (data->mlx->ptr && data->mlx->win)
	{
		mlx_clear_window(data->mlx->ptr, data->mlx->win);
		mlx_destroy_window(data->mlx->ptr, data->mlx->win);
	}
	if (data->mlx->ptr && data->mlx->img)
		mlx_destroy_image(data->mlx->ptr, data->mlx->img);
	if (data->mlx->ptr)
	{
		mlx_destroy_display(data->mlx->ptr);
		free(data->mlx->ptr);
	}
	free_all(data);
	exit(0);
}

int	key_event(int keycode, void *data)
{
	if (keycode == 119)
		move_forward(data);
	else if (keycode == 115)
		move_backward(data);
	else if (keycode == 97)
		move_left(data);
	else if (keycode == 100)
		move_right(data);
	else if (keycode == 65363)
		rotate_right(data);
	else if (keycode == 65361)
		rotate_left(data);
	else if (keycode == 65307)
		ft_exit(data);
	return (0);
}

void	game(t_data *data)
{
	data->mlx->ptr = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->ptr, data->map_fd->width * 100, data->map_fd->height * 100, "QubtroiD");
	data->mlx->img = mlx_new_image(data->mlx->ptr, data->map_fd->width * 100, data->map_fd->height * 100);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, &data->mlx->bpp,
					&data->mlx->line_length, &data->mlx->endian);
	get_minimap(data);
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->mlx->img, 0, 0);
	mlx_key_hook(data->mlx->win, &key_event, data);
	mlx_hook(data->mlx->win, 17, 17, &ft_exit, data);
	mlx_loop(data->mlx->ptr);
}

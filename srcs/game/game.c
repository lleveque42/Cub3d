/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:02:26 by arudy             #+#    #+#             */
/*   Updated: 2022/05/13 17:08:47 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx->addr + (y * data->mlx->line_length + x * (data->mlx->bpp / 8));
	*(unsigned int*)dst = color;
}

void	game(t_data *data)
{
	char	*dst;
	int		x = 0;
	int		y = 0;
	int		i = 0;
	int		j = 0;

	data->mlx->m = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->m, 1000, 1000, "QubtroiD");
	data->mlx->img = mlx_new_image(data->mlx->m, 1000, 1000);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, &data->mlx->bpp,
					&data->mlx->line_length, &data->mlx->endian);
	while (data->map[y])
	{
		x = 0;
		i = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '0')
			{
				while(i < (x + 1) * 100)
				{
					j = y * 100;
					while (j < (y + 1) * 100)
					{
						dst = data->mlx->addr + (j * data->mlx->line_length + i * (data->mlx->bpp / 8));
						*(unsigned int*)dst = 0x00FFFFFF;
						j++;
					}
					i++;
				}
			}
			else if (data->map[y][x] == '1')
			{
				while(i < (x + 1) * 100)
				{
					j = y * 100;
					while (j < (y + 1) * 100)
					{
						dst = data->mlx->addr + (j * data->mlx->line_length + i * (data->mlx->bpp / 8));
						*(unsigned int*)dst = 0x007F7F7F;
						j++;
					}
					i++;
				}
			}
			else
			{
				printf("i=%d, c=%d\n", i, (int)data->map[y][x]);
				while(i < (x + 1) * 100)
				{
					j = y * 100;
					while (j < (y + 1) * 100)
					{
						if (j <= ((y * 100) + 40) && j >= ((y * 100) + 60) && i <= (x * 100) + 40 && i >= (x * 100 +60))
						{
							dst = data->mlx->addr + (j * data->mlx->line_length + i * (data->mlx->bpp / 8));
							*(unsigned int*)dst = 0x00FFFFFF;
						}
						j++;
					}
					i++;
				}
			}
			x++;
		}
		y++;
	}

	// i = 105;
	// while(i++ < 205)
	// {
	// 	j = 0;
	// 	dst = data->mlx->addr + (i * data->mlx->line_length + j * (data->mlx->bpp / 8));
	// 	*(unsigned int*)dst = 0x00FF0000;
	// 	while (j++ < 100)
	// 	{
	// 		dst = data->mlx->addr + (i * data->mlx->line_length + j * (data->mlx->bpp / 8));
	// 		*(unsigned int*)dst = 0x00FF0000;
	// 	}
	// }
	// for (int i = 0; i < 500; i++)
		// my_mlx_pixel_put(data, i, i, 0x00FF0000);
	// my_mlx_pixel_put(data, 450, 450, 0x00FF0000);
	// my_mlx_pixel_put(data, 5, 5, 0x00FF0000);
	// my_mlx_pixel_put(data, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(data->mlx->m, data->mlx->win, data->mlx->img, 0, 0);
	mlx_loop(data->mlx->m);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:02:26 by arudy             #+#    #+#             */
/*   Updated: 2022/05/31 14:30:06 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	render_ray(t_data *data)
{
	int	x;

	x = 0;
	while (x < SCREEN_W)
	{
		ray_dir(data, x);
		calc_steps(data);
		ray_hit_wall_pos(data);
		calc_line_height(data);
		draw_ceiling(data, x);
		get_color(data);
		draw_texture(data, x);
		draw_floor(data, x);
		x++;
	}
}

int	render_image(t_data *data)
{
	get_pos(data);
	if (data->player->change)
	{
		render_ray(data);
		mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, \
		data->mlx->img, 0, 0);
	}
	data->player->change = 0;
	return (0);
}

void	init_game(t_data *data)
{
	data->mlx->ptr = mlx_init();
	if (!data->mlx->ptr)
		ft_exit(data, "Can't init mlx ptr");
	data->mlx->win = mlx_new_window(data->mlx->ptr, SCREEN_W, SCREEN_H, \
		"QubtroiD");
	if (!data->mlx->win)
		ft_exit(data, "Can't init mlx window");
	data->mlx->img = mlx_new_image(data->mlx->ptr, SCREEN_W, SCREEN_H);
	if (!data->mlx->img)
		ft_exit(data, "Can't init mlx image");
	data->mlx->addr = (int *)mlx_get_data_addr(data->mlx->img, &data->mlx->bpp, \
		&data->mlx->line_length, &data->mlx->endian);
	if (!data->mlx->addr)
		ft_exit(data, "Can't init mlx addr");
	get_textures(data);
}

void	game(t_data *data)
{
	init_game(data);
	mlx_hook(data->mlx->win, 2, 1, &key_event, data);
	mlx_loop_hook(data->mlx->ptr, &render_image, data);
	mlx_hook(data->mlx->win, 17, 17, &ft_exit_esc, data);
	mlx_hook(data->mlx->win, 3, 10, &key_release, data);
	mlx_loop(data->mlx->ptr);
}

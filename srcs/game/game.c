/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:02:26 by arudy             #+#    #+#             */
/*   Updated: 2022/05/25 18:01:48 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// void	render_minimap(t_data *data)
// {
// 	int		x = 0;
// 	int		y = 0;
// 	int		i = 0;
// 	int		j = 0;

// 	while (data->map[y])
// 	{
// 		x = 0;
// 		i = 0;
// 		while (data->map[y][x])
// 		{
// 			i += 2;
// 			if (data->map[y][x] != '1' && data->map[y][x] != ' ')
// 			{
// 				while (i < (x + 1) * TILE_SIZE)
// 				{
// 					j = y * TILE_SIZE + 1;
// 					while (j < (y + 1) * TILE_SIZE - 1)
// 						pixel_put(data, i, j++, WHITE);
// 					i++;
// 				}
// 			}
// 			else if (data->map[y][x] == '1')
// 			{
// 				while (i < (x + 1) * TILE_SIZE)
// 				{
// 					j = y * TILE_SIZE + 1;
// 					while (j < (y + 1) * TILE_SIZE - 1)
// 						pixel_put(data, i, j++, GREY);
// 					i++;
// 				}
// 			}
// 			else
// 			{
// 				i += 98;
// 				j += 99;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	render_player(t_data *data)
// {
// 	(void)data;
// 	int	x;
// 	int	y;
// 	int	i;

// 	(void)i;
// 	x = data->player->old_x * 100 - 5;
// 	y = data->player->old_y * 100 - 5;
// 	while (x < data->player->old_x * 100 + 5)
// 	{
// 		y = data->player->old_y * 100 - 5;
// 		while (y < data->player->old_y * 100 + 5)
// 			pixel_put(data, x, y++, WHITE);
// 		x++;
// 	}
// 	x = data->player->x * 100 - 5;
// 	y = data->player->y * 100 - 5;
// 	while (x < data->player->x * 100 + 5)
// 	{
// 		y = data->player->y * 100 - 5;
// 		while (y < data->player->y * 100 + 5)
// 			pixel_put(data, x, y++, RED);
// 		x++;
// 	}
// 	x = data->player->old_x * 100;
// 	y = data->player->old_y * 100;
// 	i = -1;
// 	while (++i < 150)
// 		pixel_put(data, (x + (int)data->player->old_dx * i / 5), (y + (int)data->player->old_dy * i / 5), WHITE);
// 	x = data->player->x * 100;
// 	y = data->player->y * 100;
// 	i = -1;
// 	while (++i < 150)
// 		pixel_put(data, (x + (int)data->player->dir_x * i / 5), (y + (int)data->player->dir_y * i / 5), RED);
// }

void	render_ray(t_data *data)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	color = 0;
	while (x < SCREEN_W)
	{
		ray_dir(data, x);
		calc_steps(data);

		// Perform the algo to check when & where a ray hit a wall
		data->ray->hit = 0;
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
			if (data->map[data->ray->map_y][data->ray->map_x] == '1')
				data->ray->hit = 1;
		}

		// Calculate dist on cam direction, (sort of avoid fisheye effect)
		if (data->ray->side == 0)
			data->ray->pwd = data->ray->sdx - data->ray->ddx;
		else
			data->ray->pwd = data->ray->sdy - data->ray->ddy;

		// Calculate height of the line to draw & and coor of pixels to fill
		data->ray->line_h = (int)(SCREEN_H / data->ray->pwd);
		data->ray->draw_start = -data->ray->line_h / 2 + SCREEN_H / 2;
		if (data->ray->draw_start < 0)
			data->ray->draw_start = 0;
		data->ray->draw_end = data->ray->line_h / 2 + SCREEN_H / 2;
		if (data->ray->draw_end >= SCREEN_H)
			data->ray->draw_end = SCREEN_H - 1;

		// choose wall color
		color = RED;
		if (data->ray->side == 0)
			color = REDDD;

		// draw ray on screen
		y = 0;
		while (y < SCREEN_H)
		{
			if (y >= data->ray->draw_start && y <= data->ray->draw_end)
				pixel_put(data, x, y, color);
			else if (y > data->ray->draw_start)
				pixel_put(data, x, y, data->texture->f_color);
			else
				pixel_put(data, x, y, data->texture->c_color);
			++y;
		}
		x++;
	}
}

int	render_image(t_data *data)
{
	get_pos(data);
	if (data->player->change)
	{
		render_ray(data);
		mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->mlx->img, 0, 0);
	}
	data->player->change = 0;
	return (0);
}

// int	render_image2(t_data *data)
// {
// 	get_pos(data);
// 	if (data->player->change)
// 	{
// 		render_ray(data);
// 		mlx_put_image_to_window(data->mlx->ptr2, data->mlx->win2, data->mlx->img, 0, 0);
// 	}
// 	data->player->change = 0;
// 	return (0);
// }

// char	*create_m(char *s, t_data *data)
// {
// 	int	 i = 1;

// 	s = ft_strdup(data->map[0], data);
// 	// s = ft_strjoin(s, "\n", data);
// 	while (data->map[i])
// 	{
// 		s = ft_strjoin(s, ft_strdup(data->map[i], data), data);
// 		// if (data->map[i + 1] != NULL)
// 			// s = ft_strjoin(s, "\n", data);
// 		i++;
// 	}
// 	return (s);
// }

void	game(t_data *data)
{
	data->mlx->ptr = mlx_init();
	if (!data->mlx->ptr)
		ft_exit(data, "Can't init mlx ptr");
	data->mlx->win = mlx_new_window(data->mlx->ptr, SCREEN_W, SCREEN_H, "QubtroiD");
	if (!data->mlx->win)
		ft_exit(data, "Can't init mlx window");
	data->mlx->img = mlx_new_image(data->mlx->ptr, SCREEN_W, SCREEN_H);
	if (!data->mlx->img)
		ft_exit(data, "Can't init mlx image");
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, &data->mlx->bpp,
					&data->mlx->line_length, &data->mlx->endian);
	if (!data->mlx->addr)
		ft_exit(data, "Can't init mlx addr");
	// render_minimap(data);
	// render_player(data);
	render_ray(data);
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->mlx->img, 0, 0);
	mlx_hook(data->mlx->win, 2, 1, &key_event, data);
	mlx_loop_hook(data->mlx->ptr, &render_image, data);
	mlx_hook(data->mlx->win, 17, 17, &ft_exit_esc, data);
	mlx_hook(data->mlx->win, 3, 10, &key_release, data);
	mlx_loop(data->mlx->ptr);
}

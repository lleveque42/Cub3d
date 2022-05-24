/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:02:26 by arudy             #+#    #+#             */
/*   Updated: 2022/05/24 18:00:03 by arudy            ###   ########.fr       */
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
				while (i < (x + 1) * TILE_SIZE)
				{
					j = y * TILE_SIZE + 1;
					while (j < (y + 1) * TILE_SIZE - 1)
						pixel_put(data, i, j++, WHITE);
					i++;
				}
			}
			else if (data->map[y][x] == '1')
			{
				while (i < (x + 1) * TILE_SIZE)
				{
					j = y * TILE_SIZE + 1;
					while (j < (y + 1) * TILE_SIZE - 1)
						pixel_put(data, i, j++, GREY);
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
	(void)data;
	int	x;
	int	y;
	int	i;

	(void)i;
	x = data->player->old_x * 100 - 5;
	y = data->player->old_y * 100 - 5;
	while (x < data->player->old_x * 100 + 5)
	{
		y = data->player->old_y * 100 - 5;
		while (y < data->player->old_y * 100 + 5)
			pixel_put(data, x, y++, WHITE);
		x++;
	}
	x = data->player->x * 100 - 5;
	y = data->player->y * 100 - 5;
	while (x < data->player->x * 100 + 5)
	{
		y = data->player->y * 100 - 5;
		while (y < data->player->y * 100 + 5)
			pixel_put(data, x, y++, RED);
		x++;
	}
	x = data->player->old_x * 100;
	y = data->player->old_y * 100;
	i = -1;
	while (++i < 50)
		pixel_put(data, (x + (int)data->player->old_dx * i / 5), (y + (int)data->player->old_dy * i / 5), WHITE);
	x = data->player->x * 100;
	y = data->player->y * 100;
	i = -1;
	while (++i < 50)
		pixel_put(data, (x + (int)data->player->dir_x * i / 5), (y + (int)data->player->dir_y * i / 5), RED);
}

void	render_ray(t_data *data)
{
	int	x;
	int	color;
	int	y;

	(void)color;

	x = 0;
	color = 0;
	while (x < RES)
	{
		// Calculate ray pos & dir
		data->ray->camera_x = 2 * (float)x / (float)RES - 1;
		data->ray->dir_x = data->player->dir_x + data->ray->plane_x * data->ray->camera_x;
		data->ray->dir_y = data->player->dir_y + data->ray->plane_y * data->ray->camera_x;
		data->ray->map_x = (int)data->player->x;
		data->ray->map_y = (int)data->player->y;

		// Calculate step & side dist
		if (data->ray->dir_x == 0)
			data->ray->ddx = 1e30;
		else
			data->ray->ddx = sqrt(1 + (data->ray->dir_y * data->ray->dir_y) / (data->ray->dir_x * data->ray->dir_x));
		if (data->ray->dir_y == 0)
			data->ray->ddy = 1e30;
		else
			data->ray->ddy = sqrt(1 + (data->ray->dir_x * data->ray->dir_x) / (data->ray->dir_y * data->ray->dir_y));
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

		// Perform the algo to check when & where a ray hit a wall
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
		// printf("win_height = %d\n", data->win_height);
		// printf("pwd = %f\n", data->ray->pwd);
		data->ray->line_h = (int)(RES / data->ray->pwd);
		data->ray->draw_start = -data->ray->line_h / 2 + RES / 2;
		if (data->ray->draw_start < 0)
			data->ray->draw_start = 0;
		data->ray->draw_end = data->ray->line_h / 2 + RES / 2;
		if (data->ray->draw_end >= RES)
			data->ray->draw_end = RES - 1;

		// choose wall color
		color = RED;
		if (data->ray->side == 0)
			color = REDDD;

		// draw ray on screen
		y = 0;
		while (y < RES)
		{
			if (y >= data->ray->draw_start && y <= data->ray->draw_end)
				pixel_put2(data, x, y, color);
			else if (y > data->ray->draw_start)
				pixel_put2(data, x, y, data->texture->f_color);
			else
				pixel_put2(data, x, y, data->texture->c_color);
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
		render_player(data);
		render_ray(data);
		mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->mlx->img, 0, 0);
		mlx_put_image_to_window(data->mlx->ptr2, data->mlx->win2, data->mlx->img2, 0, 0);
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
	// data->m = create_m(data->m, data);

	// data->win_height = data->map_fd->height * TILE_SIZE; // on s'en fou ducoup
	// data->win_width = data->map_fd->width * TILE_SIZE; // on s'en fou ducoup
	data->mlx->ptr = mlx_init();
	data->mlx->ptr2 = mlx_init();
	if (!data->mlx->ptr)
		ft_exit(data, "Can't init mlx ptr");
	data->mlx->win = mlx_new_window(data->mlx->ptr, RES, RES, "QubtroiD");
	data->mlx->win2 = mlx_new_window(data->mlx->ptr2, RES, RES, "QubtroiD");
	if (!data->mlx->win)
		ft_exit(data, "Can't init mlx window");
	data->mlx->img = mlx_new_image(data->mlx->ptr, RES, RES);
	data->mlx->img2 = mlx_new_image(data->mlx->ptr2, RES, RES);
	if (!data->mlx->img)
		ft_exit(data, "Can't init mlx image");
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, &data->mlx->bpp,
					&data->mlx->line_length, &data->mlx->endian);
	data->mlx->addr2 = mlx_get_data_addr(data->mlx->img2, &data->mlx->bpp,
					&data->mlx->line_length, &data->mlx->endian);
	if (!data->mlx->addr)
		ft_exit(data, "Can't init mlx addr");
	render_minimap(data);
	render_player(data);
	render_ray(data);
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->mlx->img, 0, 0);
	mlx_put_image_to_window(data->mlx->ptr2, data->mlx->win2, data->mlx->img2, 0, 0);
	mlx_hook(data->mlx->win2, 2, 1, &key_event, data);
	mlx_loop_hook(data->mlx->ptr2, &render_image, data);
	mlx_hook(data->mlx->win2, 17, 17, &ft_exit_esc, data);
	mlx_hook(data->mlx->win2, 3, 10, &key_release, data);
	mlx_hook(data->mlx->win, 2, 1, &key_event, data);
	mlx_loop_hook(data->mlx->ptr, &render_image, data);
	mlx_hook(data->mlx->win, 17, 17, &ft_exit_esc, data);
	mlx_hook(data->mlx->win, 3, 10, &key_release, data);
	mlx_loop(data->mlx->ptr2);
	mlx_loop(data->mlx->ptr);
}

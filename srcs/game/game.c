/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:02:26 by arudy             #+#    #+#             */
/*   Updated: 2022/05/18 16:49:31 by arudy            ###   ########.fr       */
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
	while (x < data->player->old_x+ 5)
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
	// i = -1;
	// while (++i < 80)
	// {
	// 		data->mlx->addr[(((y + (int)data->player->old_dy / 5 * i) * data->mlx->line_length) + (x + (int)data->player->old_dx / 5 * i) * data->mlx->bpp / 8) + 0] = (WHITE) & 0xFF;
	// 		data->mlx->addr[(((y + (int)data->player->old_dy / 5 * i) * data->mlx->line_length) + (x + (int)data->player->old_dx / 5 * i) * data->mlx->bpp / 8) + 1] = (WHITE >> 8) & 0xFF;
	// 		data->mlx->addr[(((y + (int)data->player->old_dy / 5 * i) * data->mlx->line_length) + (x + (int)data->player->old_dx / 5 * i) * data->mlx->bpp / 8) + 2] = (WHITE >> 16) & 0xFF;
	// 		data->mlx->addr[(((y + (int)data->player->old_dy / 5 * i) * data->mlx->line_length) + (x + (int)data->player->old_dx / 5 * i) * data->mlx->bpp / 8) + 3] = (WHITE >> 24) & 0xFF;
	// }
	// x = data->player->x;
	// y = data->player->y;
	// i = -1;
	// while (++i < 80)
	// {
	// 		data->mlx->addr[(((y + (int)data->player->dy / 5 * i) * data->mlx->line_length) + (x + (int)data->player->dx / 5 * i) * data->mlx->bpp / 8) + 0] = (RED) & 0xFF;
	// 		data->mlx->addr[(((y + (int)data->player->dy / 5 * i) * data->mlx->line_length) + (x + (int)data->player->dx / 5 * i) * data->mlx->bpp / 8) + 1] = (RED >> 8) & 0xFF;
	// 		data->mlx->addr[(((y + (int)data->player->dy / 5 * i) * data->mlx->line_length) + (x + (int)data->player->dx / 5 * i) * data->mlx->bpp / 8) + 2] = (RED >> 16) & 0xFF;
	// 		data->mlx->addr[(((y + (int)data->player->dy / 5 * i) * data->mlx->line_length) + (x + (int)data->player->dx / 5 * i) * data->mlx->bpp / 8) + 3] = (RED >> 24) & 0xFF;
	// }
}

void	render_ray(t_data *data)
{
	(void)data;
	int		i;
	int		r;
	float		x;
	float		y;
	float	tan_a;
	float	tan_n;


	(void)x;
	(void)y;
	(void)i;
	(void)tan_a;
	(void)tan_n;
	r = 0;
	while (data->player->change && r < 1)
	{
		data->ray->angle = data->player->angle;
		data->ray->r = 0;
		// ===================== check horizontal =================================
		data->ray->dof = 0;
		tan_a = -1 / tan(data->ray->angle);
		if (data->ray->angle > PI) // looking up
		{
			data->ray->y = (((int)data->player->y >> 6) << 6) - 0.0001;
			data->ray->x = (data->player->y - data->ray->y) * tan_a + data->player->x;
			data->ray->yo = -64;
			data->ray->xo = -data->ray->yo * tan_a;
		}
		else if (data->ray->angle < PI) // looking down
		{
			data->ray->y = (((int)data->player->y >> 6) << 6) + 64;
			data->ray->x = (data->player->y - data->ray->y) * tan_a + data->player->x;
			data->ray->yo = 64;
			data->ray->xo = -data->ray->yo * tan_a;
		}
		else if (data->ray->angle == 0 || data->ray->angle == PI) // looking left or right
		{
			data->ray->x = data->player->x;
			data->ray->y = data->player->y;
			data->ray->dof = data->map_fd->width;
		}
		while (data->ray->dof < data->map_fd->width)
		{
			data->ray->mx = (int)data->ray->x >> 6;
			data->ray->my = (int)data->ray->y >> 6;
			data->ray->mp = data->ray->my * data->map_fd->width + data->ray->mx;
			// printf("mp : %d\n", data->ray->mp);
			// printf("M : %c\n", data->m[data->ray->mp]);
			if (data->ray->mp > 0 && data->ray->mp < data->map_fd->width * data->map_fd->height && data->m[data->ray->mp] == '1')
				data->ray->dof = data->map_fd->width;
			else
			{
				data->ray->x += data->ray->xo;
				data->ray->y += data->ray->yo;
				data->ray->dof += 1;
			}
		}
		x = data->player->old_x;
		y = data->player->old_y;
		if (data->ray->old_y && y < data->ray->old_y)
		{
			while (y < data->ray->old_y)
			{
				data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 0] = (WHITE) & 0xFF;
				data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 1] = (WHITE >> 8) & 0xFF;
				data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 2] = (WHITE >> 16) & 0xFF;
				data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 3] = (WHITE >> 24) & 0xFF;
				if (data->player->old_dy < 0.03 && data->player->old_dy > -0.03 && y > 0 && y < (64 * data->map_fd->height - (data->player->old_y / 64)))
					y += data->player->old_dy * 50;
				else if (y > 0 && y < (64 * data->map_fd->height - (data->player->old_y / 64)))
					y += data->player->old_dy;
				else
					break ;
				if (x > 0 && x < (64 * data->map_fd->width - (data->player->old_x / 64)))
					x += data->player->old_dx;
			}
		}
		else if (data->ray->old_y)
		{
			while (y > data->ray->old_y)
			{
				data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 0] = (WHITE) & 0xFF;
				data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 1] = (WHITE >> 8) & 0xFF;
				data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 2] = (WHITE >> 16) & 0xFF;
				data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 3] = (WHITE >> 24) & 0xFF;
				if (data->player->old_dy < 0.03 && data->player->old_dy > -0.03 && y > 0 && y < (64 * data->map_fd->height - (data->player->old_y / 64)))
					y += data->player->old_dy * 50;
				else if (y > 0 && y < (64 * data->map_fd->height - (data->player->old_y / 64)))
					y += data->player->old_dy;
				else
					break ;
				if (x > 0 && x < (64 * data->map_fd->width - (data->player->old_x / 64)))
					x += data->player->old_dx;
			}
		}
		data->ray->old_x = data->ray->x;
		data->ray->old_y = data->ray->y;
		x = data->player->x;
		y = data->player->y;
		// printf("x : %f\n", x);
		// printf("y : %f\n", y);
		// printf("ray mx : %d\n", data->ray->mx);
		// printf("ray my : %d\n", data->ray->my);
		// printf("ray x : %f\n", data->ray->x);
		// printf("ray y : %f\n", data->ray->y);
		// printf("dir x : %f\n", data->player->dx);
		// printf("dir y : %f\n", data->player->dy);
		// printf("dy : %f\n", data->player->dy);
		// printf("dx : %f\n", data->player->dx);
		// printf("%f\n", 64 * data->map_fd->width - (data->player->x / 64));
		if (y < data->ray->y)
		{
			while (y < data->ray->y)
			{
				printf("1\n");
				data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 0] = (BLACK) & 0xFF;
				data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 1] = (BLACK >> 8) & 0xFF;
				data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 2] = (BLACK >> 16) & 0xFF;
				data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 3] = (BLACK >> 24) & 0xFF;
				// printf("y : %f\n", y);
				// printf("ray y : %f\n", data->ray->y);
				// printf("dy : %f\n", data->player->dy);
				// printf("x : %f\n", x);
				// printf("dx : %f\n", data->player->dx);
				if (data->player->dy < 0.03 && data->player->dy > -0.03 && y > 0 && y < (64 * data->map_fd->height - (data->player->y / 64)))
					y += data->player->dy * 50;
				else if (y > 0 && y < (64 * data->map_fd->height - (data->player->y / 64)))
					y += data->player->dy;
				else
					break ;
				if (x >= 0 && x <= (64 * data->map_fd->width - (data->player->x / 64)))
					x += data->player->dx;
			}
			break ;
		}
		else
		{
			while (y > data->ray->y)
			{
				// printf("2\n");
				data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 0] = (BLACK) & 0xFF;
				data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 1] = (BLACK >> 8) & 0xFF;
				data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 2] = (BLACK >> 16 ) & 0xFF;
				data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 3] = (BLACK >> 24) & 0xFF;
				// printf("y : %f\n", y);
				// printf("ray y : %f\n", data->ray->y);
				// printf("dy : %f\n", data->player->dy);
				// printf("x : %f\n", x);
				// printf("dx : %f\n", data->player->dx);
				// printf("ray x : %f\n", data->ray->x);
				if (data->player->dy < 0.03 && data->player->dy > -0.03 && y > 0 && y < (64 * data->map_fd->height - (data->player->y / 64)))
					y += data->player->dy * 50;
				else if (y > 0 && y < (64 * data->map_fd->height - (data->player->y / 64)))
					y += data->player->dy;
				else
					break ;
				if (x >= 0 && x < (64 * data->map_fd->width - (data->player->x / 64)))
					x += data->player->dx;
			}
			// break ;
		}
		// // ===================== check vertical =================================
		// tan_n = -tan(data->ray->angle);
		// if (data->ray->angle > PI / 2 && data->ray->angle < 3 * PI / 2) // looking up
		// {
		// 	data->ray->x = (((int)data->player->x >> 6) << 6) - 0.0001;
		// 	data->ray->y = (data->player->x - data->ray->x) * tan_n + data->player->y;
		// 	data->ray->xo = -64;
		// 	data->ray->yo = -data->ray->xo * tan_n;
		// }
		// else if (data->ray->angle < PI / 2 || data->ray->angle > 3 * PI / 2) // looking down
		// {
		// 	data->ray->x = (((int)data->player->y >> 6) << 6) + 64;
		// 	data->ray->y = (data->player->x - data->ray->x) * tan_n + data->player->y;
		// 	data->ray->xo = 64;
		// 	data->ray->yo = -data->ray->xo * tan_n;
		// }
		// else if (data->ray->angle == 0 || data->ray->angle == PI) // looking left or right
		// {
		// 	data->ray->x = data->player->x;
		// 	data->ray->y = data->player->y;
		// 	data->ray->dof = data->map_fd->width;
		// }
		// while (data->ray->dof < data->map_fd->width)
		// {
		// 	data->ray->mx = (int)data->ray->x >> 6;
		// 	data->ray->my = (int)data->ray->y >> 6;
		// 	data->ray->mp = data->ray->my * data->map_fd->width + data->ray->mx;
		// 	if (data->ray->mp > 0 && data->ray->mp < data->map_fd->width * data->map_fd->height && data->m[data->ray->mp] == '1')
		// 		data->ray->dof = data->map_fd->width;
		// 	else
		// 	{
		// 		data->ray->x += data->ray->xo;
		// 		data->ray->y += data->ray->yo;
		// 		data->ray->dof += 1;
		// 	}
		// }
		// printf("y : %f\n", y);
		// printf("ray y : %f\n", data->ray->y);
		// printf("dy : %f\n", data->player->dy);
		// printf("x : %f\n", x);
		// printf("ray x : %f\n", data->ray->x);
		// printf("dx : %f\n", data->player->dx);
		// x = data->player->old_x;
		// y = data->player->old_y;
		// // if (data->ray->old_x && x < data->ray->old_x)
		// // {
		// // 	printf("COUCOUCOUCOU\n");
		// // 	while (x < data->ray->old_x)
		// // 	{
		// // 		data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 0] = (RED) & 0xFF;
		// // 		data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 1] = ((RED) >> 8) & 0xFF;
		// // 		data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 2] = ((RED) >> 16) & 0xFF;
		// // 		data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 3] = ((RED) >> 24) & 0xFF;
		// // 		if (y > 0 && y < (64 * data->map_fd->height - (data->player->old_y / 64)))
		// // 			y += data->player->old_dy;
		// // 		if (x > 0 && x < (64 * data->map_fd->width - (data->player->old_x / 64)))
		// // 			x += data->player->old_dx;
		// // 	}
		// // }
		// // else if (data->ray->old_x)
		// // {
		// // 	while (x < data->ray->old_x)
		// // 	{
		// // 		data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 0] = (RED) & 0xFF;
		// // 		data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 1] = ((RED) >> 8) & 0xFF;
		// // 		data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 2] = ((RED) >> 16) & 0xFF;
		// // 		data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 3] = ((RED) >> 24) & 0xFF;
		// // 		if (y > 0 && y < (64 * data->map_fd->height - (data->player->old_y / 64)))
		// // 			y += data->player->old_dy;
		// // 		if (x > 0 && x < (64 * data->map_fd->width - (data->player->old_x / 64)))
		// // 			x += data->player->old_dx;
		// // 	}
		// // }
		// data->ray->old_x = data->ray->x;
		// data->ray->old_y = data->ray->y;
		// x = data->player->x;
		// y = data->player->y;
		// // printf("x : %d\n", x);
		// // printf("y : %d\n", y);
		// // printf("ray mx : %d\n", data->ray->mx);
		// // printf("ray my : %d\n", data->ray->my);
		// // printf("ray x : %f\n", data->ray->x);
		// // printf("ray y : %f\n", data->ray->y);
		// // printf("dir x : %f\n", data->player->dx);
		// // printf("dir y : %f\n", data->player->dy);
		// // printf("dy : %f\n", data->player->dy);
		// // printf("dx : %f\n", data->player->dx);
		// // printf("%f\n", 64 * data->map_fd->width - (data->player->x / 64));
		// if (x < data->ray->x)
		// {
		// 	while (x < data->ray->x)
		// 	{
		// 		printf("1\n");
		// 		data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 0] = (RED) & 0xFF;
		// 		data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 1] = ((RED) >> 8) & 0xFF;
		// 		data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 2] = ((RED) >> 16) & 0xFF;
		// 		data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 3] = ((RED) >> 24) & 0xFF;
		// 		// printf("y : %f\n", y);
		// 		// printf("ray y : %f\n", data->ray->y);
		// 		// printf("dy : %f\n", data->player->dy);
		// 		// printf("x : %f\n", x);
		// 		// printf("dx : %f\n", data->player->dx);
		// 		if (y > 0 && y < (64 * data->map_fd->height - (data->player->y / 64)))
		// 			y += data->player->dy;
		// 		if (x >= 0 && x <= (64 * data->map_fd->width - (data->player->x / 64)))
		// 			x += data->player->dx;
		// 	}
		// 	break ;
		// }
		// else
		// {
		// 	while (x > data->ray->x)
		// 	{
		// 		printf("2\n");
		// 		data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 0] = (RED) & 0xFF;
		// 		data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 1] = ((RED) >> 8) & 0xFF;
		// 		data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 2] = ((RED) >> 16) & 0xFF;
		// 		data->mlx->addr[(((int)y * data->mlx->line_length) + ((int)x * data->mlx->bpp / 8)) + 3] = ((RED) >> 24) & 0xFF;
		// 		// printf("y : %f\n", y);
		// 		// printf("ray y : %f\n", data->ray->y);
		// 		// printf("dy : %f\n", data->player->dy);
		// 		// printf("x : %f\n", x);
		// 		// printf("dx : %f\n", data->player->dx);
		// 		if (y > 0 && y < (64 * data->map_fd->height - (data->player->y / 64)))
		// 			y += data->player->dy;
		// 		if (x >= 0 && x < (64 * data->map_fd->width - (data->player->x / 64)))
		// 			x += data->player->dx;
		// 	}
		// 	break ;
		// }
		r++;
	}
	data->player->change = 0;
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
// 			data->ray->step_	x = -1;
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
	data->mlx->ptr = mlx_init();
	data->win_height = data->map_fd->height * 64;
	data->win_width = data->map_fd->width * 64;
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
	render_minimap(data);
	render_player(data);
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->mlx->img, 0, 0);
	mlx_hook(data->mlx->win, 2, 1, &key_event, data);
	mlx_loop_hook(data->mlx->ptr, &render_image, data);
	mlx_hook(data->mlx->win, 17, 17, &ft_exit_esc, data);
	mlx_hook(data->mlx->win, 3, 10, &key_release, data);
	mlx_loop(data->mlx->ptr);
}

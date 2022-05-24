/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:58:10 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/24 11:20:05 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_null_1(t_data *data)
{
	data->map = NULL;
	data->filled = 0;
	data->texture->c->r = -1;
	data->texture->c->g = -1;
	data->texture->c->b = -1;
	data->texture->f->r = -1;
	data->texture->f->g = -1;
	data->texture->f->b = -1;
	data->texture->no_path = NULL;
	data->texture->so_path = NULL;
	data->texture->we_path = NULL;
	data->texture->ea_path = NULL;
	data->texture->no_fd = -1;
	data->texture->so_fd = -1;
	data->texture->we_fd = -1;
	data->texture->ea_fd = -1;
	data->map_fd->begin = 0;
	data->map_fd->ended = 0;
	data->map_fd->height = 0;
	data->map_fd->width = 0;
}

void	init_null_2(t_data *data)
{
	data->win_width = 0;
	data->win_height = 0;
	data->key->w_pressed = 0;
	data->key->s_pressed = 0;
	data->key->a_pressed = 0;
	data->key->d_pressed = 0;
	data->key->la_pressed = 0;
	data->key->lr_pressed = 0;
	data->mlx->ptr = NULL;
	data->mlx->ptr2 = NULL;
	data->mlx->win = NULL;
	data->mlx->win2 = NULL;
	data->mlx->img = NULL;
	data->mlx->img2 = NULL;
	data->mlx->addr = NULL;
	data->mlx->addr2 = NULL;
	data->mlx->bpp = 0;
	data->mlx->bpp2 = 0;
	data->mlx->line_length = 0;
	data->mlx->line_length2 = 0;
	data->mlx->endian = 0;
	data->mlx->endian2 = 0;
}

void	init_null_3(t_data *data)
{
	data->ray->hit = 0;
	data->ray->side = 0;
	data->ray->map_x = 0;
	data->ray->map_y = 0;
	data->ray->step_x = 0;
	data->ray->step_y = 0;
	data->ray->line_h = 0;
	data->ray->draw_end = 0;
	data->ray->draw_start = 0;
	data->ray->pwd = 0;
	data->ray->ddy = 0;
	data->ray->ddx = 0;
	data->ray->sdx = 0;
	data->ray->sdy = 0;
	data->ray->time = 0;
	data->ray->old_time = 0;
	data->ray->dir_x = 0;
	data->ray->dir_y = 0;
	data->ray->old_x = 0;
	data->ray->old_y = 0;
	data->ray->angle = 0;
	data->ray->plane_x = 0;
	data->ray->plane_y = 0.66;
	data->ray->camera_x = 0;
}

void	init_null_4(t_data *data)
{
	data->player->change = 0;
	data->player->dir = 0;
	data->player->x = 0;
	data->player->y = 0;
	data->player->old_x = 0;
	data->player->old_y = 0;
	data->player->dir_x = 0;
	data->player->dir_y = 0;
	data->player->old_dx = 0;
	data->player->old_dy = 0;
	data->player->angle = 0;
}

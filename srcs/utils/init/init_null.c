/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:58:10 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/31 14:10:17 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	init_null_1(t_data *data)
{
	data->filled = 0;
	data->c_color = 0;
	data->f_color = 0;
	data->map = NULL;
	data->c->r = -1;
	data->c->g = -1;
	data->c->b = -1;
	data->f->r = -1;
	data->f->g = -1;
	data->f->b = -1;
	data->map_fd->begin = 0;
	data->map_fd->ended = 0;
	data->map_fd->height = 0;
	data->map_fd->width = 0;
	data->mlx->ptr = NULL;
	data->mlx->win = NULL;
	data->mlx->img = NULL;
	data->mlx->addr = NULL;
	data->mlx->bpp = 0;
	data->mlx->line_length = 0;
	data->mlx->endian = 0;
}

void	init_null_2(t_data *data)
{
	data->key->w_pressed = 0;
	data->key->s_pressed = 0;
	data->key->a_pressed = 0;
	data->key->d_pressed = 0;
	data->key->la_pressed = 0;
	data->key->lr_pressed = 0;
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
	data->ray->text_x = 0;
	data->ray->text_y = 0;
	data->ray->text_pos = 0;
	data->ray->text_num = 0;
	data->ray->draw_end = 0;
	data->ray->draw_start = 0;
	data->ray->pwd = 0;
	data->ray->ddy = 0;
	data->ray->ddx = 0;
	data->ray->sdx = 0;
	data->ray->sdy = 0;
	data->ray->step = 0;
	data->ray->dir_x = 0;
	data->ray->dir_y = 0;
	data->ray->wall_x = 0;
	data->ray->camera_x = 0;
}

void	init_null_4(t_data *data)
{
	int	i;

	i = -1;
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
	while (++i < 4)
	{
		data->texture[i].path = NULL;
		data->texture[i].addr = NULL;
		data->texture[i].img = NULL;
		data->texture[i].h = 0;
		data->texture[i].w = 0;
		data->texture[i].bpp = 0;
		data->texture[i].line_length = 0;
		data->texture[i].endian = 0;
	}
}

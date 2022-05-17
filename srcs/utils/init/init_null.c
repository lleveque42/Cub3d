/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:58:10 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/17 12:26:16 by lleveque         ###   ########.fr       */
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
	data->player->dir = 0;
	data->player->x = 0;
	data->player->y = 0;
	data->player->old_x = 0;
	data->player->old_y = 0;
}

void	init_null_2(t_data *data)
{
	data->key->w_pressed = 0;;
	data->key->s_pressed = 0;
	data->key->a_pressed = 0;
	data->key->d_pressed = 0;
	data->key->la_pressed = 0;
	data->key->lr_pressed = 0;
	data->mlx->ptr = NULL;
	data->mlx->win = NULL;
	data->mlx->img = NULL;
	data->ray->angle = 0;
	data->ray->dof = 0;
	data->ray->mp = 0;
	data->ray->mx = 0;
	data->ray->my = 0;
	data->ray->r = 0;
	data->ray->x = 0;
	data->ray->y = 0;
	data->ray->xo = 0;
	data->ray->yo = 0;
}


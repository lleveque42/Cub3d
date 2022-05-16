/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:03:37 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/16 19:46:02 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_forward(t_data *data)
{
	data->player->x += data->player->dx * 0.01;
	data->player->y += data->player->dy * 0.01;
}

void	move_backward(t_data *data)
{
	data->player->x -= data->player->dx * 0.01;
	data->player->y -= data->player->dy * 0.01;
}

void	move_right(t_data *data)
{
	(void)data;
	// data->player->x += data->player->dx * 0.01;
	// data->player->y += data->player->dy * 0.01;
}

void	move_left(t_data *data)
{
	(void)data;
	// data->player->x -= data->player->dx * 0.01;
	// data->player->y += data->player->dy * 0.01;
}

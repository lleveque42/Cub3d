/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:36:40 by arudy             #+#    #+#             */
/*   Updated: 2022/05/24 10:37:01 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

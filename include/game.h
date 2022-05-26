/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:03:58 by arudy             #+#    #+#             */
/*   Updated: 2022/05/26 17:41:07 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "struct.h"

int		key_event(int keycode, t_data *data);
int		get_color(t_data *data, int x);
int		key_release(int keycode, t_data *data);
void	game(t_data *data);
void	get_pos(t_data *data);
void	move_left(t_data *data);
void	calc_steps(t_data *data);
void	move_right(t_data *data);
void	rotate_left(t_data *data);
void	rotate_right(t_data *data);
void	get_textures(t_data *data);
void	move_forward(t_data *data);
void	move_backward(t_data *data);
void	ray_dir(t_data *data, int x);
void	calc_line_height(t_data *data);
void	ray_hit_wall_pos(t_data *data);

#endif

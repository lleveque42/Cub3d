/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:03:58 by arudy             #+#    #+#             */
/*   Updated: 2022/05/25 14:32:58 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "struct.h"

void	game(t_data *data);
void	get_pos(t_data *data);
void	move_left(t_data *data);
void	calc_steps(t_data *data);
void	move_right(t_data *data);
void	rotate_left(t_data *data);
void	rotate_right(t_data *data);
void	move_forward(t_data *data);
void	move_backward(t_data *data);
void	ray_dir(t_data *data, int x);
int		key_event(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);

#endif

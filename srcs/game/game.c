/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:02:26 by arudy             #+#    #+#             */
/*   Updated: 2022/05/13 14:10:01 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	game(t_data *data)
{
	data->mlx->m = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->m, 500, 500, "QubtroiD");
	mlx_loop(data->mlx->m);
}

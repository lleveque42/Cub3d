/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:22:44 by arudy             #+#    #+#             */
/*   Updated: 2022/05/24 12:38:34 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx->addr + (y * data->mlx->line_length)
		+ (x * data->mlx->bpp / 8);
	*(unsigned int *)dst = color;
}

void	pixel_put2(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx->addr2 + (y * data->mlx->line_length)
		+ (x * data->mlx->bpp / 8);
	*(unsigned int *)dst = color;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:22:44 by arudy             #+#    #+#             */
/*   Updated: 2022/05/24 18:03:37 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

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

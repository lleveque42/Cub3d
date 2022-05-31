/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:34:37 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/31 15:05:51 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	clear_mlx(t_data *data)
{
	int	i;

	i = -1;
	if (data->mlx->ptr && data->mlx->win)
	{
		mlx_clear_window(data->mlx->ptr, data->mlx->win);
		mlx_destroy_window(data->mlx->ptr, data->mlx->win);
	}
	if (data->mlx->ptr && data->mlx->img)
		mlx_destroy_image(data->mlx->ptr, data->mlx->img);
	while (++i < 4)
	{
		if (data->texture[i].img)
			mlx_destroy_image(data->mlx->ptr, data->texture[i].img);
	}
	if (data->mlx->ptr)
	{
		mlx_destroy_display(data->mlx->ptr);
		free(data->mlx->ptr);
	}
}

int	ft_exit_esc(t_data *data)
{
	clear_mlx(data);
	free_all(data);
	exit(0);
}

int	ft_exit(t_data *data, char *msg, int value)
{
	clear_mlx(data);
	ft_exit_message(msg, data, 1);
	free_all(data);
	exit(value);
}

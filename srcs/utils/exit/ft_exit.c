/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:34:37 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/16 12:11:23 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	ft_exit_esc(t_data *data)
{
	if (data->mlx->ptr && data->mlx->win)
	{
		mlx_clear_window(data->mlx->ptr, data->mlx->win);
		mlx_destroy_window(data->mlx->ptr, data->mlx->win);
	}
	if (data->mlx->ptr && data->mlx->img)
		mlx_destroy_image(data->mlx->ptr, data->mlx->img);
	if (data->mlx->ptr)
	{
		mlx_destroy_display(data->mlx->ptr);
		free(data->mlx->ptr);
	}
	free_all(data);
	exit(0);
}

int	ft_exit(t_data *data, char *msg)
{
	if (data->mlx->ptr && data->mlx->win)
	{
		mlx_clear_window(data->mlx->ptr, data->mlx->win);
		mlx_destroy_window(data->mlx->ptr, data->mlx->win);
	}
	if (data->mlx->ptr && data->mlx->img)
		mlx_destroy_image(data->mlx->ptr, data->mlx->img);
	if (data->mlx->ptr)
	{
		mlx_destroy_display(data->mlx->ptr);
		free(data->mlx->ptr);
	}
	ft_exit_message(msg, data, 1);
	free_all(data);
	exit(0);
}

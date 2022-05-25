/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:34:37 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/25 11:46:41 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	ft_exit_esc(t_data *data)
{
	if (data->mlx->ptr && data->mlx->win)
	{
		mlx_clear_window(data->mlx->ptr, data->mlx->win);
		mlx_destroy_window(data->mlx->ptr, data->mlx->win);
		mlx_clear_window(data->mlx->ptr2, data->mlx->win2); // temp
		mlx_destroy_window(data->mlx->ptr2, data->mlx->win2); // temp
	}
	if (data->mlx->ptr && data->mlx->img)
	{
		mlx_destroy_image(data->mlx->ptr, data->mlx->img);
		mlx_destroy_image(data->mlx->ptr2, data->mlx->img2); // temp
	}
	if (data->mlx->ptr)
	{
		mlx_destroy_display(data->mlx->ptr);
		mlx_destroy_display(data->mlx->ptr2); // temp
		free(data->mlx->ptr);
		free(data->mlx->ptr2); // temp
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
		mlx_clear_window(data->mlx->ptr2, data->mlx->win2); // temp
		mlx_destroy_window(data->mlx->ptr2, data->mlx->win2); // temp
	}
	if (data->mlx->ptr && data->mlx->img)
	{
		mlx_destroy_image(data->mlx->ptr, data->mlx->img);
		mlx_destroy_image(data->mlx->ptr2, data->mlx->img2); // temp
	}
	if (data->mlx->ptr)
	{
		mlx_destroy_display(data->mlx->ptr);
		mlx_destroy_display(data->mlx->ptr2); // temp
		free(data->mlx->ptr);
		free(data->mlx->ptr2); // temp
	}
	ft_exit_message(msg, data, 1);
	free_all(data);
	exit(0);
}

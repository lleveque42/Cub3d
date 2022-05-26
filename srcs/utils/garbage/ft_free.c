/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:57:22 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/26 14:36:34 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	ft_free_garbage(t_garbage *garbage)
{
	t_garbage	*tmp;

	while (garbage && garbage->next)
	{
		tmp = garbage;
		if (garbage && garbage->ptr)
			free(garbage->ptr);
		garbage = garbage->next;
		free(tmp);
	}
	if (garbage)
	{
		free(garbage->ptr);
		free(garbage);
	}
}

void	remove_garbage(void *ptr, t_data *data)
{
	t_garbage	*tmp;

	while (data->garbage && data->garbage->ptr != ptr)
		data->garbage = data->garbage->next;
	tmp = data->garbage;
	if (data->garbage && !data->garbage->prev && !data->garbage->next)
		return (free(tmp));
	if (data->garbage && !data->garbage->prev)
		data->garbage->next->prev = NULL;
	else if (data->garbage && !data->garbage->next)
	{
		data->garbage->prev->next = NULL;
		data->garbage = data->garbage->prev;
	}
	if (data->garbage && data->garbage->prev && data->garbage->next)
	{
		data->garbage->prev->next = data->garbage->next;
		data->garbage->next->prev = data->garbage->prev;
	}
	if (data->garbage && data->garbage->next)
		data->garbage = data->garbage->next;
	free(tmp);
	while (data->garbage && data->garbage->prev)
		data->garbage = data->garbage->prev;
}

void	ft_free(void *ptr, t_data *data)
{
	free(ptr);
	remove_garbage(ptr, data);
}

void	free_all(t_data *data)
{
	close(data->in_fd);
	if (data->texture->no->fd > 0)
		close(data->texture->no->fd);
	if (data->texture->so->fd > 0)
		close(data->texture->so->fd);
	if (data->texture->ea->fd > 0)
		close(data->texture->ea->fd);
	if (data->texture->we->fd > 0)
		close(data->texture->we->fd);
	ft_free_garbage(data->garbage);
	free(data);
}

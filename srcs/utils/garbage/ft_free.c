/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:57:22 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/30 10:49:42 by lleveque         ###   ########.fr       */
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
	ft_free_garbage(data->garbage);
	free(data);
}

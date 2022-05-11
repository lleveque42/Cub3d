/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:20:03 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/11 11:28:30 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/cub3d.h"

t_data	*init_data(char *input)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		ft_putstr_fd("Error\ncub3d: can't malloc data\n", 2);
		exit(EXIT_FAILURE);
	}
	data->garbage = malloc(sizeof(t_garbage));
	if (!data->garbage)
	{
		ft_putstr_fd("Error\ncub3d: can't malloc data\n", 2);
		free(data);
		exit(EXIT_FAILURE);
	}
	data->garbage->ptr = NULL;
	return (data);
}


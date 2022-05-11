/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:20:03 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/11 15:13:23 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	open_map_error(char *msg, t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	free_all(data);
	exit(1);
}

void	open_map(char *input, t_data *data)
{
	int		i;
	int		j;
	char	*to_find;

	i = ft_strlen(input) - 1;
	j = 0;
	to_find = "buc.";
	if (i + 1 == 0)
		open_map_error("No input file", data);
	while (j < 4)
	{
		if (to_find[j++] != input[i--])
			open_map_error("Must be a .cub file", data);
	}
	data->in_fd = open(input, O_RDONLY);
	if (data->in_fd < 0)
	{
		ft_putstr_fd("Error\n", 2);
		perror(input);
		free_all(data);
		exit(1);
	}
}

t_data	*init_data(char *input)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		ft_putstr_fd("Error\ncan't malloc data\n", 2);
		exit(EXIT_FAILURE);
	}
	data->garbage = malloc(sizeof(t_garbage));
	if (!data->garbage)
	{
		ft_putstr_fd("Error\ncan't malloc data\n", 2);
		free(data);
		exit(EXIT_FAILURE);
	}
	data->garbage->ptr = NULL;
	open_map(input, data);
	data->filename = ft_strdup(input, data);
	data->map = NULL;
	return (data);
}

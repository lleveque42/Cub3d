/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:09:01 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/11 22:11:57 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_data(t_data *data)
{
	printf("\n----------    DATA   ----------\n\n");
	printf("filename = %s\n", data->filename);
	if (data->map)
	{
		printf("\n----------    MAP    ----------\n\n");
		for (int i = 0; data->map[i]; i++)
			printf("map[%d] = %s\n", i, data->map[i]);
	}
	printf("\n----------  TEXTURE  ----------\n\n");
	printf("no_path = %s\n", data->texture->no_path);
	printf("so_path = %s\n", data->texture->so_path);
	printf("ea_path = %s\n", data->texture->ea_path);
	printf("we_path = %s\n", data->texture->we_path);
	printf("\n----------  FLOOR   ----------\n\n");
	printf("R = %d G = %d B = %d\n", data->texture->f->r,
		data->texture->f->g, data->texture->f->b);
	printf("\n---------- CEILING  ----------\n\n");
	printf("R = %d G = %d B = %d\n", data->texture->c->r,
		data->texture->c->g, data->texture->c->b);
}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	if (ac != 2 || !envp[0])
		return (0);
	data = init_data(av[1]);
	if (parsing(data))
		return (1);
	print_data(data);
	free_all(data);
	return (0);
}

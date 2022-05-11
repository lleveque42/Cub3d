/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:09:01 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/11 16:23:47 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	if (ac != 2 || !envp[0])
		return (0);
	data = init_data(av[1]);
	if (parsing(data))
		return (1);
	free_all(data);
	return (0);
}

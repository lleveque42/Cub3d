/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:09:01 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/11 11:07:10 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	if (ac != 1 || !envp[0])
		return (0);
	data = init_data(data);
	if (!parsing(av[1], data))
		return (0);
	return (0);
}

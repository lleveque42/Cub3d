/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:28:30 by arudy             #+#    #+#             */
/*   Updated: 2022/05/11 16:29:40 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_texture(char *buff, t_data *data)
{
	if (!ft_strncmp(buff, "NO ", 3))
		printf("NO\n");
	if (!ft_strncmp(buff, "SO ", 3))
		printf("SO\n");
	if (!ft_strncmp(buff, "WE ", 3))
		printf("WE\n");
	if (!ft_strncmp(buff, "EA ", 3))
		printf("EA\n");
	if (!ft_strncmp(buff, "C ", 2))
		printf("C\n");
	if (!ft_strncmp(buff, "F ", 2))
		printf("F\n");
	(void)data;
	return (0);
}

void	scan_buff(t_data *data, char *buff)
{
	is_texture(buff, data);
}

void	fill_map(t_data *data)
{
	char	*buff;

	while (1)
	{
		buff = get_next_line(data->in_fd, data);
		if (!buff)
			break ;
		scan_buff(data, buff);
		ft_free(buff, data);
	}
	ft_free(buff, data);
}

int	parsing(t_data *data)
{
	fill_map(data);
	return (0);
}

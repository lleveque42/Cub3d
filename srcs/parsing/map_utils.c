/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:13:42 by lleveque          #+#    #+#             */
/*   Updated: 2022/06/01 12:00:29 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	dup_map(t_data *data)
{
	int	j;

	j = 0;
	while (data->map[j])
	{
		if (data->map_fd->width < (int)ft_strlen(data->map[j]))
			data->map_fd->width = ft_strlen(data->map[j]);
		j++;
	}
	j = -1;
	while (data->map[++j])
		data->map[j] = ft_strdup_bzero(data->map[j], data);
}

int	check_wall_only(char **s, int x)
{
	int	y;

	y = 0;
	while (s[x][y])
	{
		if (!(s[x][y] == ' ' || s[x][y] == '1' || s[x][y] == '\n'))
			return (1);
		y++;
	}
	return (0);
}

int	check_wall(char **s, int x, int y)
{
	if (!s[x - 1][y])
		return (1);
	if (s[x - 1][y] == ' ')
		return (1);
	if (s[x + 1][y] == ' ')
		return (1);
	if (s[x][y + 1] == ' ')
		return (1);
	if (s[x][y - 1] == ' ')
		return (1);
	return (0);
}

int	check_map_line(char *buff, t_data *data)
{
	int	i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		while (buff[i] && buff[i] == ' ')
			i++;
		if (buff[i] != '1')
			ft_exit_message("Map is invalid", data, 1);
		while (buff[i] && (buff[i] == '1' || buff[i] == '0' || buff[i] == 'N'
				|| buff[i] == 'E' || buff[i] == 'S' || buff[i] == 'W'))
			i++;
		if (buff[i - 1] && buff[i - 1] != '1')
			ft_exit_message("Map is invalid", data, 1);
	}
	if (buff[i] && buff[i] != '\n')
		ft_exit_message("Map is invalid", data, 1);
	return (0);
}

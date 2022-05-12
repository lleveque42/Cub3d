/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:58:41 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/12 15:19:33 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_wall_only(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (!(s[i] == ' ' || s[i] == '1'))
			return (1);
		i++;
	}
	return (0);
}

int	check_wall(char **s, int x, int y, t_data *data)
{
	if (y != 0 && s[y - 1][x])
	{
		if (s[y - 1][x] != ' ' && s[y - 1][x] != '1')
			return (1);
		if (s[y - 1][x + 1] && s[y - 1][x + 1] != ' ' && s[y - 1][x + 1] != '1')
			return (1);
	}
	if (y != data->map_fd->height - 1 && s[y + 1][x])
	{
		if (s[y + 1][x] != ' ' && s[y + 1][x] != '1')
			return (1);
		if (s[y + 1][x + 1] && s[y + 1][x + 1] != ' ' && s[y + 1][x + 1] != '1')
			return (1);
	}
	if (y != 0 && s[y - 1][x] && x > 0)
		if (s[y - 1][x - 1] && s[y - 1][x - 1] != ' ' && s[y - 1][x - 1] != '1')
			return (1);
	if (x > 0 && y != data->map_fd->height)
		if (s[y + 1][x - 1] && s[y + 1][x - 1] != ' ' && s[y + 1][x - 1] != '1')
			return (1);
	if (x > 0 && s[y][x - 1] && s[y][x - 1] != ' ' && s[y][x - 1] != '1')
		return (1);
	if (s[y][x] && s[y][x + 1] && s[y][x + 1] != ' ' && s[y][x + 1] != '1')
		return (1);
	return (0);
}

int	check_line(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		if (!ft_is_whitespace(buff[i]))
			return (1);
		i++;
	}
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

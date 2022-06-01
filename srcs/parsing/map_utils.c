/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:13:42 by lleveque          #+#    #+#             */
/*   Updated: 2022/06/01 02:39:28 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	del_new_line(t_data *data, int y)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	dest = NULL;
	if (!data->map[y])
		return ;
	while (data->map[y][i])
	{
		if (data->map[y][i] == '\n')
		{
			dest = ft_strldup(data->map[y], ft_strlen(data->map[y]), data);
			ft_free(data->map[y], data);
			data->map[y] = dest;
			break ;
		}
		i++;
	}
	len = ft_strlen(data->map[y]);
	if (len > data->map_fd->width)
		data->map_fd->width = len;
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

int	check_wall(char **s, int x, int y, t_data *data)
{
	if (x != 0 && s[x - 1][y])
	{
		if (s[x - 1][y] != ' ' && s[x - 1][y] != '1')
			return (1);
	}
	if (x != data->map_fd->height - 1 && s[x + 1][y])
	{
		if (s[x + 1][y] != ' ' && s[x + 1][y] != '1')
			return (1);
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

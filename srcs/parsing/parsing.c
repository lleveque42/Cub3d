/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:28:30 by arudy             #+#    #+#             */
/*   Updated: 2022/06/01 12:03:28 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	scan_buff(t_data *data, char *buff)
{
	if (!data->filled && !textures_all_filled(data))
	{
		while (*buff && ft_is_whitespace(*buff))
			buff++;
		if (is_texture(buff, data))
			ft_exit_invalid_file(data->filename, " is invalid", data, 1);
		data->map_fd->begin++;
	}
	else if (data->map_fd->height == 0)
	{
		while (*buff && ft_is_whitespace(*buff))
			buff++;
		if (*buff && *buff != '\n' && !check_map_line(buff, data))
			data->map_fd->height++;
		else
			data->map_fd->begin++;
	}
	else if (!check_line(buff) && !data->map_fd->ended)
		data->map_fd->ended = 1;
	else if ((check_line(buff) && data->map_fd->ended)
		|| check_map_line(buff, data))
		ft_exit_message("Map is invalid", data, 1);
	else if (!data->map_fd->ended)
		data->map_fd->height++;
}

void	fill_data(t_data *data)
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
	close(data->in_fd);
}

void	fill_map(t_data *data)
{
	char	*buff;
	int		i;
	int		j;

	i = -1;
	j = -1;
	data->in_fd = open(data->filename, O_RDONLY);
	if (data->in_fd < 0)
	{
		ft_putstr_fd("Error\n", 2);
		perror(data->filename);
		free_all(data);
		exit(EXIT_FAILURE);
	}
	while (++i < data->map_fd->begin)
	{
		buff = get_next_line(data->in_fd, data);
		if (!buff)
			break ;
		ft_free(buff, data);
	}
	while (++j < data->map_fd->height)
		data->map[j] = get_next_line(data->in_fd, data);
	data->map[j] = NULL;
	dup_map(data);
}

void	scan_map(char **s, t_data *data)
{
	int	x;
	int	y;

	x = -1;
	if (!s[0])
		ft_exit_message("No map found", data, 1);
	if (check_wall_only(s, 0))
		ft_exit_message("Map is invalid", data, 1);
	while (s[++x])
	{
		y = -1;
		if (!s[x + 1])
			break ;
		while (s[x][++y])
		{
			if (s[x][y] == '0')
				if (check_wall(s, x, y))
					ft_exit_message("Map is invalid", data, 1);
			if (s[x][y] == 'N' || s[x][y] == 'S' || s[x][y] == 'W'
				|| s[x][y] == 'E')
				find_player_data(s, x, y, data);
		}
	}
	if (check_wall_only(s, x))
		ft_exit_message("Map is invalid", data, 1);
}

int	parsing(t_data *data)
{
	fill_data(data);
	if (!textures_all_filled(data) || open_textures(data))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(data->filename, 2);
		ft_putstr_fd(" file not valid\n", 2);
	}
	data->map = ft_malloc(sizeof(char *) * (data->map_fd->height + 1), data);
	fill_map(data);
	scan_map(data->map, data);
	if (!data->player->dir)
		ft_exit_message("Need a player position", data, 1);
	return (0);
}

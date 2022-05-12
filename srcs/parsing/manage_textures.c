/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:58:44 by arudy             #+#    #+#             */
/*   Updated: 2022/05/12 18:58:46 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	textures_all_filled(t_data *data)
{
	if (data->texture->no_path == NULL)
		return (0);
	if (data->texture->so_path == NULL)
		return (0);
	if (data->texture->ea_path == NULL)
		return (0);
	if (data->texture->we_path == NULL)
		return (0);
	if (data->texture->c->r == -1)
		return (0);
	if (data->texture->c->g == -1)
		return (0);
	if (data->texture->c->b == -1)
		return (0);
	if (data->texture->f->r == -1)
		return (0);
	if (data->texture->f->g == -1)
		return (0);
	if (data->texture->f->b == -1)
		return (0);
	data->filled = 1;
	return (1);
}

char	*manage_texture(char *buff, char *id, int n, t_data *data)
{
	int		i;
	size_t	size;

	i = 0;
	size = 0;
	while (i++ < n)
		buff++;
	while (*buff && ft_is_whitespace(*buff))
		buff++;
	if (!*buff || *buff == '\n')
		ft_exit_texture_error(id, " is invalid in file", data, 1);
	i = 0;
	while (buff[i] && (ft_isalpha(buff[i]) || ft_isdigit(buff[i])
			|| buff[i] == '.' || buff[i] == '/' || buff[i] == '_'))
	{
		i++;
		size++;
	}
	while (buff[i] && buff[i] != '\n')
	{
		if (!ft_is_whitespace(buff[i]))
			ft_exit_texture_error(id, " is invalid in file", data, 1);
		i++;
	}
	return (ft_strldup(buff, size + 1, data));
}

int	is_texture(char *buff, t_data *data)
{
	if (!ft_strncmp(buff, "NO ", 3))
		data->texture->no_path = manage_texture(buff, "NO", 3, data);
	else if (!ft_strncmp(buff, "SO ", 3))
		data->texture->so_path = manage_texture(buff, "SO", 3, data);
	else if (!ft_strncmp(buff, "WE ", 3))
		data->texture->we_path = manage_texture(buff, "WE", 3, data);
	else if (!ft_strncmp(buff, "EA ", 3))
		data->texture->ea_path = manage_texture(buff, "EA", 3, data);
	else if (!ft_strncmp(buff, "C ", 2))
		manage_colors(buff, 2, 'C', data);
	else if (!ft_strncmp(buff, "F ", 2))
		manage_colors(buff, 2, 'F', data);
	else if (!check_line(buff))
		return (0);
	else
		return (1);
	return (0);
}

void	check_texture_extension(char *file, t_data *data)
{
	int		i;
	int		j;
	char	*to_find;

	i = ft_strlen(file) - 1;
	j = 0;
	to_find = "mpx.";
	if (i + 1 == 0)
		ft_exit_invalid_file(file, " Must be a .xpm", data, 1);
	while (j < 4)
	{
		if (to_find[j++] != file[i--])
			ft_exit_invalid_file(file, " Must be a .xpm", data, 1);
	}
}

int	open_textures(t_data *data)
{
	check_texture_extension(data->texture->no_path, data);
	check_texture_extension(data->texture->so_path, data);
	check_texture_extension(data->texture->ea_path, data);
	check_texture_extension(data->texture->we_path, data);
	data->texture->no_fd = open(data->texture->no_path, O_RDONLY);
	data->texture->so_fd = open(data->texture->so_path, O_RDONLY);
	data->texture->ea_fd = open(data->texture->ea_path, O_RDONLY);
	data->texture->we_fd = open(data->texture->we_path, O_RDONLY);
	if (data->texture->no_fd < 0)
		ft_exit_perror(data->texture->no_path, data, 1);
	if (data->texture->so_fd < 0)
		ft_exit_perror(data->texture->so_path, data, 1);
	if (data->texture->ea_fd < 0)
		ft_exit_perror(data->texture->ea_path, data, 1);
	if (data->texture->we_fd < 0)
		ft_exit_perror(data->texture->we_path, data, 1);
	return (0);
}

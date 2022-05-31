/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:58:44 by arudy             #+#    #+#             */
/*   Updated: 2022/05/31 13:47:12 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	textures_all_filled(t_data *data)
{
	if (data->texture[0].path == NULL)
		return (0);
	if (data->texture[1].path == NULL)
		return (0);
	if (data->texture[2].path == NULL)
		return (0);
	if (data->texture[3].path == NULL)
		return (0);
	if (data->c->r == -1)
		return (0);
	if (data->c->g == -1)
		return (0);
	if (data->c->b == -1)
		return (0);
	if (data->f->r == -1)
		return (0);
	if (data->f->g == -1)
		return (0);
	if (data->f->b == -1)
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
		data->texture[0].path = manage_texture(buff, "NO", 3, data);
	else if (!ft_strncmp(buff, "SO ", 3))
		data->texture[1].path = manage_texture(buff, "SO", 3, data);
	else if (!ft_strncmp(buff, "WE ", 3))
		data->texture[2].path = manage_texture(buff, "WE", 3, data);
	else if (!ft_strncmp(buff, "EA ", 3))
		data->texture[3].path = manage_texture(buff, "EA", 3, data);
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
	check_texture_extension(data->texture[0].path, data);
	check_texture_extension(data->texture[1].path, data);
	check_texture_extension(data->texture[2].path, data);
	check_texture_extension(data->texture[3].path, data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:58:44 by arudy             #+#    #+#             */
/*   Updated: 2022/05/12 10:56:12 by arudy            ###   ########.fr       */
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

void	manage_colors(char *buff, int n, char c, t_data *data)
{
	int		i;
	char	**rgb;

	i = 0;
	while (i++ < n)
		buff++;
	while (*buff && ft_is_whitespace(*buff))
		buff++;
	rgb = ft_split(buff, ',', data);
	if (check_rgb(rgb, c, data))
		ft_exit_rgb_error(c, " is invalid in file", data, 1);
	if (c == 'C')
	{
		data->texture->c->r = ft_atoi(rgb[0]);
		data->texture->c->g = ft_atoi(rgb[1]);
		data->texture->c->b = ft_atoi(rgb[2]);
	}
	else
	{
		data->texture->f->r = ft_atoi(rgb[0]);
		data->texture->f->g = ft_atoi(rgb[1]);
		data->texture->f->b = ft_atoi(rgb[2]);
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:58:44 by arudy             #+#    #+#             */
/*   Updated: 2022/05/11 18:57:17 by arudy            ###   ########.fr       */
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
	// if (data->texture->c->r == -1)
	// 	return (0);
	// if (data->texture->c->g == -1)
	// 	return (0);
	// if (data->texture->c->b == -1)
	// 	return (0);
	// if (data->texture->f->r == -1)
	// 	return (0);
	// if (data->texture->f->g == -1)
	// 	return (0);
	// if (data->texture->f->b == -1)
	// 	return (0);
	return (1);
}

char	*manage_texture(char *buff, int n, t_data *data)
{
	int		i;
	size_t	size;
	char	*s;

	i = 0;
	size = 0;
	while (i++ < n)
		buff++;
	while (ft_is_whitespace(*buff))
		buff++;
	i = 0;
	while (ft_isalpha(buff[i]) || ft_isdigit(buff[i]) || buff[i] == '.'
			|| buff[i] == '/' || buff[i] == '_')
	{
		i++;
		size++;
	}
	size++;
	s = ft_malloc(sizeof(char *) * (size + 1), data);
	if(ft_strlcpy(s, buff, size))
		printf("strlcpy error lol\n");
	return (s);
}
	// checker si buff de partout ?
	// checker return de strlcpy ?
	// leaks ?

void	is_texture(char *buff, t_data *data)
{
	if (!ft_strncmp(buff, "NO ", 3))
		data->texture->no_path = manage_texture(buff, 3, data);
	if (!ft_strncmp(buff, "SO ", 3))
		data->texture->so_path = manage_texture(buff, 3, data);
	if (!ft_strncmp(buff, "WE ", 3))
		data->texture->we_path = manage_texture(buff, 3, data);
	if (!ft_strncmp(buff, "EA ", 3))
		data->texture->ea_path = manage_texture(buff, 3, data);
	if (!ft_strncmp(buff, "C ", 2))
		printf("C\n");
		// manage_texture(buff, 2, data->texture->c, data);
	if (!ft_strncmp(buff, "F ", 2))
		printf("F\n");
		// manage_texture(buff, 2, data->texture->f, data);
	(void)data;
}

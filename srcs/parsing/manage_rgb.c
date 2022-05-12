/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:08:07 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/12 12:09:26 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_rgb_value(char **rgb, char c, t_data *data)
{
	int	i;
	int	len;

	i = 0;
	while (rgb[i])
	{
		len = 0;
		while (rgb[i][len] && ft_isdigit(rgb[i][len]))
			len++;
		if (len > 3 || (len == 3 && ft_atoi(rgb[i]) > 255))
			ft_exit_rgb_error(c, " is invalid in file, RGB colors in range \
[0, 255]", data, i);
		i++;
	}
	return (0);
}

int	check_rgb(char **rgb, char c, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (rgb[++i])
	{
		j = 0;
		while (i < 2 && rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]))
				return (1);
			j++;
		}
		while (i == 2 && rgb[i][j] && ft_isdigit(rgb[i][j]))
			j++;
		while (i == 2 && rgb[i][j] && rgb[i][j] != '\n')
		{
			if (!ft_is_whitespace(rgb[i][j]))
				return (1);
			j++;
		}
		if (i > 2 || (i == 2 && !ft_isdigit(rgb[i][0])))
			return (1);
	}
	return (check_rgb_value(rgb, c, data));
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

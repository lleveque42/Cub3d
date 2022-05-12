/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:58:41 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/12 11:57:10 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

int	check_map_line(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		while (buff[i] && ft_is_whitespace(buff[i]))
			i++;
		if (buff[i] != '1')
			return (1);
		while (buff[i] && (buff[i] == '1' || buff[i] == '0' || buff[i] == 'N'
				|| buff[i] == 'E' || buff[i] == 'S' || buff[i] == 'W'))
			i++;
		if (buff[i - 1] && buff[i - 1] != '1')
			return (1);
	}
	if (buff[i] && buff[i] != '\n')
		return (1);
	return (0);
}

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

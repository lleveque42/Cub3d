/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:11:09 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/11 15:08:48 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*str_to_out(char *str, t_data *data)
{
	size_t	i;
	size_t	len;
	char	*out;

	i = 0;
	len = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\0')
		out = ft_malloc(sizeof(char) * (len + 1), data);
	if (str[len] == '\n')
		out = ft_malloc(sizeof(char) * (len + 2), data);
	if (!out)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
	{
		out[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		out[i] = '\n';
	out[i] = '\0';
	return (out);
}

char	*next_str(char *str, t_data *data)
{
	char	*out;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		ft_free(str, data);
		return (NULL);
	}
	out = ft_malloc(sizeof(char) * (ft_strlen(str) - i + 1), data);
	if (!out)
		return (NULL);
	while (str[i++] != '\0')
	{
		out[j] = str[i];
		j++;
	}
	out[j] = '\0';
	ft_free(str, data);
	return (out);
}

char	*read_line(int fd, char *str, t_data *data)
{
	int		count;
	char	*buff;

	count = 1;
	buff = ft_malloc(sizeof(char) * 1 + 1, data);
	if (!buff)
		return (NULL);
	while (!(ft_strchr(str, '\n')) && count > 0)
	{
		count = read(fd, buff, 1);
		if (count < 1)
			break ;
		buff[count] = '\0';
		str = ft_strjoin(str, buff, data);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd, t_data *data)
{
	char		*out;
	static char	*str;

	if (fd < 0)
		return (NULL);
	if (!str)
	{
		str = ft_malloc(sizeof(char) * 1, data);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	str = read_line(fd, str, data);
	if (!str)
		return (NULL);
	out = str_to_out(str, data);
	str = next_str(str, data);
	return (out);
}

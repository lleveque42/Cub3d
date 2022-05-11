/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:11:09 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/20 12:00:24 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_to_out(char *str)
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
		out = malloc(sizeof(char) * (len + 1));
	if (str[len] == '\n')
		out = malloc(sizeof(char) * (len + 2));
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

char	*next_str(char *str)
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
		free(str);
		return (NULL);
	}
	out = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!out)
		return (NULL);
	while (str[i++] != '\0')
	{
		out[j] = str[i];
		j++;
	}
	out[j] = '\0';
	free(str);
	return (out);
}

char	*read_line(int fd, char *str)
{
	int		count;
	char	*buff;

	count = 1;
	buff = malloc(sizeof(char) * 1 + 1);
	if (!buff)
		return (NULL);
	while (!(ft_strchr(str, '\n')) && count > 0)
	{
		count = read(fd, buff, 1);
		if (count < 1)
			break ;
		buff[count] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*out;
	static char	*str;

	if (fd < 0)
		return (NULL);
	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	str = read_line(fd, str);
	if (!str)
		return (NULL);
	out = str_to_out(str);
	str = next_str(str);
	return (out);
}

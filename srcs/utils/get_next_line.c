/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:11:09 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/11 22:13:27 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_trim_stat(char *s, t_data *data)
{
	size_t	i;
	size_t	j;
	char	*dst;

	i = 0;
	j = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\0')
		return (ft_free(s, data), NULL);
	dst = ft_malloc (sizeof(char) * (ft_strlen(s) - i + 1), data);
	i++;
	while (s[i] != '\0')
		dst[j++] = s[i++];
	dst[j] = '\0';
	ft_free(s, data);
	return (dst);
}

char	*make_line(char *stat, t_data *data)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (stat[i] == '\0')
		return (NULL);
	while (stat[i] != '\0' && stat[i] != '\n')
		i++;
	if (stat[i] == '\0')
		line = ft_malloc (sizeof(char) * (i + 1), data);
	else
		line = ft_malloc (sizeof(char) * (i + 2), data);
	while (stat[j] != '\0' && stat[j] != '\n')
	{
		line[j] = stat[j];
		j++;
	}
	if (stat[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*read_line(int fd, char *stat, t_data *data)
{
	int			count;
	char		*buff;

	count = 1;
	buff = ft_malloc (sizeof(char) * 2, data);
	while (ft_strchr(stat, '\n') == 0 && count > 0)
	{
		count = read(fd, buff, 1);
		if (count < 0)
			break ;
		buff[count] = '\0';
		stat = ft_strjoin(stat, buff, data);
	}
	ft_free(buff, data);
	return (stat);
}

char	*get_next_line(int fd, t_data *data)
{
	static char	*stat;
	char		*line;

	if (!stat)
	{
		stat = ft_malloc(sizeof(char) * 1, data);
		stat[0] = '\0';
	}
	stat = read_line(fd, stat, data);
	if (!stat)
		return (NULL);
	line = make_line(stat, data);
	stat = ft_trim_stat(stat, data);
	return (line);
}

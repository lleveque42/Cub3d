/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:12:40 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/11 13:31:31 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	ft_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*out;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	out = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!out)
	{
		free(s1);
		return (NULL);
	}
	while (s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	while (s2[j])
		out[i++] = s2[j++];
	out[i] = '\0';
	free(s1);
	return (out);
}

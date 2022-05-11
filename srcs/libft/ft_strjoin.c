/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:15:34 by arudy             #+#    #+#             */
/*   Updated: 2022/05/11 15:11:10 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_strjoin(char *s1, char *s2, t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	total_len;
	char	*dst;

	i = 0;
	j = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	dst = ft_malloc(sizeof(char) * (total_len + 1), data);
	while (s1 && s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
		dst[i++] = s2[j++];
	dst[i] = '\0';
	ft_free(s1, data);
	return (dst);
}

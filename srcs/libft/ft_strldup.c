/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:23:28 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/11 23:59:33 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_strldup(char *s, size_t size, t_data *data)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (size == 0)
		return (NULL);
	dest = ft_malloc(sizeof(char) * (size + 1), data);
	while (s && s[i] && i < size - 1)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

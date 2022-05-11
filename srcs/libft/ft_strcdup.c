/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:28:09 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/11 15:11:10 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_strcdup(char *s, char c, t_data *data)
{
	size_t	i;
	size_t	size;
	char	*dest;

	i = 0;
	size = 0;
	while (s && s[size] && s[size] != c)
		size++;
	dest = ft_malloc(sizeof(char) * (size + 1), data);
	while (s && s[i] && s[i] != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

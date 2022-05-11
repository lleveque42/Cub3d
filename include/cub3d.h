/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:09:54 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/11 11:19:05 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "parsing.h"
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "../mlx/mlx_int.h"

typedef struct s_data		t_data;
typedef struct s_garbage	t_garbage;

struct	s_garbage
{
	struct s_garbage	*prev;
	void				*ptr;
	struct s_garbage	*next;
};

struct	s_color
{
	int	r;
	int	g;
	int	b;
};

struct	s_data
{
	t_garbage	*garbage;
};

#endif

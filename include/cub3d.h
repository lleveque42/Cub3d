/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:09:54 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/31 15:16:48 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include "game.h"
# include "libft.h"
# include "utils.h"
# include "struct.h"
# include "parsing.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

// # define MOVE_SPEED 0.0002
// # define ROT_SPEED 0.001
// # define MOVE_SPEED			0.015 // LOUIS
// # define ROT_SPEED			0.015 // LOUIS
// # define MOVE_SPEED			0.2 // LOUIS VALGRIND
// # define ROT_SPEED			0.2 // LOUIS VALGRIND

# define SCREEN_W	1200
# define SCREEN_H	900
# define PI			3.1415926535
# define MOVE_SPEED	0.06
# define ROT_SPEED	0.06

#endif

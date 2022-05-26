/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:09:54 by lleveque          #+#    #+#             */
/*   Updated: 2022/05/26 11:10:49 by arudy            ###   ########.fr       */
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

// # define SPEED_TEST 0.0002
// # define ROT_SPEED 0.001

// # define RES				1200
# define SCREEN_W			1200
# define SCREEN_H			900
# define PI					3.1415926535
// # define SPEED_TEST			0.015 // LOUIS
// # define ROT_SPEED			0.015 // LOUIS
// # define SPEED_TEST			0.2 // LOUIS VALGRIND
// # define ROT_SPEED			0.2 // LOUIS VALGRIND
# define SPEED_TEST			0.06 // Ecole
# define ROT_SPEED			0.06 // Ecole
# define RED				0x00FF7F7F
# define REDDD				0x99605c
# define WHITE				0x00FFFFFF
# define BLACK				0x00000000
# define GREY				0x007F7F7F
# define BLUE				0x000000FF
# define TILE_SIZE			100

#endif

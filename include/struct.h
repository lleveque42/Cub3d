/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:05:31 by arudy             #+#    #+#             */
/*   Updated: 2022/05/19 11:13:45 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_mlx		t_mlx;
typedef struct s_key		t_key;
typedef struct s_ray		t_ray;
typedef struct s_data		t_data;
typedef struct s_color		t_color;
typedef struct s_map_fd		t_map_fd;
typedef struct s_player		t_player;
typedef struct s_texture	t_texture;
typedef struct s_garbage	t_garbage;

struct	s_data
{
	int			in_fd;
	int			filled;
	int			win_width;
	int			win_height;
	char		**map;
	char		*m;
	char		*filename;
	t_mlx		*mlx;
	t_key		*key;
	t_ray		*ray;
	t_player	*player;
	t_map_fd	*map_fd;
	t_texture	*texture;
	t_garbage	*garbage;
};

struct s_key
{
	int	w_pressed;
	int	s_pressed;
	int	a_pressed;
	int	d_pressed;
	int	la_pressed;
	int	lr_pressed;
};

struct s_mlx
{
	int		bpp;
	int		bpp2;
	int		line_length;
	int		line_length2;
	int		endian;
	int		endian2;
	void	*ptr;
	void	*ptr2;
	void	*win;
	void	*win2;
	void	*img;
	void	*img2;
	char	*addr;
	char	*addr2;
};

struct s_ray
{
	int		hit;
	int		side;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	ddy;
	double	ddx;
	double	sdy;
	double	sdx;
	double	time;
	double	dir_x;
	double	dir_y;
	double	old_x;
	double	old_y;
	double	angle;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	old_time;
};

struct s_player
{
	int		change;
	char	dir;
	double	x;
	double	y;
	double	old_x;
	double	old_y;
	double	dir_x;
	double	dir_y;
	double	old_dx;
	double	old_dy;
	double	angle;
};

struct s_map_fd
{
	int	begin;
	int	ended;
	int	height;
	int	width;
};

struct	s_texture
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		no_fd;
	int		so_fd;
	int		we_fd;
	int		ea_fd;
	t_color	*c;
	t_color	*f;
};

struct	s_color
{
	int	r;
	int	g;
	int	b;
};

struct	s_garbage
{
	struct s_garbage	*prev;
	void				*ptr;
	struct s_garbage	*next;
};

#endif

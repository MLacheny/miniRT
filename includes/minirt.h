/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:13:35 by mlacheny          #+#    #+#             */
/*   Updated: 2020/10/18 17:33:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINIRT_H
#	define MINIRT_H

#include "../minilibx/mlx.h"
#include "../minilibx/mlx_int.h"
#include <X11/Xlib.h>
#include <math.h>
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include "get_next_line.h"

typedef struct	s_coord
{
	int x;
	int y;
	int z;
}				t_coord;

typedef struct	s_orien
{
	float	rx;
	float	ry;
	float	rz;
}				t_orien;

typedef	struct	s_color
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
}				t_color;

typedef struct	s_cam
{
	t_coord			coord;
	t_orien			orien;
	int				fov;
	struct s_cam	*next;
}				t_cam;

typedef struct	s_lum_amb
{
	float	strenght;
	t_color	color;
}				t_lum_amb;

typedef struct	s_res
{
	int x;
	int y;
}				t_res;

typedef	struct	s_light
{
	t_coord			coord;
	float			strenght;
	t_color			color;
	struct s_light	*next;
}				t_light;

typedef struct	s_obj
{
	int				id;
	void			*type;
	struct s_obj	*next;
}				t_obj;

typedef	struct	s_sp
{
	t_coord	coord;
	t_color	color;
	float	diam;
}				t_sp;

typedef	struct	s_plane
{
	t_coord	coord;
	t_color	color;
	t_orien	orien;
}				t_plane;

typedef	struct	s_carre
{
	t_coord	coord;
	t_color	color;
	t_orien	orien;
	float	size;
}				t_carre;

typedef	struct	s_cylin
{
	t_coord	coord;
	t_color	color;
	t_orien	orien;
	float	diam;
	float	height;
}				t_cylin;

typedef	struct	s_trian
{
	t_coord	coord[3];
	t_color	color;
}				t_trian;

typedef struct	s_scene
{
	t_res		res;
	t_lum_amb	lum_amb;
	t_cam		*cam;
	t_light		*light;
	t_obj		*objs;
}				t_scene;

#	endif

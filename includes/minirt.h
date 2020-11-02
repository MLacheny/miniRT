/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:13:35 by mlacheny          #+#    #+#             */
/*   Updated: 2020/11/02 16:59:47 by mlacheny         ###   ########.fr       */
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
	float x;
	float y;
	float z;
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
}				t_cam;

typedef struct	s_lum_amb
{
	float	stren;
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
	float			stren;
	t_color			color;
}				t_light;

typedef struct	s_obj
{
	int				id;
	void			*type;
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
	t_list		*cam;
	t_list		*light;
	t_list		*objs;
}				t_scene;

int				fill_scene(t_scene *scene, int *fd, int argc, char **argv);
int				handle_err(int argc, char **argv);
int				is_sp(char c);
int				valid_res(char *str, int *is_R);
int				valid_amb(char *str, int *is_A);
int				valid_cam(char *str);
int				valid_light(char *str);
int				valid_sphere(char *str);
int				valid_plane(char *str);
int				valid_squarre(char *str);
int				valid_cylindre(char *str);
int				valid_triangle(char *str);
int				valid_coord(char **str, t_coord *coord);
int				valid_orient(char **str, t_orien *orien);
int				valid_spacing(char **str);
int				valid_color(char **str, t_color *color);
int				ft_atocolor(char **str, unsigned char *p);
int				ft_atof(char **str, float *f);
int				ft_atoint(char **str);
int				new_res(t_scene *scene, char *str);
int				new_amb(t_scene *scene, char *str);
int				new_cam(t_scene *scene, char *str);
t_color			set_color(unsigned char R, unsigned char G, unsigned char B);
t_orien			set_orien(float rx, float ey, float rz);
t_coord			set_coord(float x, float y, float z);
t_scene			def_scene(void);

#	endif

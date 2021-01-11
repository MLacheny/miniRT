/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:13:35 by mlacheny          #+#    #+#             */
/*   Updated: 2021/01/06 15:55:30 by mlacheny         ###   ########.fr       */
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
	double x;
	double y;
	double z;
}				t_coord;

typedef struct	s_orien
{
	double	rx;
	double	ry;
	double	rz;
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
	t_list			*obj;
	double			tra[4][4];
}				t_cam;

typedef struct	s_lum_amb
{
	double	stren;
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
	double			stren;
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
	double	diam;
	t_color	color;
}				t_sp;

typedef	struct	s_plane
{
	t_coord	coord;
	t_orien	orien;
	t_color	color;
}				t_plane;

typedef	struct	s_carre
{
	t_coord	coord;
	t_orien	orien;
	double	size;
	t_color	color;
}				t_carre;

typedef	struct	s_cy
{
	t_coord	coord;
	t_orien	orien;
	double	d;
	double	h;
	t_color	color;
}				t_cy;

typedef	struct	s_tr
{
	t_coord	coord[3];
	t_color	color;
}				t_tr;

typedef struct	s_scene
{
	t_res		res;
	t_lum_amb	lum_amb;
	t_list		*cam;
	t_list		*light;
	t_list		*objs;
}				t_scene;
//					./pars
//						  /parsing.c
int				handle_err(int argc, char **argv);
//						  /fill_scene.c
int				fill_scene(t_scene *scene, int *fd, int argc, char **argv);
//						  /valid_arg.c
int				valid_res(char *str, int *is_R);
int				valid_amb(char *str, int *is_A);
int				valid_cam(char *str);
int				valid_light(char *str);
int				valid_sphere(char *str);
//						  /valid_arg2.c
int				valid_plane(char *str);
int				valid_squarre(char *str);
int				valid_cylindre(char *str);
int				valid_triangle(char *str);
//						  /valid_param.c
int				is_sp(char c);
int				valid_spacing(char **str);
int				valid_color(char **str, t_color *color);
int				valid_coord(char **str, t_coord *coord);
int				valid_orient(char **str, t_orien *orien);
//						  /ft_atonum.c
int				ft_atocolor(char **str, unsigned char *p);
int				ft_atof(char **str, double *f);
int				ft_atoint(char **str);
//						  /fill_arg.c
int				new_res(t_scene *scene, char *str);
int				new_amb(t_scene *scene, char *str);
int				new_cam(t_scene *scene, char *str);
int				new_light(t_scene *scene, char *str);
int				new_sphere(t_scene *scene, char *str);
//						  /fill_arg2.c
int				new_plane(t_scene *scene, char *str);
int				new_carre(t_scene *scene, char *str);
int				new_cy(t_scene *scene, char *str);
int				new_tr(t_scene *scene, char *str);
//						  /vect_op.c
t_orien			to_norm(t_orien o);
//					/structs
//							/disp_arg.c
void			display_scene(t_scene scene);
void			display_res(t_res res);
void			display_lumamb(t_lum_amb lum_amb);
void			display_cams(t_list *cam);
void			display_lights(t_list *light);
//							/disp_objs.c
void			display_objs(t_list *obj);
void			display_sphere(t_sp sp);
void			display_plane(t_plane pl);
void			display_carre(t_carre sq);
void			display_cy(t_cy cy);
void			display_tr(t_tr tr);
//							/set_structs.c
t_color			set_color(unsigned char R, unsigned char G, unsigned char B);
t_orien			set_orien(double rx, double ey, double rz);
t_coord			set_coord(double x, double y, double z);
t_scene			def_scene(void);
//					/rotations
//						  	  /transfo_mat.c
void			fill_mat_cam(t_cam *cam);
t_coord			coord_transfo(t_coord v1, double m21[4][4]);
t_orien			orien_transfo(t_orien v1, double m21[4][4]);
//							  /objtocam.c
void			objtocam(t_scene *scene);
//					/intersections
//								  /obj_inter.c
//								  /ray_gen.c
t_orien			gen_ray(t_res res, t_cam cam, int index);

#	endif

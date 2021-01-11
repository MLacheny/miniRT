/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objtocam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 14:15:14 by mlacheny          #+#    #+#             */
/*   Updated: 2021/01/05 17:20:52 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	*tr_sp(t_cam cam, t_list *o)
{
	t_obj	*obj;
	t_sp	*sp_c;

	if (!(obj = malloc(sizeof(*obj))))
		return (0);
	if (!(sp_c = malloc(sizeof(*sp_c))))
		return (0);
	*sp_c = *((t_sp *)((t_obj *)o->content)->type);
	sp_c->coord = coord_transfo(sp_c->coord, cam.tra);
	obj->id = 1;
	obj->type = sp_c;
	return (obj);
}

t_obj	*tr_pl(t_cam cam, t_list *o)
{
	t_obj	*obj;
	t_plane	*pl_c;

	if (!(obj = malloc(sizeof(*obj))))
		return (0);
	if (!(pl_c = malloc(sizeof(*pl_c))))
		return (0);
	*pl_c = *((t_plane *)((t_obj *)o->content)->type);
	pl_c->coord = coord_transfo(pl_c->coord, cam.tra);
	pl_c->orien = orien_transfo(pl_c->orien, cam.tra);
	obj->id = 2;
	obj->type = pl_c;
	return (obj);
}

t_obj	*tr_sq(t_cam cam, t_list *o)
{
    t_obj	*obj;
    t_carre	*sp_c;

    if (!(obj = malloc(sizeof(*obj))))
        return (0);
    if (!(sp_c = malloc(sizeof(*sp_c))))
        return (0);
    *sp_c = *((t_carre *)((t_obj *)o->content)->type);
    sp_c->coord = coord_transfo(sp_c->coord, cam.tra);
    sp_c->orien = orien_transfo(sp_c->orien, cam.tra);
    obj->id = 3;
    obj->type = sp_c;
    return (obj);
}

t_obj	*tr_cy(t_cam cam, t_list *o)
{
	t_obj	*obj;
	t_cy	*cy_c;

	if (!(obj = malloc(sizeof(*obj))))
		return (0);
	if (!(cy_c = malloc(sizeof(*cy_c))))
		return (0);
	*cy_c = *((t_cy *)((t_obj *)o->content)->type);
	cy_c->coord = coord_transfo(cy_c->coord, cam.tra);
	cy_c->orien = orien_transfo(cy_c->orien, cam.tra);
	obj->id = 4;
	obj->type = cy_c;
	return (obj);
}

t_obj	*tr_tr(t_cam cam, t_list *o)
{
	t_obj	*obj;
	t_tr	 *tr_c;

	if (!(obj = malloc(sizeof(*obj))))
		return (0);
	if (!(tr_c = malloc(sizeof(*tr_c))))
		return (0);
	*tr_c = *((t_tr *)((t_obj *)o->content)->type);
	tr_c->coord[0] = coord_transfo(tr_c->coord[0], cam.tra);
	tr_c->coord[1] = coord_transfo(tr_c->coord[1], cam.tra);
	tr_c->coord[2] = coord_transfo(tr_c->coord[2], cam.tra);
	obj->id = 5;
	obj->type = tr_c;
	return (obj);
}

void	objtocam(t_scene *scene)
{
	t_list	*next_obj;
	t_list	*next_cam;
	t_cam	*p_cam;

	next_cam = scene->cam;
	next_obj = scene->objs;
	while (next_cam)
	{
		p_cam = ((t_cam *)next_cam->content);
		while (next_obj)
		{
			if (((t_obj *)next_obj->content)->id == 1)
				ft_lstadd_back(&p_cam->obj, ft_lstnew(tr_sp(*p_cam, next_obj)));
			if (((t_obj *)next_obj->content)->id == 2)
				ft_lstadd_back(&p_cam->obj, ft_lstnew(tr_pl(*p_cam, next_obj)));
			if (((t_obj *)next_obj->content)->id == 3)
				ft_lstadd_back(&p_cam->obj, ft_lstnew(tr_sq(*p_cam, next_obj)));
			if (((t_obj *)next_obj->content)->id == 4)
				ft_lstadd_back(&p_cam->obj, ft_lstnew(tr_cy(*p_cam, next_obj)));
			if (((t_obj *)next_obj->content)->id == 5)
				ft_lstadd_back(&p_cam->obj, ft_lstnew(tr_tr(*p_cam, next_obj)));
			next_obj = next_obj->next;
		}
		next_cam = next_cam->next;
		next_obj = scene->objs;
	}
}

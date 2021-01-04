/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objtocam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 14:15:14 by mlacheny          #+#    #+#             */
/*   Updated: 2021/01/04 10:50:34 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	*tr_sp(t_scene scene)
{
	t_obj	*obj;
	t_sp	*sp;

	
}

t_list	*objtocam(t_scene *scene)
{
	t_list	*next_obj;
	t_list	*next_cam;
	t_cam	*p_cam;

	next_cam = scene->cam;
	next_obj = scene->obj;
	while (next_cam)
	{
		p_cam = ((*t_cam)next_cam->content);
		while (next_obj)
		{
			if (((t_obj)next_obj->content)->id == 1)
				ft_lstadd_back(&p_cam->obj, ft_lstnew(tr_sp()));
			next_obj = next_obj->next_obj;
		}
		next_cam = next_cam->next;
		next_obj = scene->obj;
	}
}

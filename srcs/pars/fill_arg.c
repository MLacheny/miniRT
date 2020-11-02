/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:49:18 by mlacheny          #+#    #+#             */
/*   Updated: 2020/11/02 14:27:42 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	new_res(t_scene *scene, char *str)
{
	scene->res.x = ft_atoint(&str);
	scene->res.y = ft_atoint(&str);
	return (1);
}

int	new_amb(t_scene *scene, char *str)
{
	valid_spacing(&str);
	ft_atof(&str, &scene->lum_amb.stren);
	valid_spacing(&str);
	valid_color(&str, &scene->lum_amb.color);
	return (1);
}

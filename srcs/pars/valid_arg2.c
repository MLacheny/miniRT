/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:59:39 by mlacheny          #+#    #+#             */
/*   Updated: 2020/11/03 15:35:58 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	valid_plane(char *str)
{
	t_plane pl;

	if (valid_spacing(&str) == -1)
		return (-1);
	if (valid_coord(&str, &pl.coord) == -1)
		return (-1);
	if (valid_spacing(&str) == -1)
		return (-1);
	if (valid_orient(&str, &pl.orien) == -1)
		return (-1);
	if (valid_spacing(&str) == -1)
		return (-1);
	if (valid_color(&str, &pl.color) == -1)
		return (-1);
	if (!*str)
		return (1);
	return (-1);
}

int	valid_squarre(char *str)
{
	t_carre sq;

	if (valid_spacing(&str) == -1)
		return (-1);
	if (valid_coord(&str, &sq.coord) == -1)
		return (-1);
	if (valid_spacing(&str) == -1)
		return (-1);
	if (valid_orient(&str, &sq.orien) == -1)
		return (-1);
	if (valid_spacing(&str))
		return (-1);
	if (ft_atof(&str, &sq.size) == -1 || sq.size <= 0)
		return (-1);
	if (valid_spacing(&str) == -1)
		return (-1);
	if (valid_color(&str, &sq.color) == -1)
		return (-1);
	if (*str)
		return (-1);
	return (1);
}

int	valid_cylindre(char *str)
{
	t_cy cy;

	if (valid_spacing(&str) == -1)
		return (-1);
	if (valid_coord(&str, &cy.coord) == -1)
		return (-1);
	if (valid_spacing(&str) == -1)
		return (-1);
	if (valid_orient(&str, &cy.orien) == -1)
		return (-1);
	if (valid_spacing(&str) == -1)
		return (-1);
	if (ft_atof(&str, &cy.d) == -1 || cy.d <= 0)
		return (-1);
	if (valid_spacing(&str) == -1)
		return (-1);
	if (ft_atof(&str, &cy.h) == -1 || cy.h <= 0)
		return (-1);
	if (valid_spacing(&str) == -1)
		return (-1);
	if (valid_color(&str, &cy.color) == -1)
		return (-1);
	if (*str)
		return (-1);
	return (1);
}

int	valid_triangle(char *str)
{
	t_tr	tr;
	int		i;

	i = -1;
	while (++i < 3) 
	{
		if (valid_spacing(&str))
			return (-1);
		if (valid_coord(&str, &tr.coord[i]) == -1)
			return (-1);
	}
	if (valid_spacing(&str) == -1)
		return (-1);
	if (valid_color(&str, &tr.color) == -1)
		return (-1);
	if (*str)
		return (-1);
	return (1);
}

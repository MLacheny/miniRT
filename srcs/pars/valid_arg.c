/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:53:22 by mlacheny          #+#    #+#             */
/*   Updated: 2020/10/26 13:50:09 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_sp(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int valid_int(char **str)
{
	if (!is_sp(**str))
		return (0);
	while (is_sp(*(++(*str))));
	if (!ft_isdigit(**str))
		return (0);
	while (ft_isdigit(*(++(*str))));
	return (1);
}

int	valid_res(char *str, int *is_R)
{
	if (*is_R)
		return (-1);
	*is_R = 1;
	if (!valid_int(&str))
		return (-1);
	if (!valid_int(&str))
		return (-1);
	if (*str == 0)
		return (1);
	return (-1);
}

int	valid_color(char **str)
{
	int i;

	i = 0;
	if (!is_sp(**str))
		return (0);
	while (is_sp(*(++(*str))));
	if (!ft_isdigit(**str))
		return (0);
	i = i * 10 + **str - '0';
	while (ft_isdigit(*(++(*str))))
		i = i * 10 + **str - '0';
	if (0 > i || i > 255)
		return (0);
	return (1);
}

int	valid_amb(char *str, int *is_A)
{
	(void)str;
	(void)is_A;
	return (1);	
}

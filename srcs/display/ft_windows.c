/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_windows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:43:02 by mlacheny          #+#    #+#             */
/*   Updated: 2020/12/12 14:12:01 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	compute_color(char *adr, int np, t_scene scene)
{
	
}

int	create_images(t_scene scene, void *mlx, t_list **im)
{
	void	*image;
	char	*adr;
	int		np;
	int		data[3];

	np = 0;
	while (scene->cam)
	{
		if (!(image = mlx_new_image(mlx, scene.res.x, scene.res.y)))
			return (0);
		adr = mlx_get_data_addr(image, data, data + 1, data + 2);
		while (np < scene.res.x * scene.res.y)
		{
			compute_color(adr + np * 4, np, scene);
			np++;
		}
		ft_lstadd_back(im, ft_lstnew(image));
		scene->cam = scene->cam->next;
	}
}

int	create_views(t_scene scene)
{
	void	*mlx;
	void	*win;
	t_list	*im;

	im = 0;
	if (!(mlx = mlx_init()))
		return (0);
	if (!(win = mlx_nex_window(mlx, scene.res.x, scene.res.y, "miniRT")))
		return (0);
	if (!create_images(scene, mlx, &im))
		return (0);
	return (1);
}

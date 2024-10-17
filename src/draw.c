/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitasci <mitasci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:12:19 by emgul             #+#    #+#             */
/*   Updated: 2024/10/17 18:34:25 by mitasci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

void	*check_sphere_intersection(t_ray *ray, t_minirt *minirt)
{
	int i;
	t_vector *intersection;
	void *obj;

	i = 0;
	while (minirt->scene->objects[i])
	{
		if (minirt->scene->obj_tags[i] == SPHERE)
		{
			intersection = intersect_sphere(*ray, *(t_sphere *)minirt->scene->objects[i]);
			if (intersection)
				print_vector("intersection", *intersection);
			obj = minirt->scene->objects[i];
		}
		i++;
	}
	if (intersection)
		return (obj);
	return (NULL);
}

int	get_color(int x, int y, t_minirt *minirt)
{
	t_ray *ray;
    t_sphere *sp;

	ray = send_ray_from_cam(x, y, minirt);
    sp = (t_sphere *)check_sphere_intersection(ray, minirt);
	if (sp)
		return (sp->color);
	else
		return (0x000000);
}
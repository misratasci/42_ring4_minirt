/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:08:16 by emgul             #+#    #+#             */
/*   Updated: 2024/10/08 16:06:07 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

float pythagoras(float a, float b)
{
    return sqrt(a * a + b * b);
}

float dist_from_viewport_origin(int x, int y, t_minirt *minirt)
{
    t_viewport *viewport;
	int origin_x;
	int origin_y;
    
	viewport = minirt->scene->viewport;
	origin_x = viewport->width / 2;
	origin_y = viewport->height / 2;
	return (pythagoras(fabsf((float)x - (float)origin_x), fabsf((float)y - (float)origin_y)));
}

float	dist_cam_viewport(int x, int y, t_minirt *minirt)
{
    float dist;
    float hypotenuse_len;

    dist = dist_from_viewport_origin(x, y, minirt);
    hypotenuse_len = pythagoras(dist, minirt->scene->viewport->d);
	return (hypotenuse_len);
}

t_ray *send_ray_from_cam(int x, int y, t_minirt *minirt)
{
	t_vector *point_on_viewport;
	float	t;
	t_ray	*ray;
	t_vector	*dir;

	t = dist_cam_viewport(x, y, minirt);
	point_on_viewport = get_point_on_ray(*ray, t);
	dir = subtract_vector(*point_on_viewport, *minirt->scene->camera->pos);
	ray = init_ray(*minirt->scene->camera->pos, *dir);
	printf("px: %f, py: %f, pz: %f\n", point_on_viewport->x, point_on_viewport->y, point_on_viewport->z);
	return (ray);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:27:39 by emgul             #+#    #+#             */
/*   Updated: 2024/10/03 16:14:05 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

int	dot_product(t_vector v, t_vector u)
{
    return ((v.x * u.x) + (v.y * u.y) + (v.z * u.z));
}

t_vector *cross_product(t_vector v, t_vector u)
{
    t_vector *vector;

    vector = (t_vector *)ft_calloc(sizeof(t_vector), 1);
    if (!vector)
        return (NULL);
    vector->x = (u.y * v.z) - (u.z * v.y);
    vector->y = (u.z * v.x) - (u.x * v.z);
    vector->z = (u.x * v.y) - (u.y * v.x);
    return (vector);
}

int	norm(t_vector v)
{
	return (sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}

t_vector *sum_vector(t_vector v, t_vector u)
{
    t_vector *vector;

    vector = (t_vector *)ft_calloc(sizeof(t_vector), 1);
    if (!vector)
        return (NULL);
    vector->x = v.x + u.x;
    vector->y = v.y + u.y;
    vector->z = v.z + u.z;
    return (vector);
}

t_vector	*scale_vector(t_vector v, float s)
{
	t_vector *vector;

    vector = (t_vector *)ft_calloc(sizeof(t_vector), 1);
    if (!vector)
        return (NULL);
	vector->x = s * v.x;
	vector->y = s * v.y;
	vector->z = s * v.z;
	return (vector);
}

t_vector	*get_point_on_ray(t_ray ray, float t)
{
	t_vector *v;
	t_vector *td;

	td = scale_vector(*ray.direction, t);
	v = sum_vector(*ray.origin, *td);
	free(td);
	return (v);
}

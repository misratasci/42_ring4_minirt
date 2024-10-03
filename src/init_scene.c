/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:25:11 by emgul             #+#    #+#             */
/*   Updated: 2024/10/03 15:11:42 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

t_amb_light	*init_amb_light(char **arr)
{
	t_amb_light *amb_light;
	
    amb_light = (t_amb_light *)ft_calloc(sizeof(t_amb_light), 1);
    if (!amb_light)
        return (NULL);
	amb_light->intensity = ft_atof(arr[1]);
    amb_light->color = parse_color(arr[2]);
    return (amb_light);
}

t_camera	*init_camera(char **arr)
{
	t_camera *camera;
	
    camera = (t_camera *)ft_calloc(sizeof(t_camera), 1);
    if (!camera)
        return (NULL);
    camera->pos = init_vector(arr[1]);
    camera->orientation = init_vector(arr[2]);
	camera->fov = ft_atoi(arr[3]);
    return (camera);
}

t_light	*init_light(char **arr)
{
	t_light *light;
	
    light = (t_light *)ft_calloc(sizeof(t_light), 1);
    if (!light)
        return (NULL);
    light->pos = init_vector(arr[1]);
    light->intensity = ft_atof(arr[2]);
    return (light);
}

t_plane	*init_plane(char **arr)
{
	t_plane *plane;
	
    plane = (t_plane *)ft_calloc(sizeof(t_plane), 1);
    if (!plane)
        return (NULL);
    plane->point = init_vector(arr[1]);
    plane->normal = init_vector(arr[2]);
    plane->color = parse_color(arr[3]);
    return (plane);
}

t_sphere	*init_sphere(char **arr)
{
	t_sphere *sphere;
	
    sphere = (t_sphere *)ft_calloc(sizeof(t_sphere), 1);
    if (!sphere)
        return (NULL);
    sphere->origin = init_vector(arr[1]);
    sphere->radius = ft_atof(arr[2]);
    sphere->color = parse_color(arr[3]);
    return (sphere);
}

t_cylinder	*init_cylinder(char **arr)
{
	t_cylinder *cylinder;
	
    cylinder = (t_cylinder *)ft_calloc(sizeof(t_cylinder), 1);
    if (!cylinder)
        return (NULL);
    cylinder->origin = init_vector(arr[1]);
    cylinder->axis = init_vector(arr[2]);
    cylinder->radius = atof(arr[3]);
    cylinder->height = atoi(arr[4]);
    return (cylinder);
}

static int	fill_objects(t_scene *scene, char **split)
{
	int i;
	
	if (strs_equal(split[0], "pl"))
	{
		i = 0;
		while (scene->objects[i])
			i++;
		scene->objects[i] = init_plane(split);
		scene->obj_tags[i] = PLANE;
	}
	if (strs_equal(split[0], "cy"))
	{
		i = 0;
		while (scene->objects[i])
			i++;
		scene->objects[i] = init_cylinder(split);
		scene->obj_tags[i] = CYLINDER;
	}
}

int parse_line(char *line, t_scene *scene)
{
    char **split;
	int i;

    split = ft_split_charset(line, " \t");
    if (strs_equal(split[0], "A"))
        scene->amb_light = init_amb_light(split);
	if (strs_equal(split[0], "C"))
        scene->camera = init_camera(split);
	if (strs_equal(split[0], "L"))
	{
		i = 0;
		while (scene->objects[i])
			i++;
		scene->objects[i] = init_light(split);
		scene->obj_tags[i] = LIGHT;
	}
	if (strs_equal(split[0], "sp"))
	{
		i = 0;
		while (scene->objects[i])
			i++;
		scene->objects[i] = init_sphere(split);
		scene->obj_tags[i] = SPHERE;
	}
	fill_objects(scene, split);
}

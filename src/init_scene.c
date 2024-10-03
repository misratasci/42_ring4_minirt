/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:25:11 by emgul             #+#    #+#             */
/*   Updated: 2024/10/03 14:44:24 by emgul            ###   ########.fr       */
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

int parse_line(char *line, t_scene *scene)
{
    char **split;

    split = ft_split_charset(line, " \t");
    if (strs_equal(split[0], "A"))
        scene->amb_light = init_amb_light(split);
	if (strs_equal(split[0], "C"))
        scene->camera = init_camera(split);
}

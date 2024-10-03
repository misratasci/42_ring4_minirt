/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:33:30 by emgul             #+#    #+#             */
/*   Updated: 2024/10/03 15:06:29 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"
#include "libft.h"

t_vector *init_vector(char *str)
{
	char **split;
    t_vector *v;

    v = (t_vector *)ft_calloc(sizeof(t_vector), 1);
    if (!v)
        return (NULL);
	split = ft_split(str, ',');
	v->x = ft_atof(split[0]);
    v->y = ft_atof(split[1]);
    v->z = ft_atof(split[2]);
	free_array(split);
	return (v);
}

t_scene *init_scene()
{
    t_scene *scene;

    scene = (t_scene *)ft_calloc(sizeof(t_scene), 1);
    if (!scene)
        return (NULL);
}

void fill_scene(t_minirt *minirt, t_input *input)
{
    t_scene *scene;
    
    scene = minirt->scene;
    scene->amb_light = (t_amb_light *)ft_calloc(sizeof(t_amb_light), 1);
    scene->camera = (t_camera *)ft_calloc(sizeof(t_camera), 1);
    scene->viewport = (t_viewport *)ft_calloc(sizeof(t_viewport), 1);
    scene->objects = (void **)ft_calloc(sizeof(void *), input->obj_count + 1);
    scene->obj_tags = (int *)ft_calloc(sizeof(int), input->obj_count + 1);
    if (!scene->amb_light || !scene->camera || !scene->viewport
             || !scene->objects || !scene->obj_tags)
        ft_exit("scene_malloc", -1, minirt);
}

t_minirt *init_minirt()
{
    t_minirt *minirt;
    
    minirt = (t_minirt *)ft_calloc(sizeof(t_minirt), 1);
    if (!minirt)
        ft_exit("init_minirt", -1, minirt);
	minirt->mlx = mlx_init();
	minirt->win_height = WIN_H;
	minirt->win_width = WIN_W;
	minirt->win = mlx_new_window(minirt->mlx, minirt->win_width,
			minirt->win_height, "RaRe Tracer");
	minirt->img.ptr = mlx_new_image(minirt->mlx, minirt->win_width, minirt->win_height);
	minirt->img.data = mlx_get_data_addr(minirt->img.ptr, &minirt->img.bits_per_pixel,
			&minirt->img.line_len, &minirt->img.endian);
    minirt->scene = init_scene();
    if (!minirt->scene)
        ft_exit("init_scene", -1, minirt);
    return (minirt);
}

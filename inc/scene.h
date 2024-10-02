/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:08:54 by emgul             #+#    #+#             */
/*   Updated: 2024/10/02 17:14:30 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "minirt.h"

typedef struct s_camera
{
	t_vector	pos;
	t_vector	orientation;
	int			fov;
}	t_camera;

typedef struct s_viewport
{
	float	d;
	int width;
	int height;
}	t_viewport;

typedef struct s_amb_light
{
	int			color;
	float		intensity;
}				t_amb_light;

typedef struct s_light
{
	t_vector pos;
	float intensity;
}	t_light;

typedef struct s_sphere
{
	t_vector	origin;
	int			radius;
	int			color;
}				t_sphere;

typedef struct s_plane
{
	t_vector	normal;
	int			color;

}				t_plane;

typedef struct s_cylinder
{
	t_vector	origin;
	int			radius;
	int			height;
	int			color;
}				t_cylinder;

typedef struct s_scene
{
	t_camera *camera;
	t_viewport *viewport;
	t_amb_light *amb_light;
	t_light **lights;
	void **objects;
	char **obj_tags;
}	t_scene;

#endif
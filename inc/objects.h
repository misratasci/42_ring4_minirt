/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:08:54 by emgul             #+#    #+#             */
/*   Updated: 2024/10/02 14:14:05 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "minirt.h"

typedef struct s_sphere
{
	t_vector	origin;
	int			radius;
}				t_sphere;

typedef struct s_plane
{
	t_vector	normal;

}				t_plane;

typedef struct s_cylinder
{
	t_vector	origin;
	int			radius;
	int			height;
}				t_cylinder;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:02:00 by emgul             #+#    #+#             */
/*   Updated: 2024/10/02 17:40:53 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIN_W 1200
# define WIN_H 800

#include <stdio.h>

typedef struct s_vector
{
	float x;
	float y;
	float z;
}	t_vector;

# include "scene.h"

typedef struct s_input
{
	int light_count;
    int sphere_count;
    int plane_count;
    int cylinder_count;
}	t_input;

typedef struct s_img
{
	void			*ptr;
	char			*data;
	int				bits_per_pixel;
	int				line_len;
	int				endian;
}					t_img;

typedef struct s_minirt
{
	void *mlx;
	void *win;
	int win_width;
	int win_height;
	t_img img;
	t_scene *scene;
}	t_minirt;

t_minirt *init_minirt();
int ft_exit(char *err, int exit_code, t_minirt *minirt);
int	handle_keypress(int key, t_minirt *minirt);

//utils
void	draw(t_minirt *minirt);
int is_whitespace(char c);
void	parse_input(char *input_file);
char	**ft_split_charset(char const *s, char **charset);
int	higher_len(char *str1, char *str2);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:02:00 by emgul             #+#    #+#             */
/*   Updated: 2024/10/03 15:12:15 by emgul            ###   ########.fr       */
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
	int obj_count;
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
void	draw(t_minirt *minirt);
int is_whitespace(char c);
void	parse_input(char *input_file, t_minirt *minirt);
char	**ft_split_charset(char const *s, char *charset);
int	higher_len(char *str1, char *str2);
void	free_array(char **arr);
int	count_elements(char **arr);
void	input_control(char *input_file);
void iter_lines(t_minirt *minirt, char *input_file, int (*f)(char *, void *), void *ptr);
int	strs_equal(char *a, char *b);
int parse_line(char *line, t_scene *scene);
int	create_rgb(int red, int green, int blue);
int	parse_color(char *str);
float ft_atof(const char *str);
t_vector *init_vector(char *str);
void fill_scene(t_minirt *minirt, t_input *input);

#endif
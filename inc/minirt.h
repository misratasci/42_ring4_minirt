/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:02:00 by emgul             #+#    #+#             */
/*   Updated: 2024/10/02 15:23:53 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIN_W 1200
# define WIN_H 800

typedef struct s_vector
{
	int x;
	int y;
	int z;
}	t_vector;

typedef struct s_camera
{
	t_vector pos;
}	t_camera;

typedef struct s_viewport
{
	int	d;
	int width;
	int height;
}	t_viewport;

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
}	t_minirt;

t_minirt *init_minirt();
int ft_exit(char *err, int exit_code);
void	draw(t_minirt *minirt);
int	handle_keypress(int key, t_minirt *minirt);

#endif
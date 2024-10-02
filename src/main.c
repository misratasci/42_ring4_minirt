/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:28:30 by emgul             #+#    #+#             */
/*   Updated: 2024/10/02 14:54:24 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minirt.h"
#include "mlx.h"

#include "stdlib.h"

int ft_exit(char *err, int exit_code)
{
    if (exit_code != 0)
        perror(err);
    exit(exit_code);
}

int main()
{
    t_minirt *minirt;

    minirt = init_minirt();
    printf("MISRA HELLO: %s\n", minirt->str);
    
    // mlx_loop_hook(fdf->mlx_ptr, &render, fdf);
	// mlx_hook(fdf->win_ptr, KeyPress, KeyPressMask, handle_keypress, fdf);
	// mlx_hook(fdf->win_ptr, DestroyNotify, KeyReleaseMask, exit_mlx, fdf);
	mlx_loop(minirt->mlx);

    // mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img->ptr, 0, 0);
}
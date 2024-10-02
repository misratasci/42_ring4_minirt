/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:33:30 by emgul             #+#    #+#             */
/*   Updated: 2024/10/02 14:52:53 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"
#include "libft.h"

t_minirt *init_minirt()
{
    t_minirt *minirt;
    
    minirt = (t_minirt *)ft_calloc(1, sizeof(t_minirt));
    if (!minirt)
        ft_exit("calloc", 1);
    minirt->str = ft_strdup("kek");
	minirt->mlx = mlx_init();
	minirt->win_height = WIN_H;
	minirt->win_width = WIN_W;
	minirt->mlx_win = mlx_new_window(minirt->mlx, minirt->win_width,
			minirt->win_height, "MiniRT");
    return (minirt);
}
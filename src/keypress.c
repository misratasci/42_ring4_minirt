/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:07:32 by emgul             #+#    #+#             */
/*   Updated: 2024/10/02 15:24:37 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <unistd.h>
#include <X11/keysym.h>

int	handle_keypress(int key, t_minirt *minirt)
{
    if (key == XK_Escape)
        ft_exit(NULL, 0);
	return (0);
}

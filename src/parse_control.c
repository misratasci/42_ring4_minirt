/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:57:22 by emgul             #+#    #+#             */
/*   Updated: 2024/10/03 13:05:58 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


static int	object_valid(char *str)
{
	if (ft_strncmp(str, "A", higher_len(str, "A")) == 0)
		return (1);
	if (ft_strncmp(str, "C", higher_len(str, "C")) == 0)
		return (1);
	if (ft_strncmp(str, "L", higher_len(str, "L")) == 0)
		return (1);
	if (ft_strncmp(str, "sp", higher_len(str, "sp")) == 0)
		return (1);
	if (ft_strncmp(str, "cy", higher_len(str, "cy")) == 0)
		return (1);
	if (ft_strncmp(str, "pl", higher_len(str, "pl")) == 0)
		return (1);
	return (0);
}

static int arg_count_valid(char **arr)
{
    if (ft_strncmp(arr[0], "A", higher_len(arr[0], "A")) == 0)
		return (count_elements(arr) == 3);
	if (ft_strncmp(arr[0], "C", higher_len(arr[0], "C")) == 0)
		return (count_elements(arr) == 4);
	if (ft_strncmp(arr[0], "L", higher_len(arr[0], "L")) == 0)
		return (count_elements(arr) == 4);
	if (ft_strncmp(arr[0], "sp", higher_len(arr[0], "sp")) == 0)
		return (count_elements(arr) == 4);
	if (ft_strncmp(arr[0], "cy", higher_len(arr[0], "cy")) == 0)
		return (count_elements(arr) == 5);
	if (ft_strncmp(arr[0], "pl", higher_len(arr[0], "pl")) == 0)
		return (count_elements(arr) == 4);
    return (0);
}
static int consecutive_chars(char x, char y)
{
    if (x == '.' && (y == '.' || y == ',' || y == '-'))
            return (1);
    if (x == ',' && (y == '.' || y == ','))
            return (1);
    if (x == '-' && (y == '.' || y == ',' || y == '-'))
            return (1);
    return (0);
}

static int numbers_valid(char **arr)
{
    int i;
    int j;

    i = 1;
    while (arr[i])
    {
        j = 0;
        while (arr[i][j])
        {
            if (!ft_isdigit(arr[i][j]) && !arr[i][j] == '-' && !arr[i][j] == '.' && !arr[i][j] == ',')
                return (0);
            if (consecutive_chars(arr[i][j], arr[i][j + 1]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

static int color_valid(char **arr)
{
    char *col;
    char **split;
    int i;

    if (ft_strncmp(arr[0], "A", higher_len(arr[0], "A")))
        col = arr[2];
    else if (ft_strncmp(arr[0], "L", higher_len(arr[0], "L")) 
            || ft_strncmp(arr[0], "pl", higher_len(arr[0], "pl"))
            || ft_strncmp(arr[0], "sp", higher_len(arr[0], "sp")))
        col = arr[3];
    else if (ft_strncmp(arr[0], "cy", higher_len(arr[0], "cy")))
        col = arr[5];
    else
        return (1);
    split = ft_split(col, ',');
    i = 0;
    while (split && split[i])
    {
        if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255)
            return (0);
        i++;
    }
    free_array(split);
    return (1);
}

int line_valid(char *line)
{
    char **split;

    split = ft_split_charset(line, " \t");
    if (!split)
        return (0);
	if (!object_valid(split[0]) || !arg_count_valid(split) || !numbers_valid(split) || !color_valid(split))
    {
		free_array(split);
        return (0);
    }
    return (1);
}

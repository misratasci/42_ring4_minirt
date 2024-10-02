/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:58:30 by emgul             #+#    #+#             */
/*   Updated: 2024/10/02 17:41:46 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

t_input *init_input()
{
    t_input *input;

    input = (t_input *)ft_calloc(sizeof(t_input), 1);
    if (!input)
		ft_exit("input_malloc", -1, NULL);
    return (input);
}

static void count_object(t_input *input, char *line)
{
    int i;

    i = 0;
    while(line[i] && is_whitespace(line[i]))
        i++;
    if (line[i] == 'L' && is_whitespace(line[i + 1]))
        input->light_count++;
    else if (line[i] == 's' && line[i + 1] == 'p' && is_whitespace(line[i + 2]))
        input->sphere_count++;
    else if (line[i] == 'c' && line[i + 1] == 'y' && is_whitespace(line[i + 2]))
        input->cylinder_count++;
    else if (line[i] == 'p' && line[i + 1] == 'l' && is_whitespace(line[i + 2]))
        input->plane_count++;
}

int	object_valid(char *str)
{
	if (ft_strnmcp(str, "L", higher_len(str, "L")) == 0)
		return (1);
	if (ft_strnmcp(str, "sp", higher_len(str, "sp")) == 0)
		return (1);
	if (ft_strnmcp(str, "cy", higher_len(str, "cy")) == 0)
		return (1);
	if (ft_strnmcp(str, "pl", higher_len(str, "pl")) == 0)
		return (1);
	return (0);
}

int line_valid(char *line)
{
    char **split;

    split = ft_split_charset(line, " \t");
	if (!object_valid(split[0]))
		return (0);
	// RaRe: to be continued
}

void	count_objects(t_input *input, char *input_file)
{
    char *line;
    int fd;
    
    fd = open(input_file, O_RDONLY, 0644);
    if (fd == -1)
        ft_exit(input_file, -1, NULL);
    line = get_next_line(fd);
    if (!line)
    {
        close(fd);
        ft_exit("gnl", -1, NULL);
    }
    while (line)
    {
        if (!line_valid(line))
			ft_exit("Could not parse line", -1, NULL);
        count_object(input, line);
		free(line);
		line = get_next_line(fd);
    }
    free(line);
}

void	parse_input(char *input_file)
{
	t_input *input;
	char *line;

	
	count_objects(input, input_file);
    input = init_input();
    printf("L: %i, sp: %i, pl: %i, cy: %i\n", input->light_count, input->sphere_count, input->plane_count, input->cylinder_count);
	//parse_line(line, input);
}
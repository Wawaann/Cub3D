/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:06:33 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/29 14:12:10 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

int	get_max_width(char **map)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
		i++;
	}
	return (max);
}

void	add_line_to_map(t_data *data, char *line, int *i)
{
	data->parse.map = ft_realloc(data->parse.map, *i + 1,
			sizeof(char *));
	data->parse.map[*i] = ft_strtrim(line, "\n");
	(*i)++;
}

void	test_file_is_empty(t_data *data, char *line, int fd)
{
	while (line)
	{
		if (ft_strcmp(line, "\n") != 0)
		{
			free_file(line, fd);
			exit_map(data, "Error\nMore than one map");
		}
		free(line);
		line = get_next_line(fd);
	}
}

void	read_map_lines(t_data *data, int fd, char *line)
{
	int	nl;
	int	i;

	nl = 0;
	i = 0;
	data->parse.map = ft_calloc(1, sizeof(char *));
	while (line)
	{
		if (ft_strcmp(line, "\n") != 0)
		{
			nl = 1;
			add_line_to_map(data, line, &i);
		}
		if (nl == 1 && ft_strcmp(line, "\n") == 0)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	data->parse.map = ft_realloc(data->parse.map, i + 1,
			sizeof(char *));
	data->parse.height = i;
	test_file_is_empty(data, line, fd);
}

void	get_map(t_data *data, int fd, char *line)
{
	read_map_lines(data, fd, line);
	data->parse.width = get_max_width(data->parse.map);
	test_map(data);
}

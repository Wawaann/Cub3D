/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:47:03 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/23 11:23:10 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

int	flr(float x)
{
	return ((int)floor(x));
}

void	test_ply(t_data *data, char **map)
{
	int		i;

	i = 0;
	if (!map[flr(data->ply.y) + 1]
		|| map[flr(data->ply.y) + 1][flr(data->ply.x)] == '\0'
		|| map[flr(data->ply.y) + 1][flr(data->ply.x)] == ' ')
		i = 1;
	if (!map[flr(data->ply.y)][flr(data->ply.x) + 1]
		|| map[flr(data->ply.y)][flr(data->ply.x + 1)] == '\0'
		|| map[flr(data->ply.y)][flr(data->ply.x + 1)] == ' ')
		i = 1;
	if (!map[flr(data->ply.y) - 1]
		|| map[flr(data->ply.y) - 1][flr(data->ply.x)] == '\0'
		|| map[flr(data->ply.y) - 1][flr(data->ply.x)] == ' ')
		i = 1;
	if (!map[flr(data->ply.y)][flr(data->ply.x) - 1]
		|| map[flr(data->ply.y)][flr(data->ply.x - 1)] == ' ')
		i = 1;
	if (i == 1)
	{
		free(data->map.width);
		ft_freetab((char **)data->map.map);
		exit_map(data, "Error\nPlayer is out of bounds");
	}
}

void	get_data(t_data *data, char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_param(data, fd);
	get_map(data, fd, line);
	convert_map(data, data->parse.map);
	test_ply(data, data->parse.map);
	data->path = ft_calloc(1, sizeof(t_path));
	data->path->map = cpy_map_path(data->map);
	close(fd);
}

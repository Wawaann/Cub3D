/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:44:39 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/18 14:55:48 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

// int	**get_minimap(t_data *game)
// {
// 	int	**map;
// 	int	x;
// 	int	y;
// 	int	i;
// 	int	j;
// 	int	off_x;
// 	int	off_y;

// 	map = ft_calloc(19, sizeof(int *));
// 	off_x = floor(game->ply.x) - 12;
// 	off_y = floor(game->ply.y) - 9;
// 	y = 0;
// 	while (y < 18)
// 	{
// 		map[y] = ft_calloc(25, sizeof(int));
// 		x = 0;
// 		while (x < 24)
// 		{
// 			i = y + off_y;
// 			j = x + off_x;
// 			if (i >= 0 && i < game->map.height && j >= 0
// 				&& j < game->map.width[i])
// 			{
// 				if (game->map.map[i][j] == 10)
// 					map[y][x] = 10;
// 				else if (game->map.map[i][j] >= 1)
// 					map[y][x] = 1;
// 				else if (i == floor(game->objects[1].y) && j ==
					//floor(game->objects[1].x))
// 					map[y][x] = 2;
// 				else
// 					map[y][x] = 0;
// 			}
// 			else
// 				map[y][x] = -1;
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (map);
// }

static int	get_cell_value(t_data *game, int i, int j)
{
	if (i == floor(game->objects[1].y) && j == floor(game->objects[1].x))
		return (2);
	if (game->map.map[i][j] == 10)
		return (10);
	if (game->map.map[i][j] >= 1)
		return (1);
	return (0);
}

static void	fill_minimap_row(int *row, t_data *game, int off_y, int y)
{
	int	x;
	int	i;
	int	j;

	x = 0;
	while (x < 24)
	{
		i = y + off_y;
		j = x + (floor(game->ply.x) - 12);
		if (i >= 0 && i < game->map.height && j >= 0
			&& j < game->map.width[i])
			row[x] = get_cell_value(game, i, j);
		else
			row[x] = -1;
		x++;
	}
}

int	**get_minimap(t_data *game)
{
	int	**map;
	int	y;
	int	off_y;

	map = ft_calloc(19, sizeof(int *));
	if (!map)
		return (NULL);
	off_y = floor(game->ply.y) - 9;
	y = 0;
	while (y < 18)
	{
		map[y] = ft_calloc(25, sizeof(int));
		if (!map[y])
			return (NULL);
		fill_minimap_row(map[y], game, off_y, y);
		y++;
	}
	return (map);
}

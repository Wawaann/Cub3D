/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:35:20 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/23 11:06:30 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || x >= (int)ft_strlen(map[y]))
		return ;
	if ((map[y][x] >= '1' && map[y][x] <= '9') || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	single_flood_fill(char **map, int x, int y, char ch)
{
	if (x < 0 || y < 0 || !map[y] || x >= (int)ft_strlen(map[y]))
		return ;
	if (map[y][x] == ch || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	single_flood_fill(map, x + 1, y, ch);
	single_flood_fill(map, x - 1, y, ch);
	single_flood_fill(map, x, y + 1, ch);
	single_flood_fill(map, x, y - 1, ch);
}

void	fill_map(char	**map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				flood_fill(map, j, i);
			j++;
		}
		i++;
	}
}

void	fill_single_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				single_flood_fill(map, j, i, ' ');
				return ;
			}
			j++;
		}
		i++;
	}
}

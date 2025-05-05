/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:04:02 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/18 14:41:55 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	get_door_coord(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j] != -1)
		{
			if (game->map.map[i][j] == 6)
			{
				game->door.x = j;
				game->door.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	set_door_open(t_data *game, int x, int y)
{
	if (game->map.map[y][x + 1] == 6)
		game->map.map[y][x + 1] = 0;
	else if (game->map.map[y][x - 1] == 6)
		game->map.map[y][x - 1] = 0;
	else if (game->map.map[y + 1][x] == 6)
		game->map.map[y + 1][x] = 0;
	else if (game->map.map[y - 1][x] == 6)
		game->map.map[y - 1][x] = 0;
}

void	handle_door(t_data *game)
{
	static int	x = 0;
	static int	y = 0;
	static bool	opened = false;

	if (game->keys[KEY_SPACE] && game->ply.key && !opened)
	{
		x = floor(game->ply.x);
		y = floor(game->ply.y);
		if (game->map.map[y][x + 1] == 6 || game->map.map[y][x - 1] == 6
			|| game->map.map[y + 1][x] == 6 || game->map.map[y - 1][x] == 6)
			opened = true;
	}
	if (opened)
	{
		if (game->door_frame < 9)
			game->door_frame++;
		else
		{
			opened = false;
			game->ply.key = false;
			set_door_open(game, x, y);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:47:17 by cedmarti          #+#    #+#             */
/*   Updated: 2025/04/18 14:51:30 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	draw_square(t_data *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE)
	{
		j = 0;
		while (j < TILE)
		{
			put_pixel_to_buffer(&game->mini, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	compute_angle(t_rot *rot, float angle)
{
	rot->cos_a = cos(angle + (PI / 2));
	rot->sin_a = sin(angle + (PI / 2));
}

void	compute_new_coord(t_rot *rot, int x, int y)
{
	rot->new_x = rot->cos_a * (x - 12) - rot->sin_a * (y - 12) + 12;
	rot->new_y = rot->sin_a * (x - 12) + rot->cos_a * (y - 12) + 12;
}

void	get_i_j(int **map, int *i, int *j)
{
	int	x;
	int	y;

	*i = -1;
	*j = -1;
	y = 0;
	while (y < 18)
	{
		x = 0;
		while (x < 24)
		{
			if (map[y][x] == 2)
			{
				*i = ((y + 1) * 24) + y;
				*j = ((x + 1) * 24) + x;
			}
			x++;
		}
		y++;
	}
}

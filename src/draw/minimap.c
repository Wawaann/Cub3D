/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:32:13 by cedmarti          #+#    #+#             */
/*   Updated: 2025/04/18 14:51:59 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	draw_map(t_data *game, int **map)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < 18)
	{
		j = 0;
		while (j < 24)
		{
			if (map[i][j] == -1 || map[i][j] == 10)
				color = 0x594743;
			else if (map[i][j] == 1)
				color = 0x291d20;
			else
				color = 0x7f6463;
			draw_square(game, j * (TILE + 1)
				+ 25 + (game->ply.x - floor(game->ply.x)),
				i * (TILE + 1) + 25 + (game->ply.y - floor(game->ply.y)),
				color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_data *game)
{
	int		color;
	int		x;
	int		y;

	compute_angle(&game->ply.rot, game->ply.angle);
	y = 0;
	while (y < TILE)
	{
		x = 0;
		while (x < TILE)
		{
			color = get_color_from_texture(&game->player_img, x, y);
			if (color != 0)
			{
				compute_new_coord(&game->ply.rot, x, y);
				put_pixel_to_buffer(&game->mini, round(M_WIDTH / 2)
					+ game->ply.rot.new_x + 12, round(M_HEIGHT / 2)
					+ game->ply.rot.new_y + 8, color);
			}
			x++;
		}
		y++;
	}
}

void	draw_sides(t_data *game, t_img *xpm)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < M_HEIGHT)
	{
		x = xpm->offset * M_WIDTH;
		while (x < (xpm->offset + 1) * M_WIDTH)
		{
			color = *(unsigned int *)(xpm->addr + (y * xpm->size_line + x
						* (xpm->bpp / 8)));
			if (color != 0)
				put_pixel_to_buffer(&game->mini, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_key(t_data *game, int **map)
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	color;

	get_i_j(map, &i, &j);
	if (i == -1 || j == -1)
		return ;
	y = 0;
	while (y < 24)
	{
		x = 0;
		while (x < 24)
		{
			color = get_color_from_texture(&game->mini_key[1], x, y);
			if (color != 0x000000)
				put_pixel_to_buffer(&game->mini, x + j, y + i, color);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_data *game)
{
	int	i;
	int	**map;

	map = get_minimap(game);
	clear_buffer(&game->mini);
	draw_map(game, map);
	draw_key(game, map);
	draw_sides(game, &game->wood);
	draw_player(game);
	i = 0;
	while (i < 18)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:17:54 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/18 15:20:58 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

int	get_wall_color(t_data *game, int tex_x, int tex_y)
{
	int	f_off;

	if (game->rnd.wall == 6)
	{
		f_off = game->door_frame * SIZE;
		return (get_color_from_texture(&game->wall[5], tex_x + f_off, tex_y));
	}
	if (game->rnd.side == 0)
	{
		if (game->rnd.stepx < 0)
			return (get_color_from_texture(&game->wall[game->rnd.wall - 1],
					(SIZE - 1) - tex_x, tex_y));
		else
			return (get_color_from_texture(&game->wall[game->rnd.wall - 1],
					tex_x, tex_y));
	}
	else
	{
		if (game->rnd.stepy < 0)
			return (get_color_from_texture(&game->wall[game->rnd.wall - 1],
					tex_x, tex_y));
		else
			return (get_color_from_texture(&game->wall[game->rnd.wall - 1],
					(SIZE - 1) - tex_x, tex_y));
	}
}

void	draw_texture(t_data *game, int line_height, int ray_index)
{
	t_vector	tex;
	int			y;
	int			color;
	float		step;
	float		tex_pos;

	tex.x = (int)(game->rnd.wall_hit_x * SIZE);
	y = game->rnd.starting_point;
	step = SIZE / line_height;
	tex_pos = (y - S_HEIGHT / 2 + line_height / 2) * step;
	while (y < game->rnd.end_point)
	{
		tex.y = (int)tex_pos % (int)SIZE;
		tex_pos += step;
		color = get_wall_color(game, tex.x, tex.y);
		put_pixel_to_buffer(&game->frame, ray_index, y,
			apply_fog(color, game->rnd.wall_dist));
		y++;
	}
}

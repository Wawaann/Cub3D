/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:22:41 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/18 15:20:58 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	draw_sky(t_data *game, t_fs *fs, int ray_index, int starting_point)
{
	int		i;
	int		color;

	i = 0;
	init_sky_floor(game);
	while (i < starting_point)
	{
		fs->fs_p = (S_HEIGHT / 2) - i;
		fs->fs_row_dist = (0.5 * S_HEIGHT) / fs->fs_p;
		compute_sky_floor(game, fs, ray_index);
		color = get_color_from_texture(&game->sky_img,
				fs->fs_tex_x, fs->fs_tex_y);
		color = apply_fog(color, fs->fs_row_dist);
		put_pixel_to_buffer(&game->frame, ray_index, i, color);
		i++;
	}
}

void	draw_floor(t_data *game, t_fs *fs, int ray_index, int end_point)
{
	int		i;
	int		color;

	i = end_point;
	init_sky_floor(game);
	while (i < S_HEIGHT)
	{
		fs->fs_p = i - (S_HEIGHT / 2);
		fs->fs_row_dist = (0.5 * S_HEIGHT) / fs->fs_p;
		compute_sky_floor(game, fs, ray_index);
		color = get_color_from_texture(&game->floor_img,
				fs->fs_tex_x, fs->fs_tex_y);
		color = apply_fog(color, fs->fs_row_dist);
		put_pixel_to_buffer(&game->frame, ray_index, i, color);
		i++;
	}
}

static int	calculate_next_column(int ray_index)
{
	float	next_ray_dir;
	float	ray_proj_dir;
	int		next_column;

	next_column = S_WIDTH;
	if (ray_index < S_WIDTH - 1)
	{
		next_ray_dir = 66 * (floor(0.5f * S_WIDTH) - 1 - ray_index)
			/ (S_WIDTH - 1);
		ray_proj_dir = 0.5f * tan(next_ray_dir * (PI / 180))
			/ tan(33 * (PI / 180));
		next_column = (int)round(S_WIDTH * (0.5f - ray_proj_dir));
		if (next_column < 0)
			next_column = 0;
	}
	return (next_column);
}

static void	draw_scene_column(t_data *game, int column, int line_height)
{
	draw_sky(game, &game->fs, column, game->rnd.starting_point);
	draw_texture(game, line_height, column);
	draw_floor(game, &game->fs, column, game->rnd.end_point);
	game->rnd.z_buffer[column] = game->rnd.wall_pers;
}

void	draw_column_line(t_data *game, int column, int ray_index)
{
	static int	previous_column = -1;
	int			line_height;
	int			next_column;

	next_column = calculate_next_column(ray_index);
	if (previous_column < column)
	{
		line_height = (int)(S_HEIGHT / game->rnd.wall_dist);
		game->rnd.starting_point = -line_height / 2 + S_HEIGHT / 2;
		if (game->rnd.starting_point < 0)
			game->rnd.starting_point = 0;
		game->rnd.end_point = line_height / 2 + S_HEIGHT / 2;
		if (game->rnd.end_point >= S_HEIGHT)
			game->rnd.end_point = S_HEIGHT;
		previous_column = column;
		if (previous_column == S_WIDTH - 1)
			previous_column = -1;
		draw_scene_column(game, column, line_height);
		if (next_column - column > 1)
			draw_scene_column(game, column + 1, line_height);
	}
}

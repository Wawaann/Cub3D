/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:35:39 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/18 15:20:58 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	set_var(t_data *game)
{
	if (game->rnd.ray_dirx < 0)
	{
		game->rnd.stepx = -1;
		game->rnd.sidedistx = (game->ply.x - game->rnd.mapx)
			* game->rnd.deltax;
	}
	else
	{
		game->rnd.stepx = 1;
		game->rnd.sidedistx = (game->rnd.mapx + 1.0 - game->ply.x)
			* game->rnd.deltax;
	}
	if (game->rnd.ray_diry < 0)
	{
		game->rnd.stepy = -1;
		game->rnd.sidedisty = (game->ply.y - game->rnd.mapy)
			* game->rnd.deltay;
	}
	else
	{
		game->rnd.stepy = 1;
		game->rnd.sidedisty = (game->rnd.mapy + 1.0 - game->ply.y)
			* game->rnd.deltay;
	}
}

void	init_ray_vars(t_data *game, float ray_angle)
{
	game->rnd.ray_dirx = cos(ray_angle);
	game->rnd.ray_diry = sin(ray_angle);
	game->rnd.mapx = (int)game->ply.x;
	game->rnd.mapy = (int)game->ply.y;
	game->rnd.deltax = fabs(1 / game->rnd.ray_dirx);
	game->rnd.deltay = fabs(1 / game->rnd.ray_diry);
	set_var(game);
}

void	init_sky_floor(t_data *game)
{
	game->rnd.fs_dir_x = cos(game->ply.angle);
	game->rnd.fs_dir_y = sin(game->ply.angle);
	game->rnd.fs_plane_x = -game->rnd.fs_dir_y * 0.66;
	game->rnd.fs_plane_y = game->rnd.fs_dir_x * 0.66;
}

void	compute_sky_floor(t_data *game, t_fs *fs, int ray_index)
{
	fs->fs_left_x = game->ply.x + fs->fs_row_dist
		* (game->rnd.fs_dir_x - game->rnd.fs_plane_x);
	fs->fs_left_y = game->ply.y + fs->fs_row_dist
		* (game->rnd.fs_dir_y - game->rnd.fs_plane_y);
	fs->fs_right_x = game->ply.x + fs->fs_row_dist
		* (game->rnd.fs_dir_x + game->rnd.fs_plane_x);
	fs->fs_right_y = game->ply.y + fs->fs_row_dist
		* (game->rnd.fs_dir_y + game->rnd.fs_plane_y);
	fs->fs_step_x = (fs->fs_right_x - fs->fs_left_x) / S_WIDTH;
	fs->fs_step_y = (fs->fs_right_y - fs->fs_left_y) / S_WIDTH;
	fs->fs_x = fs->fs_left_x + ray_index * fs->fs_step_x;
	fs->fs_y = fs->fs_left_y + ray_index * fs->fs_step_y;
	fs->fs_tex_x = (int)(fs->fs_x * SIZE) % (int)SIZE;
	fs->fs_tex_y = (int)(fs->fs_y * SIZE) % (int)SIZE;
}

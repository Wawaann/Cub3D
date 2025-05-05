/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:28:43 by cedmarti          #+#    #+#             */
/*   Updated: 2025/04/18 15:20:58 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	set_wall_dist(t_data *game, float ray_angle)
{
	float	angle_diff;
	float	correct_dist;

	if (game->rnd.side == 0)
	{
		game->rnd.wall_dist = (game->rnd.mapx - game->ply.x
				+ (1 - game->rnd.stepx) / 2) / game->rnd.ray_dirx;
		game->rnd.wall_hit_x = game->ply.y + game->rnd.wall_dist
			* game->rnd.ray_diry;
	}
	else
	{
		game->rnd.wall_dist = (game->rnd.mapy - game->ply.y
				+ (1 - game->rnd.stepy) / 2) / game->rnd.ray_diry;
		game->rnd.wall_hit_x = game->ply.x + game->rnd.wall_dist
			* game->rnd.ray_dirx;
	}
	game->rnd.wall_pers = game->rnd.wall_dist;
	game->rnd.wall_hit_x -= floor(game->rnd.wall_hit_x);
	angle_diff = ray_angle - game->ply.angle;
	correct_dist = game->rnd.wall_dist * cos(angle_diff);
	game->rnd.wall_dist = correct_dist;
}

void	set_side(t_data *game)
{
	if (game->rnd.sidedistx < game->rnd.sidedisty)
	{
		game->rnd.sidedistx += game->rnd.deltax;
		game->rnd.mapx += game->rnd.stepx;
		game->rnd.side = 0;
	}
	else
	{
		game->rnd.sidedisty += game->rnd.deltay;
		game->rnd.mapy += game->rnd.stepy;
		game->rnd.side = 1;
	}
}

void	cast_single_ray(t_data *game, float ray_angle, int ray_index)
{
	float	ray_dir;
	float	ray_proj_dir;
	int		column;

	game->rnd.wall = 0;
	game->rnd.side = 0;
	init_ray_vars(game, ray_angle);
	while (game->rnd.wall == 0)
	{
		set_side(game);
		if (game->map.map[game->rnd.mapy][game->rnd.mapx] > 0)
			game->rnd.wall = game->map.map[game->rnd.mapy][game->rnd.mapx];
	}
	ray_dir = 66 * (floor(0.5f * S_WIDTH) - ray_index) / (S_WIDTH - 1);
	ray_proj_dir = 0.5f * tan(ray_dir * (PI / 180)) / tan(33 * (PI / 180));
	column = (int)round(S_WIDTH * (0.5f - ray_proj_dir));
	if (column < 0)
		column = 0;
	if (game->rnd.wall)
	{
		set_wall_dist(game, ray_angle);
		draw_column_line(game, column, ray_index);
	}
}

void	cast_rays(t_data *game)
{
	int		i;
	float	fov;
	float	angle_step;
	float	ray_angle;
	float	start_angle;

	i = 0;
	fov = 66 * (PI / 180);
	angle_step = fov / S_WIDTH;
	start_angle = game->ply.angle - (fov / 2);
	game->rnd.o = 0;
	while (i < S_WIDTH)
	{
		ray_angle = start_angle + (i * angle_step);
		if (ray_angle < 0)
			ray_angle += 2 * PI;
		if (ray_angle >= 2 * PI)
			ray_angle -= 2 * PI;
		cast_single_ray(game, ray_angle, i);
		i++;
	}
}

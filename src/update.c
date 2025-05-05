/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:07:51 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/29 13:31:28 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

float	clamp(float value, float min, float max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

float	get_lowan_speed(float dist)
{
	float	min_speed;
	float	max_speed;
	float	min_dist;
	float	max_dist;
	float	t;

	min_speed = 0.055f;
	max_speed = 0.095f;
	min_dist = 10.0f;
	max_dist = 800.0f;
	t = clamp((dist - min_dist) / (max_dist - min_dist), 0.0f, 1.0f);
	return (min_speed + t * (max_speed - min_speed));
}

void	update_lwn(t_data *game)
{
	float	new_x;
	float	new_y;
	long	elapsed_time;

	new_x = game->lwn.x;
	new_y = game->lwn.y;
	game->lwn.speed = get_lowan_speed(game->lwn.dist);
	gettimeofday(&game->lwn.tv2, NULL);
	elapsed_time = (game->lwn.tv2.tv_sec - game->lwn.tv.tv_sec) * 1000000
		+ (game->lwn.tv2.tv_usec - game->lwn.tv.tv_usec);
	if (elapsed_time >= 25000 && game->lwn.active)
	{
		new_x += cos(game->lwn.angle) * game->lwn.speed;
		new_y += sin(game->lwn.angle) * game->lwn.speed;
		if (game->path->map[(int)floor(new_y)][(int)floor(game->lwn.x)] == 0)
			game->lwn.y = new_y;
		if (game->path->map[(int)floor(game->lwn.y)][(int)floor(new_x)] == 0)
			game->lwn.x = new_x;
	}
	if (elapsed_time >= 333000)
	{
		game->lwn.tv = game->lwn.tv2;
		pathfinding(game);
	}
}

void	render(t_data *game)
{
	static int	i = 0;

	if (i == 0)
	{
		game->sound[1]->use = true;
		i++;
	}
	cast_rays(game);
	draw_object(game);
	draw_hand(game);
	draw_stamina_bar(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
}

int	update_view(t_data *game)
{
	long	elapsed_time;

	gettimeofday(&game->tv2, NULL);
	elapsed_time = (game->tv2.tv_sec - game->tv.tv_sec) * 1000000
		+ (game->tv2.tv_usec - game->tv.tv_usec);
	if (elapsed_time >= FPS && game->state == 0)
	{
		handle_audio(game);
		game->tv = game->tv2;
		if (!game->keys[KEY_TAB])
		{
			handle_mouse(game);
			handle_move(game);
		}
		update_lwn(game);
		render(game);
		handle_minimap(game);
		handle_door(game);
		handle_key(game);
	}
	if (game->state > 0)
		mlx_put_image_to_window(game->mlx, game->win, game->end.img, 0, 0);
	return (0);
}

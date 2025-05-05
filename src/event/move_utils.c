/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:38:01 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/28 15:59:55 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	check_lowan(t_data *game, float new_posx, float new_posy)
{
	if (floor(game->lwn.x) == floor(new_posx)
		&& floor(game->lwn.y) == floor(new_posy))
	{
		printf("Lowan le Malicieux t'as attrappé...\n");
		game->state = 1;
		game->sound[0]->use = false;
		ma_sound_stop(game->sound[0]->sound);
		play_sound(game->sound[3]);
		set_img(game->mlx, "./assets/game_over.xpm", &game->end);
	}
	else
		game->sound[0]->use = false;
}

void	check_win(t_data *game)
{
	long	elapsed_time;

	gettimeofday(&game->t_door2, NULL);
	if (game->door.x == floor(game->ply.x)
		&& game->door.y == floor(game->ply.y))
	{
		if (game->t_door.tv_sec == -1)
			gettimeofday(&game->t_door, NULL);
	}
	if (game->t_door.tv_sec == -1)
		return ;
	elapsed_time = (game->t_door2.tv_sec - game->t_door.tv_sec) * 1000000
		+ (game->t_door2.tv_usec - game->t_door.tv_usec);
	if (elapsed_time >= 2000000)
	{
		printf("Bravo tu as echappe a Lowan le Malicieux !\n");
		game->state = 2;
		set_img(game->mlx, "./assets/you_win.xpm", &game->end);
	}
}

int	can_walk(t_data *game, float new_posx, float new_posy)
{
	int		i;
	float	dx;
	float	dy;
	float	distance_squared;
	float	min_distance;

	min_distance = 0.3f;
	if (!game->pos || !game->num_objects)
		return (1);
	i = 2;
	while (i < game->num_objects)
	{
		if (game->objects[i].show == false)
		{
			i++;
			continue ;
		}
		dx = game->pos[i - 2].x - new_posx;
		dy = game->pos[i - 2].y - new_posy;
		distance_squared = dx * dx + dy * dy;
		if (distance_squared < min_distance * min_distance)
			return (0);
		i++;
	}
	return (1);
}

void	handle_rotate(t_data *game)
{
	float	rot_speed;

	rot_speed = 0.04;
	if (game->keys[KEY_RIGHT])
		game->ply.angle += rot_speed;
	if (game->keys[KEY_LEFT])
		game->ply.angle -= rot_speed;
	if (game->ply.angle < 0)
		game->ply.angle += 2 * PI;
	if (game->ply.angle > 2 * PI)
		game->ply.angle -= 2 * PI;
}

void	move_ply(t_data *game, float *n_posx, float *n_posy)
{
	if (game->keys[KEY_A])
	{
		*n_posx += sin(game->ply.angle) * game->ply.speed;
		*n_posy -= cos(game->ply.angle) * game->ply.speed;
	}
	if (game->keys[KEY_D])
	{
		*n_posx -= sin(game->ply.angle) * game->ply.speed;
		*n_posy += cos(game->ply.angle) * game->ply.speed;
	}
	if (game->keys[KEY_W])
	{
		*n_posx += cos(game->ply.angle) * game->ply.speed;
		*n_posy += sin(game->ply.angle) * game->ply.speed;
	}
	if (game->keys[KEY_S])
	{
		*n_posx -= cos(game->ply.angle) * game->ply.speed;
		*n_posy -= sin(game->ply.angle) * game->ply.speed;
	}
}

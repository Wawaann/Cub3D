/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:20:53 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/23 18:24:27 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

static void	update_speed(t_data *game)
{
	game->ply.speed = 0;
	if (game->keys[KEY_W] || game->keys[KEY_S]
		|| game->keys[KEY_A] || game->keys[KEY_D])
		game->ply.speed += 0.08;
	if ((game->keys[KEY_W] || game->keys[KEY_S])
		&& (game->keys[KEY_A] || game->keys[KEY_D]))
		game->ply.speed -= 0.02;
}

static void	handle_sprint(t_data *game)
{
	if (game->ply.stamina <= 0)
		return ;
	game->ply.speed += SPRINT;
	game->ply.stamina -= STAMINA_DRAIN;
	if (game->ply.stamina < 0)
		game->ply.stamina = 0;
	if (game->ply.stamina == 0)
		gettimeofday(&game->ply.tv, NULL);
}

static void	handle_regen(t_data *game, struct timeval now)
{
	long	elapsed;

	if (game->ply.stamina == 0)
	{
		elapsed = now.tv_sec - game->ply.tv.tv_sec;
		if (elapsed < STAMINA_REGEN_DELAY)
		{
			game->ply.speed -= 0.02;
			return ;
		}
	}
	if (game->ply.stamina >= MAX_STAMINA)
		return ;
	if (game->ply.speed == 0 && game->ply.stamina > 0)
		game->ply.stamina += STAMINA_REGEN * 1.5;
	else
		game->ply.stamina += STAMINA_REGEN;
	if (game->ply.stamina > MAX_STAMINA)
		game->ply.stamina = MAX_STAMINA;
}

void	handle_speed(t_data *game)
{
	struct timeval	now;
	int				is_moving;

	update_speed(game);
	gettimeofday(&now, NULL);
	is_moving = game->keys[KEY_W] || game->keys[KEY_S]
		|| game->keys[KEY_A] || game->keys[KEY_D];
	if (is_moving && game->keys[KEY_SHIFT])
		handle_sprint(game);
	else
		handle_regen(game, now);
}

void	handle_move(t_data *game)
{
	float	new_posx;
	float	new_posy;

	new_posx = game->ply.x;
	new_posy = game->ply.y;
	handle_speed(game);
	move_ply(game, &new_posx, &new_posy);
	check_lowan(game, new_posx, new_posy);
	if (game->map.map[(int)floor(new_posy)][(int)floor(game->ply.x)] == 0
		&& can_walk(game, new_posx, new_posy))
		game->ply.y = new_posy;
	if (game->map.map[(int)floor(game->ply.y)][(int)floor(new_posx)] == 0
		&& can_walk(game, new_posx, new_posy))
		game->ply.x = new_posx;
	check_win(game);
}

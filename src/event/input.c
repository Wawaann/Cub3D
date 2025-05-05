/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <bigotte.ewan@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:46:16 by cedmarti          #+#    #+#             */
/*   Updated: 2025/05/05 11:04:06 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

int	key_handler(int keycode, t_data *game, bool is_pressed)
{
	if (keycode == K_ESC)
		close_win(game);
	if (keycode == K_Z)
		game->keys[KEY_W] = is_pressed;
	if (keycode == K_Q)
		game->keys[KEY_A] = is_pressed;
	if (keycode == K_S)
		game->keys[KEY_S] = is_pressed;
	if (keycode == K_D)
		game->keys[KEY_D] = is_pressed;
	if (keycode == K_M && is_pressed)
		game->keys[KEY_M] = !game->keys[KEY_M];
	if (keycode == K_LEFT)
		game->keys[KEY_LEFT] = is_pressed;
	if (keycode == K_RIGHT)
		game->keys[KEY_RIGHT] = is_pressed;
	if (keycode == K_SHIFT_L)
		game->keys[KEY_SHIFT] = is_pressed;
	if (keycode == K_A)
		game->keys[KEY_TAB] = is_pressed;
	if (keycode == K_SPACE)
		game->keys[KEY_SPACE] = is_pressed;
	return (0);
}

int	key_pressed(int keycode, t_data *data)
{
	key_handler(keycode, data, true);
	return (0);
}

int	key_released(int keycode, t_data *data)
{
	key_handler(keycode, data, false);
	return (0);
}

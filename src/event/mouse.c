/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:40:43 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/22 14:33:49 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

int	set_mouse_pos(t_data *game, int x, int y)
{
	if (x < 0 || x > S_WIDTH || y < 0 || y > S_HEIGHT)
	{
		mlx_mouse_move(game->mlx, game->win, S_WIDTH / 2, S_HEIGHT / 2);
		return (1);
	}
	return (0);
}

int	mouse_move(t_data *game, int x, int y)
{
	int			i;
	static int	last_x = S_WIDTH / 2;
	float		sensitivity;

	sensitivity = 0.003;
	i = set_mouse_pos(game, x, y);
	if (i == 0)
	{
		game->ply.angle += ((x - last_x) * sensitivity);
		last_x = x;
	}
	else
		last_x = S_WIDTH / 2;
	return (0);
}

void	handle_mouse(t_data *game)
{
	int	x;
	int	y;

	if (game->keys[KEY_M])
	{
		mlx_mouse_hide(game->mlx, game->win);
		mlx_mouse_get_pos(game->mlx, game->win, &x, &y);
		mouse_move(game, x, y);
	}
	else
	{
		mlx_mouse_show(game->mlx, game->win);
		handle_rotate(game);
	}
}

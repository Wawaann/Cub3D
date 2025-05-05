/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:06:35 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/15 14:10:14 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	handle_key(t_data *game)
{
	int	x;
	int	y;
	int	k_x;
	int	k_y;

	k_x = game->parse.key.x;
	k_y = game->parse.key.y;
	if (game->keys[KEY_SPACE])
	{
		x = floor(game->ply.x);
		y = floor(game->ply.y);
		if (k_x == x && k_y == y)
		{
			game->ply.key = true;
			game->objects[1].show = false;
		}
	}
}

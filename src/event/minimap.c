/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:07:25 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/23 12:07:54 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	handle_minimap(t_data *game)
{
	if (game->keys[KEY_TAB])
	{
		draw_minimap(game);
		mlx_put_image_to_window(game->mlx, game->win, game->mini.img,
			S_WIDTH / 2 - M_WIDTH / 2, S_HEIGHT / 2 - M_HEIGHT / 2);
	}
}

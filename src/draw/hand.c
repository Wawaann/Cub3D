/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:02:20 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/18 13:15:12 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	draw_xpm_on_frame(t_data *data, t_img *xpm, int x_off, int y_off)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HAND)
	{
		x = xpm->offset * HAND;
		while (x < (xpm->offset + 1) * HAND)
		{
			color = *(unsigned int *)(xpm->addr + (y * xpm->size_line + x
						* (xpm->bpp / 8)));
			if (color != 0)
				put_pixel_to_buffer(&data->frame, x + x_off, y + y_off, color);
			x++;
		}
		y++;
	}
}

void	increment_a(t_data *game)
{
	float	test;

	test = fabs(game->ply.th);
	if (game->ply.speed <= 0.1)
	{
		if (test * 100 != 4)
			game->ply.th = game->ply.th / 2;
		if (game->ply.a >= 1)
			game->ply.th = -game->ply.th;
		if (game->ply.a <= -1)
			game->ply.th = -game->ply.th;
	}
	else
	{
		if (test * 100 != 8)
			game->ply.th = game->ply.th * 2;
		if (game->ply.a >= 1)
			game->ply.th = -game->ply.th;
		if (game->ply.a <= -1)
			game->ply.th = -game->ply.th;
	}
	if (game->ply.speed > 0)
		game->ply.a += game->ply.th;
}

float	get_x_offset(t_data *game)
{
	float	hand_offset;
	float	x_off;

	hand_offset = 650 - (game->hand.offset * HAND);
	x_off = cos(game->ply.a * PI) * 30;
	return (x_off + hand_offset);
}

float	get_y_offset(t_data *game)
{
	float	hand_offset;
	float	y_off;

	hand_offset = S_HEIGHT - HAND + 10;
	y_off = (sin(fabs(game->ply.a) * PI) / 2) * 50;
	return (hand_offset + y_off);
}

void	draw_hand(t_data *game)
{
	int		x_off;
	int		y_off;
	long	elapsed_time;

	gettimeofday(&game->hand.tv2, NULL);
	elapsed_time = (game->hand.tv2.tv_sec - game->hand.tv.tv_sec) * 1000000
		+ (game->hand.tv2.tv_usec - game->hand.tv.tv_usec);
	if (elapsed_time >= 80000)
	{
		game->hand.tv = game->hand.tv2;
		game->hand.offset = (game->hand.offset + 1) % 4;
	}
	if (!game->keys[KEY_TAB])
		increment_a(game);
	x_off = get_x_offset(game);
	y_off = get_y_offset(game);
	draw_xpm_on_frame(game, &game->hand, x_off, y_off);
}

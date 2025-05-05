/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stamina.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:44:04 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/18 14:42:23 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	draw_rect(t_img *img, int width, uint32_t color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < width)
		{
			put_pixel_to_buffer(img, 15 + j, 15 + i, color);
			j++;
		}
		i++;
	}
}

uint32_t	get_stamina_color(float ratio)
{
	int	red;
	int	green;

	red = (int)(255 * (1 - ratio));
	green = (int)(255 * ratio);
	return ((red << 16) | (green << 8));
}

void	draw_mini_key(t_data *game)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	while (x < 57)
	{
		y = 0;
		while (y < 20)
		{
			color = get_color_from_texture(&game->mini_key[0], x, y);
			if (color != 0x000000)
			{
				put_pixel_to_buffer(&game->frame, 225 + x, 15 + y,
					color);
			}
			y++;
		}
		x++;
	}
}

void	draw_stamina_bar(t_data *game)
{
	float	stamina_ratio;
	int		stamina_width;

	stamina_ratio = game->ply.stamina / MAX_STAMINA;
	stamina_width = (int)(200 * stamina_ratio);
	draw_rect(&game->frame, 200, 0x000000);
	if (stamina_width > 0)
		draw_rect(&game->frame, stamina_width,
			get_stamina_color(stamina_ratio));
	if (game->ply.key)
	{
		draw_mini_key(game);
	}
}

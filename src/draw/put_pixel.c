/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:17:04 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/23 12:05:28 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

int	apply_fog(int color, float distance)
{
	float	brightness;
	int		r;
	int		g;
	int		b;

	brightness = 1.0 - fmin(1.0, distance / MAX_DISTANCE);
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r = (int)(r * brightness);
	g = (int)(g * brightness);
	b = (int)(b * brightness);
	return ((r << 16) | (g << 8) | b);
}

int	get_color_from_texture(t_img const *texture, int x, int y)
{
	char	*pixel;
	int		color;

	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0x000000);
	pixel = texture->addr + (y * texture->size_line + x * (texture->bpp / 8));
	color = *(uint32_t *)pixel;
	return (color);
}

void	put_pixel_to_buffer(t_img *dest, int x, int y, uint32_t pixel)
{
	char	*dst;

	if (x < 0 || x >= dest->width || y < 0 || y >= dest->height)
		return ;
	dst = dest->addr + (y * dest->size_line + x * (dest->bpp / 8));
	*(unsigned int *)dst = pixel;
}

void	clear_buffer(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			put_pixel_to_buffer(img, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

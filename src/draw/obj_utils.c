/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:35:14 by cedmarti          #+#    #+#             */
/*   Updated: 2025/04/23 17:43:52 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

static float	get_obj_distance(t_object obj, t_player ply)
{
	float	dx;
	float	dy;

	dx = obj.x - ply.x;
	dy = obj.y - ply.y;
	return (dx * dx + dy * dy);
}

int	compare_and_swap(t_object *obj1, t_object *obj2, t_player ply)
{
	t_object	tmp;

	if (get_obj_distance(*obj1, ply) < get_obj_distance(*obj2, ply))
	{
		tmp = *obj1;
		*obj1 = *obj2;
		*obj2 = tmp;
		return (1);
	}
	return (0);
}

static void	draw_object_column(t_img *img, t_object *obj, int x)
{
	int	y;
	int	color;
	int	offset;

	y = obj->start_y;
	offset = obj->texture.offset * SIZE;
	while (y < obj->end_y)
	{
		obj->tex_y = (int)obj->tex_pos % obj->texture.height;
		obj->tex_pos += obj->step;
		color = get_color_from_texture(&obj->texture,
				obj->tex_x + offset, obj->tex_y);
		if (color != 0)
			put_pixel_to_buffer(img, x, y, apply_fog(color, obj->transform_y));
		y++;
	}
}

void	activate_lwn(t_data *game, t_object *obj)
{
	if (!obj->lwn)
		return ;
	if (game->lwn.active || game->lwn.dist == 0)
		return ;
	if (obj->end_x - obj->start_x > 75 && game->lwn.dist <= 360)
	{
		game->lwn.active = true;
		game->sound[2]->use = true;
	}
}

void	draw_obj(t_data *game, t_object *obj)
{
	int	x;

	x = obj->start_x;
	while (x < obj->end_x)
	{
		obj->tex_x = (int)(256 *(x -(-obj->o_width / 2 + obj->o_screen_x))
				* SIZE / obj->o_width) / 256;
		if (obj->transform_y > 0 && x > 0 && x < S_WIDTH
			&& obj->transform_y < game->rnd.z_buffer[x])
		{
			activate_lwn(game, obj);
			obj->step = 1.0 * obj->texture.height
				/ obj->o_height;
			obj->tex_pos = (obj->start_y - S_HEIGHT / 2
					+ obj->o_height / 2) * obj->step;
			draw_object_column(&game->frame, obj, x);
		}
		x++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:01:23 by cedmarti          #+#    #+#             */
/*   Updated: 2025/04/18 15:20:58 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	sort_objects(t_object *objs, t_player ply, int num_objects)
{
	int	i;
	int	swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < num_objects - 1)
		{
			if (compare_and_swap(&objs[i], &objs[i + 1], ply))
				swap = 1;
			i++;
		}
	}
}

void	set_obj_in_space(t_object *obj, t_rnd rnd, t_player ply)
{
	float	absolute_angle;

	obj->dx = obj->x - ply.x;
	obj->dy = obj->y - ply.y;
	absolute_angle = atan2(obj->dy, obj->dx);
	obj->angle_to_ply = absolute_angle - obj->angle;
	while (obj->angle_to_ply < 0)
		obj->angle_to_ply += 2 * PI;
	while (obj->angle_to_ply >= 2 * PI)
		obj->angle_to_ply -= 2 * PI;
	obj->angle_to_ply += (PI / 8) + (PI / 2);
	obj->texture.offset = (int)((obj->angle_to_ply + (PI / 2)) / (PI / 4)) % 8;
	obj->inv_det = 1.0f / (rnd.fs_plane_x * rnd.fs_dir_y - rnd.fs_dir_x
			* rnd.fs_plane_y);
	obj->transform_x = obj->inv_det * (rnd.fs_dir_y * obj->dx
			- rnd.fs_dir_x * obj->dy);
	obj->transform_y = obj->inv_det * (-rnd.fs_plane_y * obj->dx
			+ rnd.fs_plane_x * obj->dy);
}

void	get_object_dimension(t_object *obj)
{
	obj->o_screen_x = (int)((S_WIDTH / 2) * (1 + obj->transform_x
				/ obj->transform_y));
	obj->o_height = abs((int)(S_HEIGHT / obj->transform_y));
	obj->o_width = obj->o_height;
}

void	comupte_start_end_point(t_object *obj)
{
	obj->start_y = -obj->o_height
		/ 2 + S_HEIGHT / 2;
	if (obj->start_y < 0)
		obj->start_y = 0;
	obj->end_y = obj->o_height
		/ 2 + S_HEIGHT / 2;
	if (obj->end_y > S_HEIGHT)
		obj->end_y = S_HEIGHT;
	obj->start_x = -obj->o_width
		/ 2 + obj->o_screen_x;
	if (obj->start_x < 0)
		obj->start_x = 0;
	obj->end_x = obj->o_width
		/ 2 + obj->o_screen_x;
	if (obj->end_x > S_WIDTH)
		obj->end_x = S_WIDTH;
}

void	draw_object(t_data *game)
{
	int			i;
	t_object	*objs;

	i = 0;
	game->objects[0].x = game->lwn.x;
	game->objects[0].y = game->lwn.y;
	game->objects[0].angle = game->lwn.angle;
	objs = ft_calloc(game->num_objects, sizeof(t_object));
	ft_memcpy(objs, game->objects, sizeof(t_object) * game->num_objects);
	sort_objects(objs, game->ply, game->num_objects);
	while (i < game->num_objects)
	{
		set_obj_in_space(&objs[i], game->rnd, game->ply);
		if (objs[i].transform_y <= 0 || !objs[i].show)
		{
			i++;
			continue ;
		}
		get_object_dimension(&objs[i]);
		comupte_start_end_point(&objs[i]);
		draw_obj(game, &objs[i]);
		i++;
	}
	free(objs);
}

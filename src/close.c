/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:06:46 by ebigotte          #+#    #+#             */
/*   Updated: 2025/05/05 10:55:17 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"
#include "../lib/include/miniaudio.h"

void	destroy_obj_texture(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->num_objects)
	{
		mlx_destroy_image(game->mlx, game->objects[i].texture.img);
		i++;
	}
}

void	destroy_mlx(t_data *game)
{
	int	i;

	i = 0;
	mlx_destroy_image(game->mlx, game->frame.img);
	while (game->wall[i].img)
	{
		mlx_destroy_image(game->mlx, game->wall[i].img);
		i++;
	}
	mlx_destroy_image(game->mlx, game->floor_img.img);
	mlx_destroy_image(game->mlx, game->sky_img.img);
	mlx_destroy_image(game->mlx, game->mini_key[0].img);
	mlx_destroy_image(game->mlx, game->mini_key[1].img);
	mlx_destroy_image(game->mlx, game->hand.img);
	mlx_destroy_image(game->mlx, game->mini.img);
	mlx_destroy_image(game->mlx, game->wood.img);
	mlx_destroy_image(game->mlx, game->player_img.img);
	if (game->objects)
		destroy_obj_texture(game);
	if (game->state > 0)
		mlx_destroy_image(game->mlx, game->end.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
}

void	free_data(t_data *game)
{
	ft_freetab((char **)game->map.map);
	ft_freetab((char **)game->path->map);
	ft_freetab(game->parse.walls);
	ft_freetab(game->parse.oth);
	ft_freetab(game->parse.map);
	free(game->wall);
	free(game->mini_key);
	free(game->path);
	free(game->map.width);
	free(game->parse.wall);
	if (game->objects)
		free(game->objects);
	if (game->pos)
		free(game->pos);
	free(game->mlx);
}

void	uninit_audio(t_data *game)
{
	ma_sound_stop(game->sound[0]->sound);
	ma_sound_stop(game->sound[1]->sound);
	ma_sound_stop(game->sound[2]->sound);
	ma_sound_stop(game->sound[3]->sound);
	ma_sound_uninit(game->sound[0]->sound);
	free(game->sound[0]->sound);
	free(game->sound[0]);
	ma_sound_uninit(game->sound[1]->sound);
	free(game->sound[1]->sound);
	free(game->sound[1]);
	ma_sound_uninit(game->sound[2]->sound);
	free(game->sound[2]->sound);
	free(game->sound[2]);
	ma_sound_uninit(game->sound[3]->sound);
	free(game->sound[3]->sound);
	free(game->sound[3]);
	free(game->sound);
	ma_engine_uninit(game->engine);
	free(game->engine);
}

int	close_win(t_data *game)
{
	destroy_mlx(game);
	uninit_audio(game);
	free_data(game);
	exit (0);
}

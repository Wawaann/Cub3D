/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:51:38 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/18 15:22:31 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	set_objects(t_data *game)
{
	game->objects[0].show = true;
	game->objects[0].lwn = true;
	game->objects[1].x = game->parse.key.x;
	game->objects[1].y = game->parse.key.y;
	game->objects[1].angle = PI / 2;
	game->objects[1].show = true;
	game->objects[1].lwn = false;
}

void	init_objects(t_data *game)
{
	int		i;

	i = 2;
	game->num_objects += 2;
	game->objects = ft_calloc(game->num_objects, sizeof(t_object));
	game->mini_key = ft_calloc(2, sizeof(t_img));
	set_img(game->mlx, "./assets/lowan.xpm", &game->objects[0].texture);
	set_img(game->mlx, game->parse.oth[3], &game->objects[1].texture);
	set_img(game->mlx, "./assets/mini_key.xpm", &game->mini_key[0]);
	set_img(game->mlx, "./assets/key_minimap.xpm", &game->mini_key[1]);
	set_objects(game);
	srand(time(NULL));
	while (i < game->num_objects)
	{
		game->objects[i].x = game->pos[i - 2].x;
		game->objects[i].y = game->pos[i - 2].y;
		game->objects[i].angle = fmod(abs(rand()), 2 * PI);
		game->objects[i].show = true;
		game->objects[i].lwn = false;
		set_img(game->mlx, game->parse.oth[4], &game->objects[i].texture);
		i++;
	}
}

void	set_img(void *mlx, char *asset, t_img *img)
{
	img->img = mlx_xpm_file_to_image(mlx, asset, &img->width, &img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->size_line,
			&img->endian);
	img->offset = 0;
	gettimeofday(&img->tv, NULL);
}

void	load_img(t_data *game)
{
	int	i;

	i = 0;
	game->frame.img = mlx_new_image(game->mlx, S_WIDTH, S_HEIGHT);
	game->frame.addr = mlx_get_data_addr(game->frame.img, &game->frame.bpp,
			&game->frame.size_line, &game->frame.endian);
	game->frame.width = S_WIDTH;
	game->frame.height = S_HEIGHT;
	game->mini.img = mlx_new_image(game->mlx, M_WIDTH, M_HEIGHT);
	game->mini.addr = mlx_get_data_addr(game->mini.img, &game->mini.bpp,
			&game->mini.size_line, &game->mini.endian);
	game->mini.width = M_WIDTH;
	game->mini.height = M_HEIGHT;
	game->wall = ft_calloc(game->parse.nb_walls + 1, sizeof(t_img));
	set_img(game->mlx, game->parse.oth[0], &game->floor_img);
	set_img(game->mlx, game->parse.oth[1], &game->sky_img);
	set_img(game->mlx, game->parse.oth[2], &game->hand);
	set_img(game->mlx, "./assets/wood_map.xpm", &game->wood);
	set_img(game->mlx, "./assets/player.xpm", &game->player_img);
	while (i < game->parse.nb_walls)
	{
		set_img(game->mlx, game->parse.walls[i], &game->wall[i]);
		i++;
	}
}

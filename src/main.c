/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:47:56 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/28 15:58:33 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	init_data(t_data *data)
{
	int	i;

	i = 0;
	data->parse.walls = ft_calloc(10, sizeof(char *));
	data->parse.oth = ft_calloc(6, sizeof(char *));
	data->parse.wall = ft_calloc(10, sizeof(char));
	while (i < KEY_COUNT)
	{
		data->keys[i] = false;
		i++;
	}
}

void	init_audio(t_data *game)
{
	game->engine = ft_calloc(1, sizeof(ma_engine));
	if (ma_engine_init(NULL, game->engine) != MA_SUCCESS)
		return ((void)printf("Error: engine initialization\n"));
	game->sound = ft_calloc(4, sizeof(t_audio *));
	game->sound[0] = init_sound(game->engine, "music.flac", 0.5);
	game->sound[1] = init_sound(game->engine, "TOI.flac", 0.6);
	game->sound[2] = init_sound(game->engine, "viensla.flac", 1.0);
	game->sound[3] = init_sound(game->engine, "lose.flac", 1.0);
	game->sound[0]->use = true;
}

void	run_game(t_data *game)
{
	char	*title;

	title = "La cave de Lowan";
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, S_WIDTH, S_HEIGHT, title);
	game->t_door.tv_sec = -1;
	game->door_frame = 0;
	game->state = 0;
	gettimeofday(&game->tv, NULL);
	gettimeofday(&game->lwn.tv, NULL);
	load_img(game);
	get_door_coord(game);
	init_objects(game);
	init_audio(game);
	pathfinding(game);
	mlx_loop_hook(game->mlx, update_view, game);
	mlx_hook(game->win, 2, 1L << 0, key_pressed, game);
	mlx_hook(game->win, 3, 1L << 1, key_released, game);
	mlx_hook(game->win, 17, 0, close_win, game);
	mlx_loop(game->mlx);
}

// Fix crash empty file

int	main(int ac, char **av)
{
	t_data	game;

	if (!check_arg(ac, av))
		return (1);
	init_data(&game);
	get_data(&game, av[1]);
	run_game(&game);
	return (0);
}

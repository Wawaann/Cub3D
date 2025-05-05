/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:57:37 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/18 15:17:16 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	set_node_value(t_path *path, t_node *tmp, t_node *cur)
{
	if (path->i < 4)
		set_node(tmp, cur->g + 10, heuristic(tmp->x, tmp->y,
				floor(path->goal.x), floor(path->goal.y)), cur);
	else
		set_node(tmp, cur->g + 14, heuristic(tmp->x, tmp->y,
				floor(path->goal.x), floor(path->goal.y)), cur);
}

void	check_neighboor(t_path *path, t_map map, t_node *cur)
{
	t_node		*tmp;
	const int	dx[8] = {0, 0, -1, 1, 1, 1, -1, -1};
	const int	dy[8] = {-1, 1, 0, 0, 1, -1, 1, -1};

	path->i = 0;
	while (path->i < 8)
	{
		tmp = create_node(cur->x + dx[path->i], cur->y + dy[path->i]);
		if (dontneed(map, path, tmp))
		{
			free(tmp);
			path->i++;
			continue ;
		}
		path->index = get_index(path->open, tmp->x, tmp->y);
		set_node_value(path, tmp, cur);
		if (path->index == -1)
			lst_add(path->open, tmp);
		else if (path->open->nodes[path->index]->g > tmp->g)
			update_node(path->open, tmp);
		else
			free(tmp);
		path->i++;
	}
}

t_node	*astar(t_path *path, t_map map)
{
	t_node		*current;

	path->open = lst_new();
	path->closed = lst_new();
	current = create_node(floor(path->start.x), floor(path->start.y));
	set_node(current, 0, heuristic(path->start.x, path->start.y,
			path->goal.x, path->goal.y), NULL);
	lst_add(path->open, current);
	while (path->open->size > 0)
	{
		current = path->open->nodes[find_lowest_f(path->open)];
		if (current->x == floor(path->goal.x)
			&& current->y == floor(path->goal.y))
			return (current);
		lst_add(path->closed, current);
		lst_remove(path->open, get_index(path->open, current->x, current->y));
		check_neighboor(path, map, current);
	}
	return (NULL);
}

void	set_lwn_value(t_data *game, t_node *target)
{
	game->lwn.dist = 0;
	game->lwn.angle = (float)atan2((target->parent->y + 0.5) - game->lwn.y,
			(target->parent->x + 0.5) - game->lwn.x);
	if (game->lwn.angle < 0)
		game->lwn.angle += 2 * PI;
	while (target)
	{
		game->lwn.dist += target->g;
		target = target->parent;
	}
}

void	pathfinding(t_data *game)
{
	t_node	*target;

	game->path->start.x = game->ply.x;
	game->path->start.y = game->ply.y;
	game->path->goal.x = game->lwn.x;
	game->path->goal.y = game->lwn.y;
	if (floor(game->path->start.x) == floor(game->path->goal.x)
		&& floor(game->path->start.y) == floor(game->path->goal.y))
		return ;
	target = astar(game->path, game->map);
	if (!target)
	{
		game->lwn.active = false;
		game->lwn.dist = 0;
		return ;
	}
	set_lwn_value(game, target);
	lst_free(game->path->open);
	lst_free(game->path->closed);
}

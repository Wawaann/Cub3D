/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:15:47 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/18 15:16:02 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

float	heuristic(float x1, float y1, float x2, float y2)
{
	return (fabs(x1 - x2) + fabs(y1 - y2));
}

int	**cpy_map_path(t_map map)
{
	int	i;
	int	j;
	int	**new;

	new = ft_calloc(map.height + 1, sizeof(int *));
	i = 0;
	while (map.map[i])
	{
		j = 0;
		new[i] = ft_calloc(map.width[i] + 1, sizeof(int));
		while (map.map[i][j] != -1)
		{
			if (map.map[i][j] > 0)
				new[i][j] = 1;
			else
				new[i][j] = 0;
			j++;
		}
		new[i][j] = -1;
		i++;
	}
	return (new);
}

void	update_node(t_list *list, t_node *tmp)
{
	t_node	*up;

	up = list->nodes[get_index(list, tmp->x, tmp->y)];
	up->g = tmp->g;
	up->h = tmp->h;
	up->f = tmp->f;
	up->parent = tmp->parent;
	free(tmp);
	tmp = NULL;
}

void	display_node(t_node *node, int **map)
{
	printf("Node: (%d, %d); ", node->x, node->y);
	printf("G: %d; ", node->g);
	printf("H: %d; ", node->h);
	printf("F: %d; ", node->f);
	if (node->parent)
	{
		printf("Parent: (%d, %d); ", node->parent->x, node->parent->y);
	}
	else
	{
		printf("Parent: NULL; ");
	}
	printf("map[%d][%d]: %d\n", node->y, node->x, map[node->y][node->x]);
}

bool	dontneed(t_map map, t_path *path, t_node *tmp)
{
	const int	dx[8] = {0, 0, -1, 1, 1, 1, -1, -1};
	const int	dy[8] = {-1, 1, 0, 0, 1, -1, 1, -1};

	if (in_list(path->closed, tmp->x, tmp->y)
		|| path->map[tmp->y][tmp->x] > 0)
		return (true);
	if (tmp->x < 0 || tmp->y < 0
		|| tmp->y >= map.height || tmp->x >= map.width[tmp->y])
		return (true);
	if (path->i >= 4)
	{
		if (tmp->x - dx[path->i] < 0 || tmp->y < 0 || tmp->y >= map.height
			|| tmp->x - dx[path->i] >= map.width[tmp->y])
			return (true);
		if (tmp->y - dy[path->i] < 0 || tmp->y - dy[path->i] >= map.height
			|| tmp->x < 0 || tmp->x >= map.width[tmp->y - dy[path->i]])
			return (true);
		if (path->map[tmp->y][tmp->x - dx[path->i]] > 0
				&& path->map[tmp->y - dy[path->i]][tmp->x] > 0)
			return (true);
	}
	return (false);
}

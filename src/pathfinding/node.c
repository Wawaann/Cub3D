/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:19:43 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/18 15:15:52 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

t_node	*create_node(int x, int y)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	node->x = x;
	node->y = y;
	node->g = 0;
	node->h = 0;
	node->f = 0;
	node->parent = NULL;
	return (node);
}

void	set_node(t_node *node, int g, int h, t_node *parent)
{
	node->g = g;
	node->h = h;
	node->parent = parent;
}

int	find_lowest_f(t_list *open)
{
	int	i;
	int	index;

	if (open->size == 0)
		return (-1);
	index = 0;
	i = 1;
	while (i < open->size)
	{
		if (open->nodes[i]->f < open->nodes[index]->f)
			index = i;
		i++;
	}
	return (index);
}

int	get_index(t_list *list, int x, int y)
{
	int	i;

	i = 0;
	while (i < list->size)
	{
		if (list->nodes[i]->x == x && list->nodes[i]->y == y)
			return (i);
		i++;
	}
	return (-1);
}

bool	in_list(t_list *list, int x, int y)
{
	int	i;

	i = 0;
	while (i < list->size)
	{
		if (list->nodes[i]->x == x && list->nodes[i]->y == y)
			return (true);
		i++;
	}
	return (false);
}

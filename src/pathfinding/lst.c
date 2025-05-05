/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:16:58 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/18 15:15:25 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	display_list(t_list *list)
{
	int	i;

	i = 0;
	printf("size: %d\n", list->size);
	while (i < list->size)
	{
		printf("Node %d: (%d, %d) g: %d h: %d f: %d\n", i,
			list->nodes[i]->x, list->nodes[i]->y,
			list->nodes[i]->g, list->nodes[i]->h, list->nodes[i]->f);
		i++;
	}
}

t_list	*lst_new(void)
{
	t_list	*list;

	list = ft_calloc(1, sizeof(t_list));
	list->nodes = NULL;
	list->size = 0;
	return (list);
}

void	lst_add(t_list *list, t_node *node)
{
	t_node	**new_nodes;

	new_nodes = ft_calloc(list->size + 1, sizeof(t_node *));
	if (list->nodes)
	{
		ft_memcpy(new_nodes, list->nodes, list->size * sizeof(t_node *));
		free(list->nodes);
	}
	list->nodes = new_nodes;
	list->nodes[list->size] = node;
	list->size++;
}

void	lst_remove(t_list *list, int index)
{
	int	i;

	if (index < 0 || index >= list->size)
		return ;
	i = index;
	while (i < list->size - 1)
	{
		list->nodes[i] = list->nodes[i + 1];
		i++;
	}
	list->size--;
}

void	lst_free(t_list *list)
{
	int	i;

	i = 0;
	while (i < list->size)
	{
		free(list->nodes[i]);
		i++;
	}
	free(list->nodes);
	free(list);
}

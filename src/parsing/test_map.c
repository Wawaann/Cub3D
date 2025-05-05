/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:00:00 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/23 11:27:05 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

char	*cpy_line(char *line, int width)
{
	char	*new;

	new = ft_calloc(width + 3, sizeof(char));
	new[0] = ' ';
	ft_strcpy(new + 1, line);
	if (ft_strlen(line) < (size_t)width)
	{
		ft_memset(new + ft_strlen(line) + 1, ' ', width - ft_strlen(line));
	}
	new[width + 1] = ' ';
	return (new);
}

char	**cpy_map(char **map, int height, int width)
{
	char	**new;
	int		i;
	int		j;

	i = 1;
	j = 0;
	new = ft_calloc(ft_tablen(map) + 3, sizeof(char *));
	new[0] = ft_calloc(width + 3, sizeof(char));
	ft_memset(new[0], ' ', width + 2);
	new[ft_tablen(map) + 1] = ft_calloc(width + 3, sizeof(char));
	ft_memset(new[ft_tablen(map) + 1], ' ', width + 2);
	while (j < height)
	{
		new[i] = cpy_line(map[j], width);
		i++;
		j++;
	}
	return (new);
}

bool	compare_map(char **map, char **cpy, char ch)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ch && cpy[i + 1][j + 1] == 'V')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	test_single_map(char **cpy)
{
	int	i;
	int	j;

	i = 0;
	while (cpy[i])
	{
		j = 0;
		while (cpy[i][j])
		{
			if (cpy[i][j] != ' ' && cpy[i][j] != 'V')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	test_map(t_data *data)
{
	char	**cpy;

	check_char(data);
	cpy = cpy_map(data->parse.map, data->parse.height,
			data->parse.width);
	fill_map(cpy);
	if (!compare_map(data->parse.map, cpy, '0'))
	{
		ft_printf("Error\nMap not closed or space inside map\n");
		ft_freetab(cpy);
		exit_map(data, NULL);
	}
	ft_freetab(cpy);
	cpy = cpy_map(data->parse.map, data->parse.height,
			data->parse.width);
	fill_single_map(cpy);
	if (!test_single_map(cpy))
	{
		ft_printf("Error\nMore than one map closed\n");
		ft_freetab(cpy);
		exit_map(data, NULL);
	}
	ft_freetab(cpy);
}

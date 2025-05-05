/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:42:25 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/18 15:02:05 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	set_player(t_data *data, char ply, int i, int j)
{
	float	nord;
	float	sud;
	float	est;
	float	ouest;

	nord = 3 * PI / 2;
	sud = PI / 2;
	est = 0;
	ouest = PI;
	data->ply.x = (float)j + 0.5;
	data->ply.y = (float)i + 0.5;
	data->ply.a = 0;
	data->ply.th = 0.04;
	data->ply.stamina = MAX_STAMINA;
	data->ply.key = false;
	if (ply == 'N')
		data->ply.angle = nord;
	else if (ply == 'S')
		data->ply.angle = sud;
	else if (ply == 'E')
		data->ply.angle = est;
	else if (ply == 'W')
		data->ply.angle = ouest;
}

void	set_obj_pos(t_data *data, int i, int j, int count)
{
	if (count == 0)
		data->pos = ft_calloc(1, sizeof(t_vector));
	else
		data->pos = ft_realloc(data->pos, count + 1, sizeof(t_vector));
	data->pos[count].x = j + 0.5f;
	data->pos[count].y = i + 0.5f;
}

void	set_lowan(t_data *data, int i, int j)
{
	data->lwn.active = false;
	data->lwn.show = false;
	data->lwn.speed = 0;
	data->lwn.x = (float)j + 0.5;
	data->lwn.y = (float)i + 0.5;
}

void	set_map(t_data *data, int i, int j, int *count)
{
	if (data->parse.map[i][j] >= '1' && data->parse.map[i][j] <= '8')
		data->map.map[i][j] = data->parse.map[i][j] - '0';
	else if (data->parse.map[i][j] == 'M')
	{
		data->num_objects++;
		set_obj_pos(data, i, j, *count);
		data->map.map[i][j] = 0;
		(*count)++;
	}
	else if (data->parse.map[i][j] == 'N' || data->parse.map[i][j] == 'S'
		|| data->parse.map[i][j] == 'E' || data->parse.map[i][j] == 'W')
		set_player(data, data->parse.map[i][j], i, j);
	else if (data->parse.map[i][j] == 'K')
		set_key(data, i, j);
	else if (data->parse.map[i][j] == 'L')
		set_lowan(data, i, j);
	else if (data->parse.map[i][j] == ' ')
		data->map.map[i][j] = 10;
	else
		data->map.map[i][j] = 0;
}

void	convert_map(t_data *data, char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	data->map.map = ft_calloc(ft_tablen(map) + 1, sizeof(int *));
	data->map.map[ft_tablen(map)] = NULL;
	data->map.height = ft_tablen(map);
	data->map.width = ft_calloc(ft_tablen(map) + 1, sizeof(int));
	data->num_objects = 0;
	data->pos = NULL;
	while (map[i])
	{
		j = 0;
		data->map.map[i] = ft_calloc(ft_strlen(map[i]) + 1, sizeof(int));
		while (map[i][j])
		{
			set_map(data, i, j, &count);
			j++;
		}
		data->map.map[i][j] = -1;
		data->map.width[i] = j;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:24:50 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/28 16:13:20 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

int	is_good_param(char *line)
{
	int		nb;
	char	**tmp;

	if (ft_strcmp(line, "\n") == 0)
		return (0);
	tmp = ft_split(line, " \n");
	if (ft_tablen(tmp) != 2)
		return (ft_freetab(tmp), -1);
	if (ft_strdigit(tmp[0]) && ft_atoi(tmp[0]) > 0 && ft_atoi(tmp[0]) < 10)
	{
		nb = ft_atoi(tmp[0]);
		return (ft_freetab(tmp), nb);
	}
	if (ft_strcmp(tmp[0], "F") == 0)
		return (ft_freetab(tmp), 10);
	if (ft_strcmp(tmp[0], "C") == 0)
		return (ft_freetab(tmp), 11);
	if (ft_strcmp(tmp[0], "H") == 0)
		return (ft_freetab(tmp), 12);
	if (ft_strcmp(tmp[0], "K") == 0)
		return (ft_freetab(tmp), 13);
	if (ft_strcmp(tmp[0], "M") == 0)
		return (ft_freetab(tmp), 14);
	ft_printf("Error\nWrong parameter %s\n", tmp[0]);
	return (ft_freetab(tmp), -1);
}

int	get_texture(t_data *data, char *line, int fd, int param)
{
	int		i;
	char	**tmp;

	i = data->parse.nb_walls;
	tmp = ft_split(line, " \n");
	if (!test_texture(tmp[1]))
	{
		ft_freetab(tmp);
		exit_param(data, fd, line, NULL);
	}
	data->parse.walls[i] = ft_strdup(tmp[1]);
	data->parse.wall[i] = param + '0';
	data->parse.nb_walls++;
	ft_freetab(tmp);
	return (1);
}

int	get_oth(t_data *data, char *line, int param, int fd)
{
	char	**tmp;

	tmp = ft_split(line, " \n");
	if (!test_texture(tmp[1]))
	{
		ft_freetab(tmp);
		exit_param(data, fd, line, NULL);
	}
	if (param == 10)
		data->parse.oth[0] = ft_strdup(tmp[1]);
	if (param == 11)
		data->parse.oth[1] = ft_strdup(tmp[1]);
	if (param == 12)
		data->parse.oth[2] = ft_strdup(tmp[1]);
	if (param == 13)
		data->parse.oth[3] = ft_strdup(tmp[1]);
	if (param == 14)
		data->parse.oth[4] = ft_strdup(tmp[1]);
	ft_freetab(tmp);
	return (1);
}

char	*get_param(t_data *data, int fd)
{
	int		param;
	int		count;
	char	*line;

	param = 0;
	count = 0;
	data->parse.nb_walls = 0;
	line = get_next_line(fd);
	while (line && count < 11)
	{
		if (!line)
			break ;
		param = is_good_param(line);
		if (param == -1)
			break ;
		if (param > 0 && param < 9)
			count += get_texture(data, line, fd, param);
		if (param >= 10 && param <= 14)
			count += get_oth(data, line, param, fd);
		free(line);
		line = get_next_line(fd);
	}
	if (!test_fch(data->parse.oth))
		exit_param(data, fd, line, "Error\nMissing assets\n");
	return (line);
}

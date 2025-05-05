/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:40:25 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/24 17:52:04 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	free_file(char	*line, int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	exit_param(t_data *data, int fd, char *line, char *error)
{
	if (error)
		ft_putstr(error);
	free_file(line, fd);
	ft_freetab(data->parse.walls);
	ft_freetab(data->parse.oth);
	free(data->parse.wall);
	exit(0);
}

void	exit_map(t_data *data, char *msg)
{
	free(data->parse.wall);
	ft_freetab(data->parse.map);
	ft_freetab(data->parse.oth);
	ft_freetab(data->parse.walls);
	if (msg)
		ft_putendl_fd(msg, 2);
	exit(0);
}

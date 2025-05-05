/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:26:01 by ebigotte          #+#    #+#             */
/*   Updated: 2025/03/28 14:14:34 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

bool	check_file(char *path)
{
	char	*ext;
	int		fd;

	ext = path + ft_strlen(path) - 4;
	if (ft_strncmp(ext, ".cub", 4))
	{
		ft_printf("Error\nThe file must have the .cub extension.\n");
		return (false);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nThe file %s does not exist.\n", path);
		return (false);
	}
	close(fd);
	return (true);
}

bool	check_arg(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Error\nOne arguments is require.\n");
		return (false);
	}
	if (!check_file(av[1]))
		return (false);
	return (true);
}

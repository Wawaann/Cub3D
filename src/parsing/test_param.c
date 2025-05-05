/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 23:08:58 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/15 15:06:48 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

bool	test_texture(char *texture)
{
	int	fd;

	fd = open(texture, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nTexture file %s not found\n", texture);
		return (false);
	}
	close(fd);
	return (true);
}

bool	test_fch(char **oth)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (oth[i] == NULL)
			return (false);
		i++;
	}
	return (true);
}

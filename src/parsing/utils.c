/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:26:26 by ebigotte          #+#    #+#             */
/*   Updated: 2025/04/23 10:56:11 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

void	set_key(t_data *data, int i, int j)
{
	data->parse.key.x = (float)j + 0.5;
	data->parse.key.y = (float)i + 0.5;
}

void	exit_error(t_data *data, char *str)
{
	ft_printf("Error\n%s\n", str);
	exit_map(data, NULL);
}

void	validate_char(t_data *data, char c, int *count)
{
	char		*valid_chars;
	const char	*ply = "NSWE";

	valid_chars = ft_calloc(17, sizeof(char));
	ft_strlcpy(valid_chars, "0LKMNSWE ", 18);
	ft_strlcat(valid_chars, data->parse.wall, 18);
	if (!ft_strchr(valid_chars, c))
	{
		free(valid_chars);
		exit_error(data, "Invalid character in map");
	}
	if (ft_strchr(ply, c))
	{
		(*count)++;
		if (*count > 1)
		{
			free(valid_chars);
			exit_error(data, "Two or more players in map");
		}
	}
	free(valid_chars);
}

void	check_char(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data->parse.map[i])
	{
		j = 0;
		while (data->parse.map[i][j])
			validate_char(data, data->parse.map[i][j++], &count);
		i++;
	}
	if (count == 0)
		exit_error(data, "No player in map");
}

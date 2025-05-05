/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 22:01:51 by ebigotte          #+#    #+#             */
/*   Updated: 2025/03/23 10:50:10 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *f, const char *s)
{
	size_t	i;

	i = 0;
	while (f[i] && f[i] == s[i])
		i++;
	return (f[i] - s[i]);
}

int	ft_strncmp(const char *f, const char *s, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	while (f[i] && f[i] == s[i] && i < size - 1)
		i++;
	return (f[i] - s[i]);
}

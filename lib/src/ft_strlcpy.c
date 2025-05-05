/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:38:25 by ebigotte          #+#    #+#             */
/*   Updated: 2025/03/23 17:11:02 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy(char *dest, const char *src)
{
	size_t	c;

	c = 0;
	while (src[c] != '\0')
	{
		dest[c] = src[c];
		c++;
	}
	dest[c] = '\0';
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	c;
	size_t	d;

	c = 0;
	d = 0;
	while (src[c] != '\0')
		c++;
	if (size == 0)
		return (c);
	while (src[d] != '\0' && d < size - 1)
	{
		dest[d] = src[d];
		d++;
	}
	dest[d] = '\0';
	return (c);
}

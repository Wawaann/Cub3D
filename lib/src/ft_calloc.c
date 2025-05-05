/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:57:55 by ebigotte          #+#    #+#             */
/*   Updated: 2025/03/23 12:08:02 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count && size > SIZE_MAX / count)
	{
		return (NULL);
	}
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ptr = (void *)malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

void	*ft_realloc(void *ptr, size_t count, size_t size)
{
	void	*new_ptr;

	new_ptr = ft_calloc(count, size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, (count - 1) * size);
	free(ptr);
	return (new_ptr);
}

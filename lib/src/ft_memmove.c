/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:25:35 by ebigotte          #+#    #+#             */
/*   Updated: 2025/05/05 11:00:12 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*to;
	unsigned char	*from;

	to = (unsigned char *)dest;
	from = (unsigned char *)src;
	if (from == to || size == 0)
		return (dest);
	if (to > from && to < from + (int)size)
	{
		to += size;
		from += size;
		while (size--)
			*--to = *--from;
		return (dest);
	}
	if (from > to && from < to + (int)size)
	{
		while (size--)
			*to++ = *from++;
		return (dest);
	}
	ft_memcpy(dest, src, size);
	return (dest);
}

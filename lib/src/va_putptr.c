/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:31:05 by ebigotte          #+#    #+#             */
/*   Updated: 2025/03/23 10:48:43 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	va_putptr(va_list *list)
{
	unsigned long long	ptr;
	int					size;

	ptr = (unsigned long long)va_arg(*list, void *);
	size = 2;
	if (ptr == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putstr("0x");
	size += ft_nblen_base(ptr, 16);
	ft_putnbr_base(ptr, 16, 0);
	return (size);
}

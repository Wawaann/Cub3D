/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:55:09 by ebigotte          #+#    #+#             */
/*   Updated: 2025/03/23 10:48:43 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	va_putstr(va_list *list)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)va_arg(*list, char *);
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

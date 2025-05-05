/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:48:43 by ebigotte          #+#    #+#             */
/*   Updated: 2025/03/23 10:48:43 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, char ch)
{
	if (str == NULL)
		return (NULL);
	while (*str != ch)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return ((char *)str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:04:52 by ebigotte          #+#    #+#             */
/*   Updated: 2025/05/05 11:00:53 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, int start, size_t len)
{
	char	*str;
	size_t	i;

	if ((size_t)start >= ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	s += start;
	if (ft_strlen(s) < len)
		str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	else
		str = ft_calloc(len + 1, sizeof(char));
	i = 0;
	while (s[i] && i < len)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

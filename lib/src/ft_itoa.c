/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:31:58 by ebigotte          #+#    #+#             */
/*   Updated: 2025/03/23 10:48:43 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int num)
{
	char		*str;
	size_t		sign;
	size_t		size;
	long int	n;

	n = num;
	sign = (n < 0);
	size = ft_nblen(n) + sign;
	str = (char *)ft_calloc(size + 1, sizeof(char));
	str[size] = '\0';
	if (sign > 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (size-- > sign)
	{
		str[size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
/*
int main()
{
	char *str = ft_itoa(-0);
	printf("str: %s\n", str);
	return (0);
}*/
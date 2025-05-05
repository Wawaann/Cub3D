/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebigotte <ebigotte@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:06:44 by ebigotte          #+#    #+#             */
/*   Updated: 2025/03/23 10:48:43 by ebigotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_sep(char c, char *sep)
{
	size_t	i;

	i = 0;
	if (c == '\0')
		return (1);
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

size_t	count_word(const char *s, char *sep)
{
	size_t	word;
	size_t	i;

	word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], sep) > 0)
			i++;
		if (is_sep(s[i], sep) < 1)
			word++;
		while (is_sep(s[i], sep) < 1)
			i++;
	}
	return (word);
}

void	get_word(char *word, const char *s, char *sep)
{
	size_t	i;

	i = 0;
	while (is_sep(s[i], sep) < 1)
	{
		word[i] = s[i];
		i++;
	}
}

void	get_spilt(char **split, const char *s, char *sep)
{
	size_t	i;
	size_t	j;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (is_sep(s[i], sep) < 1)
		{
			j = 0;
			while (is_sep(s[i + j], sep) < 1)
				j++;
			split[word] = (char *)ft_calloc(j + 1, sizeof(char));
			get_word(split[word], s + i, sep);
			i += j;
			word++;
		}
		else
			i++;
	}
}

char	**ft_split(const char *s, char *sep)
{
	char	**split;
	size_t	word;

	word = count_word(s, sep);
	split = (char **)ft_calloc(word + 1, sizeof(char *));
	get_spilt(split, s, sep);
	return (split);
}

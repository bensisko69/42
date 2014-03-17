/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 17:46:33 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/02/09 00:41:57 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *str, char c)
{
	int	i;
	int	l;

	l = 0;
	i = 0;
	if (str[i] != c && str[i] != 0)
		l++;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (str[i + 1] != c && str[i + 1] != 0)
				l++;
		}
		i++;
	}
	return (l);
}

static int	count_c(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		y;
	int		word_len;
	char	**str;

	i = 0;
	y = 0;
	str = (char**)malloc(sizeof(char*) * (ft_count_word(s, c) + 1));
	while (s[i])
	{
		word_len = count_c(&s[i], c);
		if (word_len > 0)
		{
			str[y] = ft_strsub(&s[i], 0, word_len);
			i += word_len;
			y++;
		}
		if (s[i])
			i++;
	}
	str[y] = 0;
	return (str);
}

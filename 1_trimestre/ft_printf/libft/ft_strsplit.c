/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:38:40 by bboumend          #+#    #+#             */
/*   Updated: 2013/11/25 16:59:18 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	**ft_tab_memalloc(size_t size)
{
	char	**str;

	str = (char**)malloc(sizeof(char*) * (size + 1));
	if (str == 0)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}

static int		ft_count(const char *s, char c)
{
	int		c1;
	int		c2;

	c1 = 0;
	c2 = 0;
	while (s[c1])
	{
		while (s[c1] == c && s[c1] != '\0')
			c1++;
		if (s[c1] != '\0')
			c2++;
		while (s[c1] != c && s[c1] != '\0')
			c1++;
	}
	return (c2);
}
char	**ft_strsplit(const char *s, char c)
{
	char	**str;
	int		c1;
	int		c2;
	int		c3;
	int		c4;

	c1 = ft_count(s, c);
	c2 = 0;
	c3 = 0;
	str = ft_tab_memalloc(c1 + 1);
	while (s[c3])
	{
		c4 = 0;
		while (s[c3] == c && s[c3])
			c3++;
		c4 = c3;
		while (s[c3] != c && s[c3])
			c3++;
		if (c2 != c1)
		{
			str[c2] = ft_strsub(s, c4, (c3 - c4));
			c2++; 
		}
	}
	str[c2] = 0;
	return (str);
}

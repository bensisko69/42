/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 10:44:12 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/26 15:44:48 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_blank(char m)
{
	return (m == ' '
			|| m == '\n'
			|| m == '\t');
}

char	*ft_strtrim(char const *s)
{
	int		a;
	int		c;
	int		i;
	char	*str;

	a = ft_strlen(s);
	c = 0;
	i = 0;
	str = ft_memalloc(a + 1);
	a--;
	while (is_blank(s[c]))
		c++;
	if (s[c] == '\0')
		return (ft_strnew(0));
	while (is_blank(s[a]))
		a--;
	while (c != (a + 1))
	{
		str[i] = s[c];
		c++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

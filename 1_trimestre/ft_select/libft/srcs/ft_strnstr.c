/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:21:07 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/23 20:13:06 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = ft_strlen(s2);
	if (!*s2)
		return ((char *)s1);
	while (*s1 && n >= c)
	{
		if (!ft_strncmp(s1, s2, c))
			return ((char *)s1);
		s1++;
		n--;
	}
	return (0);
}

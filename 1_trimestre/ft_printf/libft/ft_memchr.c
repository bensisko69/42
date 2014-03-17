/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:37:58 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/20 16:56:31 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char		*s1;
	unsigned char	c1;
	size_t			i;

	i = 0;
	s1 = s;
	c1 = c;
	while (i != n)
	{
		if (s1[i] == c1)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}

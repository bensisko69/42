/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:41:43 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/21 10:49:40 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char		*s12;
	const char		*s22;
	size_t			i;

	s12 = s1;
	s22 = s2;
	i = 0;
	if (!s1 && !s2)
		return (0);
	while (i != n)
	{
		if (s12[i] != s22[i])
			return ((uchar)s12[i] - (uchar)s22[i]);
		i++;
	}
	return (0);
}

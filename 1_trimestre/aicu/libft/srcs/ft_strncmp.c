/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:19:22 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/23 18:29:08 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;
	size_t	b;
	size_t	c;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	c = (a > b ? a : b);
	c = (c < n ? c : n);
	return (ft_memcmp((const void *)s1, (const void *)s2, c));
}

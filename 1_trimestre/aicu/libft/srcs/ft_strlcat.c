/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:38:12 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/23 18:00:09 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	t1;
	size_t	t2;

	t1 = ft_strlen(src);
	t2 = ft_strlen(dst);
	if (t2 < n)
	{
		ft_strncat(dst, src, n - t2 - 1);
		return (t1 + t2);
	}
	else
		return (n + t1);
}

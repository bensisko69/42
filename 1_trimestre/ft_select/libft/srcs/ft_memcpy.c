/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:39:56 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/20 16:56:19 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest1;
	const char	*src1;

	dest1 = dest;
	src1 = src;
	while (n != 0)
	{
		dest1[n - 1] = src1[n - 1];
		n = n - 1;
	}
	return (dest);
}

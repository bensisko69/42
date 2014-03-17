/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:33:21 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/22 15:05:41 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	d;
	int		length;

	d = c;
	length = ft_strlen(s);
	while (length >= 0)
	{
		if (s[length] == d)
			return ((char *)(&s[length]));
		length--;
	}
	return (NULL);
}

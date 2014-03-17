/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:33:07 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/22 16:04:18 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		i;

	i = ft_strlen(s2);
	while (!*s2)
		return ((char *)s1);
	while (*s1)
	{
		if (!ft_strncmp(s1, s2, i))
			return ((char *)s1);
				s1 = s1 + 1;
	}
	return (0);
}

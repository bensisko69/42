/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:21:29 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/21 11:34:26 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*dup;
	int			c;

	c = ft_strlen(s);
	dup = (char*)malloc((c + 1) * sizeof(char));
	if (dup != 0)
		ft_memcpy(dup, s, c + 1);
	return (dup);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:33:47 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/22 15:03:28 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	d;
	int		temp;

	d = c;
	temp = 0;
	while (s[temp] != d && s[temp] != 0)
		temp = temp + 1;
	if (s[temp] == d)
		return ((char*)&s[temp]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:12:45 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/27 13:14:50 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char*	ft_strmap(char const *s, char (*f)(char))
{
	int		c;
	char	leng;
	char	*chaine;

	leng = ft_strlen(s) + 1;
	chaine = malloc(leng * sizeof(*chaine));
	c = 0;
	while (s[c] != '\0')
	{
		chaine[c] = f(s[c]);
		c++;
	}
	chaine[c] = '\0';
	return (chaine);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:28:46 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/27 17:44:33 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		compt;
	int		compt2;
	char	*ch;

	compt = 0;
	compt2 = 0;
	ch = malloc(sizeof(*ch) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (s1[compt2] != '\0')
	{
		ch[compt] = s1[compt2];
		compt++;
		compt2++;
	}
	compt2 = 0;
	while (s2[compt2] != '\0')
	{
		ch[compt] = s2[compt2];
		compt++;
		compt2++;
	}
	ch[compt] = '\0';
	return (ch);
}

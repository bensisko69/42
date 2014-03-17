/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 12:43:49 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/01/27 16:40:35 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_comp(char *str, char *s1)
{
	int	a;

	a = 0;
	while (s1[a])
	{
		if (str[(unsigned int)s1[a]] == 0)
		{
			write(1, &s1[a], 1);
			str[(unsigned int)s1[a]] = 1;
		}
		a++;
	}
}

void	ft_union(char *s1, char *s2)
{
	char	str[256] = {0};

	ft_comp(str, s1);
	ft_comp(str, s2);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return 0;
}

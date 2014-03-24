/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 16:28:52 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/03/24 17:39:52 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_union(char *str, char *str2)
{
	int	tab[256] = {0};
	int	a;
	
	a = 0;
	while (str[a])
	{
		if (tab[(int)str[a]] == 0)
		{
			tab[(int)str[a]] = 1;
			write (1, &str[a], 1);
		}
		a++;
	}
	a = 0;
	while (str2[a])
	{
		if (tab[(int)str2[a]] == 0)
		{
			tab[(int)str2[a]] = 1;
			write(1, &str2[a], 1);
		}
		a++;
	}
}

int	main (int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}

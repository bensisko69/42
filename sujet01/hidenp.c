/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:29:42 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/03/24 16:40:27 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_hidenp(char *str, char *str2)
{
	int c;
	int a;

	c = 0;
	a = 0;
	while (str[c] != '\0' && str2[a] != '\0')
	{
		if (str[c] == str2[a])
			c++;
		a++;
	}
	if (str[c] == '\0')
		write (1, "1", 1);
	else
		write (1,"0", 1);
}

int main (int ac, char ** av)
{
	if (ac == 3)
	   ft_hidenp(av[1], av[2]);
	write (1, "\n", 1);
	return (0);	
}

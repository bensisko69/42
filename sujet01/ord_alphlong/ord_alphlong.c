/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 17:47:05 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/03/24 18:15:13 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ord.h"

int		cmplen(char *str, char *str2)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (str[a])
		a++;
	while (str2[b])
		b++;
	if (a == b)
		return (0);
	if (a > b)
		return (1);
	if (a < b)
		return (2);
}



void	ord(char *str, t_list *list)
{
	
}

int		main (int ac, char **av)
{
	t_list	*list;

	list = NULL;
	if (ac == 2)
		ord(av[1], list);
	write (1, "\n", 1);
}

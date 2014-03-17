/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/10 15:09:27 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/02/12 20:30:02 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	read_button(t_list **list, t_list **current)
{
	char	buf[7] = {0};
	int		i;

	i = 0;
	read(0, buf, 6);
	//while (i < 6)
	//printf("%o ", buf[i++]);
	key_pressed(list, current, buf);
	ft_putchar('\n');
	print_list(*list, *current);
}

int		main(int ac, char **av)
{
	t_list	*list;
	t_list	*current;
	int		i;

	i = 1;
	list = NULL;
	init_term();
	if (ac > 1)
	{
		while (av[i] != 0)
		{
			ft_new_elem(&list, av[i]);
			i++;
		}
	current = list;
	print_list(list, current);
	for(;;)
		read_button(&list, &current);
	}
	else
		ft_putendl_fd("Too few arguments", 2);
	return (0);
}

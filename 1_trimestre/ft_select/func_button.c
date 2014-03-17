/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 15:37:56 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/02/13 14:58:49 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

extern t_termios	g_term_origin;

void	arrow_left(t_list **list, t_list **current)
{
	(void)list;
	*current = (*current)->previous;
}

void	arrow_right(t_list **list, t_list **current)
{
	(void)list;
	*current = (*current)->next;
}

void	esc(t_list **list, t_list **current)
{
	(void)current;
	(void)list;
	if (tcsetattr(0, TCSANOW, &g_term_origin) == 0)
		exit(0);
}

void	enter(t_list **list, t_list **current)
{
	int		flag;
	int		space;

	space = 0;
	*current = *list;
	flag = 0;
	term_command(CAP_CLEAR_SCREEN);
	while (*current != *list || flag == 0)
	{
		if ((*current)->select == 1)
		{
			if (space > 0)
				ft_putchar(' ');
			space++;
			ft_putstr((*current)->str);
		}
		*current = (*current)->next;
		flag++;
	}
	esc(list, current);
}

void	ft_delete(t_list **list, t_list **current)
{
	t_list	*tmp;

	tmp = *current;
	*current = (*current)->next;
	list_remove(list, tmp);
}

void	space(t_list **list, t_list **current)
{
	(void)list;
	(*current)->select = !(*current)->select;
	*current = (*current)->next;
}


void	key_pressed(t_list **list, t_list **current, char *key_code)
{
	static t_key	key[] =
	{
		{KEY_ARROW_LEFT, arrow_left},
		{KEY_ARROW_UP, arrow_left},
		{KEY_ARROW_RIGHT, arrow_right},
		{KEY_ARROW_DOWN, arrow_right},
		{KEY_DELETE, ft_delete},
		{KEY_BACKSPACE, ft_delete},
		{KEY_ESC, esc},
		{KEY_SPACE, space},
		{KEY_ENTER, enter}
	};
	size_t			i;

	i = 0;
	while (i < sizeof(key) / sizeof(t_key))
	{
		if (ft_strcmp(key[i].key_code, key_code) == 0)
			{
				key[i].func(list, current);
				break ;
			}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/10 16:58:28 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/02/13 14:32:25 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_list		*create_list(char *str)
{
	t_list	*root;

	root = (t_list*)malloc(sizeof(t_list));
	if (root != NULL)
	{
		root->select = 0;
		root->str = str;
		root->next = root;
		root->previous = root;
	}
	return (root);
}

t_list		*search_list_next(t_list **list, char *cmd)
{
	t_list	*it;

	it = *list;
	while (it->next != *list)
	{
		if (ft_strcmp(it->str, cmd) == 0)
			return (it);
		it = it->next;
	}
	if (ft_strcmp(it->str, cmd) != 0)
		return (it);
	return (NULL);
}

void		list_remove(t_list **list, t_list *to_delete)
{
	t_list	*it;

	it = *list;
	while (it->next != *list)
	{
		if (to_delete == it)
		{
			it->previous->next = it->next;
			it->next->previous = it->previous;
			if (it == *list)
				*list = it->next;
			free(it);
			return ;
		}
		it = it->next;
	}
	if (to_delete == it)
	{
		it->previous->next = it->next;
		it->next->previous = it->previous;
		if (it == *list)
			*list = it->next;
		free(it);
	}
}

void	print_list(t_list *list, t_list *current)
{
	t_list	*temp;

	temp = list;
	list = list->previous;
	term_command(CAP_CLEAR_SCREEN);
	while (temp != list)
	{
		if (temp == current)
			term_command(UNDERLINE_BEGIN);
		if (temp->select == 1)
			term_command(REVERSE_VIDEO);
		ft_putstr(temp->str);
		term_command(ALL_END);
		ft_putchar('\n');
		temp = temp->next;
	}
	if (temp == current)
		term_command(UNDERLINE_BEGIN);
	if (temp->select == 1)
		term_command(REVERSE_VIDEO);
	ft_putstr(temp->str);
	term_command(ALL_END);
	ft_putchar('\n');
}

void	ft_new_elem(t_list **list, char *cmp)
{
	t_list	*new_elem;
	t_list	*last_element;

	new_elem = create_list(cmp);
	if (*list == NULL)
		*list = new_elem;
	else
	{
		last_element = (*list)->previous;
		new_elem->next = *list;
		new_elem->previous = last_element;
		(*list)->previous = new_elem;
		last_element->next = new_elem;
	}
}


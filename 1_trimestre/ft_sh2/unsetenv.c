/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 13:18:08 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/02/15 16:35:15 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unsetenv(t_list **list, char *line)
{
	char	**cmp;

	cmp = ft_strsplit(line, ' ');
	if (char_array_size(cmp) >= 2)
	{
		list_remove(list, cmp[1]);
	}
	else
		ft_erreur(BUILTIN_UNSETENV, ERR_NOT_ENOUGH_ARGS, 0);
	free_char_array(cmp);
}

void	list_remove(t_list **list, char *str)
{
	t_list	*it;
	t_list	*previous;

	it = *list;
	previous = 0;
	while (it != NULL)
	{
		if (ft_strnequ(it->str, str, ft_strlen_char(it->str, '=')) == 1)
		{
			if (previous)
				previous->next = it->next;
			else
				*list = it->next;
			free(it->str);
			free(it);
			return ;
		}
		previous = it;
		it = it->next;
	}
	ft_erreur(BUILTIN_UNSETENV, ERR_NON_EXISTING_KEY, str);
}

int		char_array_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_list(t_list **list, char *line)
{
	t_list	*it;

	(void)line;
	it = *list;
	while (it != NULL)
	{
		ft_putstr(it->str);
		ft_putchar('\n');
		it = it->next;
	}
}

char	*exchange_tab_for_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] != 0)
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
	return (line);
}


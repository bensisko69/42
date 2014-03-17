/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 19:54:06 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/02/15 15:40:54 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_exit(t_list **list, char *line)
{
	t_list	*it;
	t_list	*tmp;

	(void)line;
	tmp = NULL;
	it = *list;
	while (it != NULL)
	{
		tmp = it->next;
		free(it);
		it = tmp;
	}
	exit(0);
}

void		do_command(t_list **list, char *line)
{
	size_t				i;
	static t_builtins	builtins[] =
	{
		{BUILTIN_ENV,      print_list},
		{BUILTIN_EXIT,     ft_exit},
		{BUILTIN_SETENV,   ft_setenv},
		{BUILTIN_UNSETENV, ft_unsetenv},
		{BUILTIN_CD,       ft_cd}
	};
	size_t				size;

	i = 0;
	while (i < sizeof(builtins) / sizeof(t_builtins))
	{
		size = ft_strlen(builtins[i].str);
		if (ft_strncmp(builtins[i].str, line, size) == 0
			&& (!line[size] || line[size] == ' '))
			return (builtins[i].func(list, line));
		++i;
	}
	ft_access(*list, line);
}

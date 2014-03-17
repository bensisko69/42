/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 16:38:27 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/02/15 15:39:02 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;

static t_list	*new_link(char *line)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->str = line;
	list->next = NULL;
	return (list);
}

static int		list_size(t_list *list)
{
	int	c;

	c = 0;
	while (list != NULL)
	{
		list = list->next;
		c++;
	}
	return (c);
}

void			ft_link(t_list **list, char *str)
{
	t_list	*it;

	if (*list == NULL)
		*list = new_link(str);
	else
	{
		it = *list;
		while (it->next != NULL)
			it = it->next;
		it->next = new_link(str);
	}
}

t_list			*ft_env_cpy(void)
{
	int		i;
	t_list	*line;

	i = 0;
	line = 0;
	while (environ[i])
	{
		ft_link(&line, ft_strdup(environ[i]));
		i++;
	}
	return (line);
}

char			**change(t_list *list)
{
	char	**env;
	int		c;

	env = (char **)malloc((list_size(list) + 1) * sizeof(char *));
	c = 0;
	while (list != NULL)
	{
		env[c] = list->str;
		list = list->next;
		c++;
	}
	env[c] = 0;
	return (env);
}

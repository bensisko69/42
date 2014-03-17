/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 16:31:11 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/02/15 15:40:18 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_setenv(t_list **list, char *line)
{
	char	**cmp;
	char	*cmp2;
	char	*cmp3;

	cmp = ft_strsplit(line, ' ');
	if (char_array_size(cmp) >= 3)
	{
		if (search(*list, cmp[1]) == 0)
		{
			cmp2 = join(cmp[1], "=", cmp[2]);
			ft_link(list, cmp2);
		}
		else
		{
			cmp3 = search(*list, cmp[1]);
			cmp2 = join(cmp[1], "=", cmp[2]);
			exchange_content(*list, cmp3, cmp2);
		}
	}
	else
		ft_putstr("setenv: not enough argument\n");
	free_char_array(cmp);
}

int		ft_strlen_char(char *str, char symb)
{
	int	i;

	i = 0;
	while (str[i] != symb)
		i++;
	return (i);
}

void	exchange_content(t_list *list, char *cmp2, char *cmp3)
{
	while (list != NULL)
	{
		if (ft_strnequ(list->str, cmp2, ft_strlen_char(list->str, '=')))
		{
			free(list->str);
			list->str = cmp3;
			break ;
		}
		list = list->next;
	}
}

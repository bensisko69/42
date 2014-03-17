/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 17:07:36 by bboumend          #+#    #+#             */
/*   Updated: 2013/11/30 17:14:52 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*i;
	t_list	*tmp;

	if (alst)
	{
		i = *alst;
		while (i)
		{
			del(i->content, i->content_size);
			tmp = i->next;
			free(i);
			i = tmp;
		}
		*alst = NULL;
	}
}

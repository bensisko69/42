/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 19:59:55 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/02/12 20:13:33 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static int	t_puts(int c)
{
	ft_putchar(c);
	return (42);
}

void		term_command(char *command)
{
	char	*res;

	res = tgetstr(command, NULL);
	tputs(res, 0, t_puts);
}

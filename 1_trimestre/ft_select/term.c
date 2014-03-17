/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 15:11:17 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/02/12 18:18:38 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_termios	g_term_origin;

int		init_term(void)
{
	t_termios	term;
	char		*name_term;

	name_term = getenv("TERM");
	if (name_term == NULL)
		return (-1);
	if (tgetent(NULL, name_term) != 1)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	ft_memcpy(&g_term_origin, &term, sizeof(t_termios));
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (-1);
	return (0);
}

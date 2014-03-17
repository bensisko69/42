/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/10 15:09:34 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/02/13 14:30:15 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H
# include <termios.h>
# include <unistd.h>
# include <term.h>
# include <libft.h>
# include <stdio.h>

/*
** Double linked list
*/
typedef struct s_list t_list;

struct		s_list
{
	char	*str;
	int		select;
	t_list	*next;
	t_list	*previous;
};

t_list		*create_list(char *str);
t_list		*search_list_next(t_list **list, char *cmd);
void		list_remove(t_list **list, t_list *to_delete);
void		ft_new_elem(t_list **list, char *cmp);
void		print_list(t_list *list, t_list *current);

/*
** Terminal
*/
typedef struct termios t_termios;

int			init_term(void);

/*
** Button
*/
typedef struct s_key t_key;
typedef void	(*t_key_func)(t_list **, t_list **);

struct			s_key
{
	char		*key_code;
	t_key_func	func;
};

void		read_button(t_list **list, t_list **current);
void		key_pressed(t_list **list, t_list **current, char *key_code);
void		arrow_left(t_list **list, t_list **current);
void		arrow_right(t_list **list, t_list **current);
void		ft_delete(t_list **list, t_list **current);
void		esc(t_list **list, t_list **current);
void		space(t_list **list, t_list **current);
void		enter(t_list **list, t_list **current);

/*
** Key codes
*/
# define KEY_ARROW_UP		"\033\133\101"
# define KEY_ARROW_DOWN		"\033\133\102"
# define KEY_ARROW_RIGHT	"\033\133\103"
# define KEY_ARROW_LEFT		"\033\133\104"
# define KEY_DELETE			"\033\133\063\176"
# define KEY_BACKSPACE		"\177"
# define KEY_ESC			"\033"
# define KEY_SPACE			"\040"
# define KEY_ENTER			"\012"

/*
** Termcaps
*/
# define CAP_CLEAR_SCREEN	"cl"
# define REVERSE_VIDEO		"mr"
# define UNDERLINE_BEGIN	"us"
# define ALL_END			"me"


void		term_command(char *command);

#endif

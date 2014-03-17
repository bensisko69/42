/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 14:54:18 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/02/15 16:35:40 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
#include <signal.h>
# define BUFF_SIZE 32
# include <string.h>
# include <libft.h>

typedef struct s_list		t_list;


typedef struct stat			t_stat;

struct		s_list
{
	char	*str;
	t_list	*next;
};

t_list	*ft_env_cpy(void);
void	ft_link(t_list **line, char *str);
char	**change(t_list *list);
void	ft_access(t_list *list, char *line);
char	*join(char *str1, char *carac, char *str2);
void	free_char_array(char **array);
void	exchange_content(t_list *list, char *cmp2, char *cmp3);
void	ft_execve(char *cmp, char **argum, t_list *list);
char	*search(t_list *list, char *var_name);
int		char_array_size(char **str);
void	list_remove(t_list **list, char *str);
void	ft_oldpwd(t_list **list, char *name_src, char *name_dest);
int		check_cmd(char *cmd);
void	show_prompt(t_list *list);
int		ft_strlen_char(char *str, char symb);
char	*exchange_tab_for_space(char *line);
/*
**Pointeur sur fonction
*/
typedef void (*t_command)(t_list**, char*);
typedef struct s_builtins	t_builtins;

struct			s_builtins
{
	char		*str;
	t_command	func;
};

# define BUILTIN_ENV		"env"
void	print_list(t_list **list, char *line);
# define BUILTIN_EXIT		"exit"
# define BUILTIN_SETENV		"setenv"
void	ft_setenv(t_list **list, char *line);
# define BUILTIN_UNSETENV	"unsetenv"
void	ft_unsetenv(t_list **list, char *line);
# define BUILTIN_CD			"cd"
void	ft_cd(t_list **list, char *line);

void	do_command(t_list **list, char *line);

/*
**gestion d'erreur
*/
# define ERR_CMD_NOT_FOUND		"command not found"
# define ERR_NO_SUCH_FILE		"no such file or directory"
# define ERR_DENIED				"permission denied"
# define ERR_NOT_A_DIR			"not a directory"
# define ERR_UNKNOWN			"erreur unknown"
# define ERR_NOT_ENOUGH_ARGS	"not enough arguments"
# define ERR_NON_EXISTING_KEY	"non existing key"

void	ft_erreur(char *cmd, char *erreur, char *info);

#endif

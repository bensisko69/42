/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 14:32:36 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/02/15 16:35:02 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_execve(char *cmd, char **argum, t_list *list)
{
	pid_t	pid;

	pid = fork();
	if (pid > 0)
	{
		waitpid(pid, 0, 0);
	}
	if (pid == 0)
	{
		execve(cmd, argum, change(list));
		ft_putendl("error execve");
		exit(0);
	}
}

void	show_prompt(t_list *list)
{
	char	*pwd;
	char	**path_components;
	char	*prompt;
	int		component_count;

	pwd = search(list, "PWD=") + 4;
	path_components = ft_strsplit(pwd, '/');
	write(1, "[POKEMON] ", 10);
	component_count = char_array_size(path_components);
	if (component_count < 2)
		ft_putstr(pwd);
	else
	{
		prompt = join(path_components[component_count - 2], "/",
						path_components[component_count - 1]);
		ft_putstr(prompt);
		free(prompt);
	}
	write(1, " > ", 3);
	free_char_array(path_components);
}

static void	exec_absolu(char *line, t_list *list)
{
	char	**str;

	str = ft_strsplit(line, ' ');
	if (check_cmd(str[0]))
		ft_execve(str[0], str, list);
	else
		ft_erreur(line, ERR_NO_SUCH_FILE, 0);
	free_char_array(str);
}

static t_list		*ft(t_list *lst)
{
	static t_list	*save = NULL;

	if (save == NULL)
		save = lst;
	return (save);
}

static void	ft_signal(int sig)
{
	t_list	*list;

	(void)sig;
	list = ft(NULL);
	ft_putchar('\n');
	show_prompt(list);
}

int			main(void)
{
	char	*line;
	char	*line2;
	t_list	*list;
	char	**args;

	list = ft_env_cpy();
	signal(SIGINT, ft_signal);
	show_prompt(list);
	while (get_next_line(0, &line) == 1)
	{
		line2 = exchange_tab_for_space(line);
		args = ft_strsplit(line2, ' ');
		if (args && args[0])
		{
			if (ft_strchr(args[0], '/'))
				exec_absolu(line, list);
			else
				do_command(&list, line);
		}
		free(line);
		show_prompt(list);
		free_char_array(args);
	}
	ft_putchar('\n');
	return (0);
}

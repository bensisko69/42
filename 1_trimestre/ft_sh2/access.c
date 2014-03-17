/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 10:33:05 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/02/15 15:40:36 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_char_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

char	*join(char *str1, char *carac, char *str2)
{
	char	*joined;
	char	*temp;

	joined = ft_strjoin(str1, carac);
	temp = joined;
	joined = ft_strjoin(joined, str2);
	free(temp);
	return (joined);
}

int		check_cmd(char *cmd)
{
	t_stat	file_stat;

	if (stat(cmd, &file_stat) != 0)
		return (0);
	if (S_ISREG(file_stat.st_mode) != 1)
		return (0);
	return (access(cmd, F_OK | X_OK) == 0);
}

static void	ft_access2(t_list *list, char **paths, char **argum)
{
	char		*cmd;
	int			i;
	int			found;

	found = 0;
	i = 0;
	while (paths[i])
	{
		cmd = join(paths[i], "/", argum[0]);
		if (check_cmd(cmd))
		{
			ft_execve(cmd, argum, list);
			found = 1;
			free(cmd);
			break ;
		}
		i++;
		free(cmd);
	}
	if (found == 0)
		ft_erreur(argum[0], ERR_CMD_NOT_FOUND, 0);
}

void	ft_access(t_list *list, char *line)
{
	char		*path;
	char		**paths;
	char		**argum;

	path = search(list, "PATH=");
	paths = ft_strsplit(path + 5, ':');
	argum = ft_strsplit(line, ' ');
	if (argum[0])
		ft_access2(list, paths, argum);
	free_char_array(paths);
	free_char_array(argum);
}

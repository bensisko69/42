/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 19:48:25 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/02/15 15:40:58 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cd_erreur(char *pwd, char *argum)
{
	struct stat	buf;

	if (stat(argum, &buf) == -1)
		ft_erreur(argum, ERR_NO_SUCH_FILE, 0);
	else if (S_ISDIR(buf.st_mode) == 0)
		ft_erreur(argum, ERR_NOT_A_DIR, 0);
	else if (access(pwd, X_OK) == -1)
		ft_erreur(argum, ERR_DENIED, 0);
	else
		ft_erreur(argum, ERR_CMD_NOT_FOUND, 0);
}

static void	reduc_cd(t_list **list, char *argum, char *pwd, char *cwd)
{
	char	*new_pwd;

	exchange_content(*list, "OLDPWD=", ft_strjoin("OLDPWD=", pwd + 4));
	pwd = join(pwd + 4, "/", argum);
	if (chdir(pwd) == 0)
	{
		cwd = getcwd(0, 0);
		new_pwd = ft_strjoin("PWD=", cwd);
		free(cwd);
		exchange_content(*list, "PWD=", new_pwd);
	}
	else
		cd_erreur(pwd, argum);
	free(pwd);
}

void		ft_cd(t_list **list, char *line)
{
	char	*pwd;
	char	**argum;
	char	*cwd;

	pwd = search(*list, "PWD=");
	argum = ft_strsplit(line, ' ');
	if (char_array_size(argum) == 1)
		ft_oldpwd(list, "HOME=", "PWD=");
	else if (char_array_size(argum) == 2)
	{
		if (ft_strcmp(argum[1], "-") == 0)
		{
			ft_putendl(search(*list, "OLDPWD=") + 7);
			ft_oldpwd(list, "OLDPWD=", "PWD=");
		}
		else
			reduc_cd(list, argum[1], pwd, cwd);
	}
	free_char_array(argum);
}

void		ft_oldpwd(t_list **list, char *name_src, char *name_dest)
{
	char	*src;
	char	*dest;
	char	*oldpwd;

	src = search(*list, name_src) + ft_strlen(name_src);
	dest = search(*list, name_dest) + ft_strlen(name_dest);
	oldpwd = ft_strjoin("OLDPWD=", dest);
	if (chdir(src) == 0)
	{
		exchange_content(*list, "PWD=", ft_strjoin("PWD=", src));
		exchange_content(*list, "OLDPWD=", oldpwd);
	}
}

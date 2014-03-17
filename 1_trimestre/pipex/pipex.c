/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 13:37:40 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/02/03 20:43:15 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

extern char **environ;

static int	has_perm(mode_t mode, mode_t flag)
{
	return ((mode & flag) == flag);
}

int	ft_open(char *file_name, mode_t flags, mode_t perm)
{
	t_stat	file_stat;
	int		fd;

	fd = open(file_name, flags, perm);
	if (fd == -1)
	{
		if (stat(file_name, &file_stat) != 0)
			ft_putendl_fd("no such file or directory", 2);
		else if (S_ISREG(file_stat.st_mode) != 1)
			ft_putendl_fd("is a directory", 2);
		else if (has_perm(file_stat.st_mode, perm) == 0)
			ft_putendl_fd("permission denied", 2);
	}
	return (fd);
}

# define CREATION_PERMS (S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH)
# define WRITE_FLAGS (O_WRONLY | O_CREAT | O_TRUNC)

# define READ_END 0
# define WRITE_END 1

static void	pipex(char *in_file, char **cmd1, char **cmd2, char *out_file)
{
	int		fd_in;
	int		fd_out;
	pid_t	pid;
	int		fds[2];

	if (pipe(fds) != -1)
	{
		pid = fork();
		if (pid != -1)
		{
			if (pid == 0)
			{
				fd_in = ft_open(in_file, O_RDONLY, S_IRUSR);
				dup2(fd_in, STDIN_FILENO);
				close(fd_in);
				dup2(fds[WRITE_END], STDOUT_FILENO);
				close(fds[WRITE_END]);
				close(fds[READ_END]);
				execve(cmd1[0], cmd1, environ);
				perror(0);
			}
			else
			{
				fd_out = ft_open(out_file, WRITE_FLAGS, CREATION_PERMS);
				dup2(fd_out, STDOUT_FILENO);
				close(fd_out);
				dup2(fds[READ_END], STDIN_FILENO);
				close(fds[READ_END]);
				close(fds[WRITE_END]);
				execve(cmd2[0], cmd2, environ);
				perror(0);
			}
		}
		else
			fork_error;
	}
	else
		pipe_error;
}

static void	show_usage(char *name)
{
	printf("usage : %s [file1] [cmd1] [cmd2] [file2]\n", name);
}

int	main(int ac, char **av)
{
	char	*in_file_name;
	char	*out_file_name;
	char	**cmd_in;
	char	**cmd_out;

	if (ac == 5)
	{
		in_file_name = av[1];
		out_file_name = av[4];
		cmd_in = ft_strsplit(av[2], ' ');
		cmd_out = ft_strsplit(av[3], ' ');
		pipex(in_file_name, cmd_in, cmd_out, out_file_name);
	}
	else
		show_usage(av[0]);
	return (0);
}

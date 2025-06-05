/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:01:43 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/05 14:45:32 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute(char *cmd, char **envp)
{
	char	**args;
	char	*cmd_path;

	args = ft_split(cmd, ' ');
	cmd_path = find_command_path(args[0], envp);
	if (!cmd_path)
	{
		ft_printf("Command not found: %s\n", args[0]);
		free_split(args);
		exit(127);
	}
	if (execve(cmd_path, args, envp) == -1)
	{
		free(cmd_path);
		free_split(args);
		error_exit("execve failed");
	}
}

void	close_fds(int *fds, int count)
{
	int		i;

	i = 0;
	while (i < count)
		close(fds[i++]);
}

void	child_process(char **argv, char **envp, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY);
	if (filein < 0)
		error_exit("open filein");
	if (dup2(filein, STDIN_FILENO) < 0)
		error_exit("dup2 filein");
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		error_exit("dup2 pipe write");
	close_fds(fd, 2);
	close(filein);
	execute(argv[2], envp);
	error_exit("execve failed");
}

void	second_child_process(char **argv, char **envp, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout < 0)
		error_exit("open fileout");
	if (dup2(fd[0], STDIN_FILENO) < 0)
		error_exit("dup2 pipe read");
	if (dup2(fileout, STDOUT_FILENO) < 0)
		error_exit("dup2 fileout");
	close_fds(fd, 2);
	close(fileout);
	execute(argv[3], envp);
	error_exit("execve failed");
}

int	wait_and_check(pid_t pid)
{
	int	status;

	if (waitpid(pid, &status, 0) == -1)
		error_exit("waitpid");
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (1);
}

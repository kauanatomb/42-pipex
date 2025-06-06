/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:01:43 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/05 14:39:00 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
	{
		ft_putendl_fd("Args error.\nUsage: ./pipex infile cmd1 cmd2 outfile", 2);
		exit(1);
	}
	if (pipe(fd) == -1)
		error_exit("Pipe error");
	pid1 = fork();
	if (pid1 < 0)
		error_exit("Fork1 error");
	if (pid1 == 0)
		child_process(argv, envp, fd);
	pid2 = fork();
	if (pid2 < 0)
		error_exit("Fork2 error");
	if (pid2 == 0)
		second_child_process(argv, envp, fd);
	close_fds(fd, 2);
	wait_and_check(pid1);
	return (wait_and_check(pid2));
}

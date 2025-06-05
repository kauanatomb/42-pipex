/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:01:43 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/05 14:48:06 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>     // open, O_RDONLY etc.
# include <sys/types.h>
# include <sys/stat.h>  // open
# include <stdio.h>     // perror
# include <sys/wait.h>
# include "libft.h"

char	*find_command_path(char *cmd, char **envp);
void	child_process(char **argv, char **envp, int *fd);
void	second_child_process(char **argv, char **envp, int *fd);
int		wait_and_check(pid_t pid);
void	close_fds(int *fds, int count);
void	free_split(char **paths);
void	error_exit(const char *msg);

#endif

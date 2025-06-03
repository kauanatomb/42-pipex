/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:01:43 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/03 12:15:28 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
    (void)envp;
    int infile_fd;
    int outfile_fd;
    int pipefd[2];
    int v_pipe;
    pid_t   pid;
    pid_t   pid2;
    if (argc != 5)
        return (ft_printf("Arguments error.\n"), 1);
    infile_fd = open(argv[1], O_RDONLY);
    if (infile_fd < 0)
        return (perror("Infile error"), 1);
    
    outfile_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (outfile_fd < 0)
        return (perror("Outfile error"), 1);
    v_pipe = pipe(pipefd);
    if (v_pipe == -1)
        return (perror("Pipe error"), 1);
    pid = fork();
    if (pid < 0)
        return (perror("Fork error"), 1);
    else if (pid == 0)
    {
        //son process
        dup2(infile_fd, STDIN_FILENO);
        dup2(pipefd[1], STDOUT_FILENO);
        close(infile_fd);
        close(pipefd[0]);
        close(pipefd[1]);
        close(outfile_fd);
        char **args = ft_split(argv[2], ' ');
        char *cmd_path = find_command_path(args[0], envp);
        if (!cmd_path)
        {
            ft_printf("Command not found: %s\n", args[0]);
            exit(EXIT_FAILURE);
        }
        execve(cmd_path, args, envp);
        perror("Execve failed");
        exit(EXIT_FAILURE);
    }
    else
    {
        //father process
        pid2 = fork();
        if (pid2 < 0)
            return (perror("Fork error"), 1);
        else if (pid2 == 0)
        {
            //son process
            dup2(pipefd[0], STDIN_FILENO);
            dup2(outfile_fd, STDOUT_FILENO);
            close(infile_fd);
            close(pipefd[0]);
            close(pipefd[1]);
            close(outfile_fd);
            char **args = ft_split(argv[3], ' ');
            char *cmd_path = find_command_path(args[0], envp);
            if (!cmd_path)
            {
                ft_printf("Command not found: %s\n", args[0]);
                exit(EXIT_FAILURE);
            }
            execve(cmd_path, args, envp);
            perror("Execve failed");
            exit(EXIT_FAILURE);
        }
        else
        {
            //father process
            close(infile_fd);
            close(pipefd[0]);
            close(pipefd[1]);
            close(outfile_fd);
            waitpid(pid, NULL, 0);
            waitpid(pid2, NULL, 0);
        }
    }
    return (0);
}
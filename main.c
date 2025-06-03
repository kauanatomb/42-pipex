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
    ft_printf("pipefd[0] (read end): %d\n", pipefd[0]);
    ft_printf("pipefd[1] (write end): %d\n", pipefd[1]);
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:01:43 by ktombola          #+#    #+#             */
/*   Updated: 2025/06/03 13:12:03 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path_from_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

void	free_split(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
}

static char	*search_in_paths(char **paths, char *cmd)
{
	int		i;
	char	*full_path;
	char	*tmp;

	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin(paths[i], "/");
		tmp = full_path;
		full_path = ft_strjoin(full_path, cmd);
		free(tmp);
		if (access(full_path, X_OK) == 0)
		{
			free_split(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_split(paths);
	return (NULL);
}

char	*find_command_path(char *cmd, char **envp)
{
	char	*path_env;
	char	**paths;

	path_env = get_path_from_env(envp);
	if (!path_env)
		return (NULL);
	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (access(cmd, X_OK) == 0)
			return (cmd);
		return (NULL);
	}
	paths = ft_split(path_env, ':');
	return (search_in_paths(paths, cmd));
}

void	close_fds(int *fds, int count)
{
	int		i;

	i = 0;
	while (i < count)
		close(fds[i++]);
}

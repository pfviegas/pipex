/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:53:32 by pviegas           #+#    #+#             */
/*   Updated: 2023/07/26 15:43:38 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	execute(char *cmd, char **envp)
{
	char	**full_cmd;
	char	*path;
	int		i;

	full_cmd = ft_split(cmd, ' ');
	cmd = *full_cmd;
	path = search_cmd(envp, cmd);
	if (!path)
	{
		i = 0;
		while (full_cmd[i])
		{
			free(full_cmd[i]);
			i++;
		}
		free(full_cmd);
		error();
	}
	if (execve(path, full_cmd, envp) == -1)
		error();
}

char	*search_cmd(char **envp, char *cmd)
{
	int		i;
	char	*path;
	char	*temp;
	char	**paths;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	paths = ft_split(path, ':');
	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, F_OK) != -1)
		{
			free_paths(paths);
			return (path);
		}
		free(path);
	}
	free_paths(paths);
	return (cmd);
}

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

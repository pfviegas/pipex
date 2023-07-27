/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:53:32 by pviegas           #+#    #+#             */
/*   Updated: 2023/07/27 14:02:03 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	close_pipe(int *fds)
{
	close(fds[0]);
	close(fds[1]);
}

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	if (!paths)
		return ;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

void	execute(char *cmd, char **envp, int *dup_fd)
{
	char	**full_cmd;
	char	*path;
	int		i;

	full_cmd = ft_split(cmd, ' ');
	cmd = *full_cmd;
	path = extract_path(envp, cmd);
	if (!path)
	{
		free_paths(full_cmd);
		close_pipe(dup_fd);
		error("command not found");
	}
	if (execve(path, full_cmd, envp) == -1)
	{
		free_paths(full_cmd);
		close_pipe(dup_fd);
		error(NULL);
	}
}

char *extract_path(char **envp, char *cmd)
{
	int i;
	char *path;
	char *temp;
	char **paths;

	i = 0;
	if (!cmd || ft_strchr(cmd, '/') != NULL)
		return (cmd);

	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;

	path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	paths = ft_split(path, ':');
	path = search_cmd(cmd, paths);
	return (path);
}
char *search_cmd(char *cmd, char **paths)
{
	int i = 0;
	char *temp;
	char *path;

	if (!paths[0])
		return (NULL);
	while (paths[i])
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
		i++;
	}
	free_paths(paths);
	return (NULL);
}

void	error(char *msg)
{
	if (!msg)
		perror("pipex");
	else
		ft_printf("pipex: %s\n", msg);
	exit(EXIT_FAILURE);
}

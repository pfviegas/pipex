/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:53:32 by pviegas           #+#    #+#             */
/*   Updated: 2023/07/25 17:03:55 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// check if arguments are valid
char	*check_args(char **argv, char **envp)
{
	char	*path;

	check_file(argv[1]);
//	path = check_path(envp);
	return (path);
}

// check if file is readable
void	check_file(const char *file) 
{
	if (access(file, R_OK) != 0)
	{
		ft_printf("%s: %s\n", strerror(errno), file);
		exit(1);
	}
}

// search for PATH in envp
// if not found return the path pre-defined
char	*check_path(char **env)
{
	char	*path;

	while (ft_strncmp("PATH", *env, 4))
		env++;

	path = *env + 5;
	if (path == NULL)
		path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:.";
	return (path);
}

void	error(int err)
{
	perror("Error");
	exit(err);
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
	free (path);
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, cmd);
		if (access(path, F_OK) != -1)
			return (path);
		free(temp);
		free(path);
		i++;
	}
	free_paths(paths);
	return (cmd);
}
void	execute(char *cmd, char **envp)
{
	char	**exec_cmd;
	char	*path;
	int		k;

	exec_cmd = ft_split(cmd, ' ');
	cmd = *exec_cmd;
	path = search_cmd(envp, cmd);
	if (!path)
	{
		k = 0;
		while (exec_cmd[k])
		{	
			free(exec_cmd[k]);
			k++;
		}
		free(exec_cmd);
		error(5);
	}
	if (execve(path, exec_cmd, envp) == -1)
		error(6);
}

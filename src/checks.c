/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:53:32 by pviegas           #+#    #+#             */
/*   Updated: 2023/07/25 16:01:27 by pviegas          ###   ########.fr       */
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
void	execute(char *cmd, char **envp)
{
	char *const argv[] = { "ls", "-l", NULL };
	ft_printf("executing: %s\n", cmd);
/*
	int	i = 0;
	ft_printf("\nENVP:\n");
	while (envp[i])
	{
		ft_printf("%s\n", envp[i]);
		i++;
	}
*/
//	char	**exec_cmd;
	char	*path;
	int		k;

//	exec_cmd = ft_split(cmd, ' ');
//	cmd = *exec_cmd;
	path = check_path(envp);
	ft_printf("\n%s\n", path);
	if (execve("/bin/ls", argv, envp) == -1) 
	{
        perror("Erro ao executar o programa");
        exit(2);
    }
/*	
	if (execve(path, &cmd, envp) == -1)
		error(6);
*/
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:53:32 by pviegas           #+#    #+#             */
/*   Updated: 2023/07/24 17:03:35 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// check if arguments are valid
char	*check_args(char **argv, char **envp)
{
	char *path;

	check_file(argv[1]);
	path = check_path(envp);
	return (path);
}

// check if file is readable
void	check_file(const char *file) 
{
	if (access(file, R_OK) != 0)
	{
		printf("%s: %s\n", strerror(errno), file);
		exit(1);
	}
}

// search for PATH in envp
// if found, return the path pre-defined
char	*check_path(char **env)
{
	char	*path;

	while (strncmp("PATH", *env, 4))
		env++;

	path = *env + 5;
	if (path == NULL)
		path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:.";
	return (path);
}
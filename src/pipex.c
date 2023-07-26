/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:43:50 by pviegas           #+#    #+#             */
/*   Updated: 2023/07/26 14:45:47 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	child_1(char **argv, int *pipe_fd, char **envp)
{
	int	infile;

	close(pipe_fd[0]);
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		error();
	dup2(pipe_fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	execute(argv[2], envp);
}

static void	child_2(char **argv, int *pipe_fd, char **envp)
{
	int	outfile;

	close(pipe_fd[1]);
	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		error();
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid_1;
	pid_t	pid_2;
	int		stat;

	if (argc != 5)
	{
		ft_printf("Error: Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	if (pipe(pipe_fd) < 0)
		error();
	pid_1 = fork();
	if (pid_1 < 0)
		error();
	if (pid_1 == 0)
		child_1(argv, pipe_fd, envp);
	pid_2 = fork();
	if (pid_2 < 0)
		error();
	if (pid_2 == 0)
		child_2(argv, pipe_fd, envp);
	waitpid(-1, &stat, 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:43:50 by pviegas           #+#    #+#             */
/*   Updated: 2023/07/28 14:16:25 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error(char *msg)
{
	if (!msg)
		perror("pipex");
	else
		ft_printf("pipex: %s\n", msg);
	exit(EXIT_FAILURE);
}

void	check_args(int argc)
{
	if (argc != 5)
	{
		ft_printf("Error: Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
}

static void	child_1(char **argv, int *pipe_fd, char **envp)
{
	int	infile;
	int	dups[2];

	close(pipe_fd[0]);
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		error(NULL);
	dups[0] = dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	dups[1] = dup2(infile, STDIN_FILENO);
	close(infile);
	execute(argv[2], envp, dups);
}

static void	child_2(char **argv, int *pipe_fd, char **envp)
{
	int	outfile;
	int	dups[2];

	close(pipe_fd[1]);
	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		error(NULL);
	dups[0] = dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	dups[1] = dup2(outfile, STDOUT_FILENO);
	close(outfile);
	execute(argv[3], envp, dups);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid_1;
	pid_t	pid_2;
	int		stat;

	check_args(argc);
	if (pipe(pipe_fd) < 0)
		error(NULL);
	pid_1 = fork();
	if (pid_1 < 0)
		error(NULL);
	if (pid_1 == 0)
		child_1(argv, pipe_fd, envp);
	close(pipe_fd[1]);
	pid_2 = fork();
	if (pid_2 < 0)
		error(NULL);
	if (pid_2 == 0)
		child_2(argv, pipe_fd, envp);
	close(pipe_fd[0]);
	waitpid(-1, &stat, 0);
	waitpid(-1, &stat, 0);
	return (0);
}

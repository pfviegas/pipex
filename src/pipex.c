/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:43:50 by pviegas           #+#    #+#             */
/*   Updated: 2023/07/25 13:48:59 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child1_process(char **argv, int *pipe_fd, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		error(4);
	close(pipe_fd[0]);
	dup2(infile, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	execute(argv[2], envp);
}

void	child2_process(char **argv, int *pipe_fd, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		error(7);
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid_1;
	pid_t	pid_2;
	int		status;	

	if (argc != 5)
	{
		ft_printf("Error: Wrong number of arguments\n");
		return (1);
	}
	if (pipe(pipe_fd) < 0)
		error(1);
	pid_1 = fork();
	if (pid_1 < 0)
		error(2);
	if (pid_1 == 0)
		child1_process(argv, pipe_fd, envp);
	pid_2 = fork();
	if (pid_2 < 0)
		error(3);
	if (pid_2 == 0)
		child2_process(argv, pipe_fd, envp);
	waitpid(-1, &status, 0);
	return (0);
}

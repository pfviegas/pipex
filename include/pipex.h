/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:02:37 by pviegas           #+#    #+#             */
/*   Updated: 2023/07/26 14:51:03 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>

# include "../libft/libft.h"

static void	child_1(char **argv, int *pipe_fd, char **envp);
static void	child_2(char **argv, int *pipe_fd, char **envp);
void	execute(char *cmd, char **envp);
char	*search_cmd(char **envp, char *cmd);
void	free_paths(char **paths);
void	error(void);

#endif
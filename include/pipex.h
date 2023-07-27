/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:02:37 by pviegas           #+#    #+#             */
/*   Updated: 2023/07/27 11:41:14 by pviegas          ###   ########.fr       */
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
void		execute(char *cmd, char **envp, int *dup_fd);
char		*search_cmd(char **envp, char *cmd);
void		free_paths(char **paths);
void		error(char *msg);

#endif
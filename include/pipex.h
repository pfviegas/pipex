/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:02:37 by pviegas           #+#    #+#             */
/*   Updated: 2023/08/15 15:53:30 by pviegas          ###   ########.fr       */
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

void		error(char *msg);
void		check_args(int argc);
void		child_1(char **argv, int *pipe_fd, char **envp);
void		child_2(char **argv, int *pipe_fd, char **envp);
void		close_pipe(int *fds);
void		free_paths(char **paths);
void		execute(char *cmd, char **envp, int *dup_fd);
char		*extract_path(char **envp, char *cmd);
char		*search_cmd(char *cmd, char **paths);

#endif

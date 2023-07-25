/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:02:37 by pviegas           #+#    #+#             */
/*   Updated: 2023/07/25 13:48:37 by pviegas          ###   ########.fr       */
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

char	*check_args(char **argv, char **envp);
void	check_file(const char *file);
char	*check_path(char **env);
void	error(int err);
void	execute(char *cmd, char **envp);

#endif
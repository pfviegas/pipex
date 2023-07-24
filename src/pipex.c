/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:43:50 by pviegas           #+#    #+#             */
/*   Updated: 2023/07/24 17:02:46 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char *path;
	/*
	printf("\nENVP:\n");
	while (*envp)
	{
		printf("%s\n", *envp);
		envp++;
	}
	*/
	if (argc != 5)
	{
		ft_printf("Error: Wrong number of arguments\n");
		return (1);
	}
	path = check_args(argv, envp);
	ft_printf("\nPATH:\n%s\n", path);
/*
    char *binaryPath = "/bin/ls"; // Substitua esse caminho pelo programa que deseja executar
    char *args[] = {binaryPath, "-la", NULL}; // Argumentos para o programa a ser executado
    
//    char *envp[] = {NULL}; // Array de ambiente vazio

    // Executa o programa indicado por binaryPath com os argumentos e ambiente fornecidos
    if (execve(binaryPath, args, envp) == -1) {
        perror("Erro ao executar o programa");
        return 1;
    }

    // Esta parte só será executada se o execve falhar, o que não deve acontecer neste exemplo.
    printf("Execução do programa concluída.\n");
*/
	return (0);
}

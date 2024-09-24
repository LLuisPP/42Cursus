/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:25:04 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/24 19:21:59 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Bucle principal del shell que gestiona la entrada del usuario y ejecuta comandos */
void	shell_loop(t_env *env, t_msh *msh)
{
	char	*input;
	char	*token;
	(void)env;
	// (void)token;
	// int		i;
	while (msh->end_sig == 0)
	{
		rl_attempted_completion_function = cmd_comp;
		input = readline("\033[1;96m👽 Space 🛸 shell $\e[0m> ");
		if (input == NULL)
			break ;
		if (*input)
			add_history(input);
		
	// 	tokenize_input(input, msh); // nueva función que tokeniza y guarda en msh->tkns
		
	// 	printf("%s\n", env->pwd);
	// 	printf("%s\n", msh->env->home);
	// 	// printf("%s\n", msh->env->values[1]);
	
	// 	// i = 0;
	// 	// while (i < 1)
	// 	// {
	// 	// 	printf("%s", msh->tkns->args[i]);
	// 	// 	i++;	
	// 	// }
	// 	free(input);
	// }
		
		token = ft_strtok(input, " \t\n");
		while (token != NULL) /* Este bucle es para pruebas, aqui va el lexer y executer */
		{
			if (ft_strcmp("pwd", token) == 0) /* pwd */
				printf("%s\n", env->pwd);			
			if (ft_strcmp("pwd2", token) == 0) /* pwd */
				printf("%s\n", msh->env->pwd);
			if (ft_strcmp("clearh", token) == 0) /* borra el historial */
				clear_history();
			if (ft_strcmp("clear", token) == 0) /* clear :D */
				printf("%s", CLEAR);
			// if (ft_strcmp("echo", token) == 0) /* Esto no va a funcionar por el tokenizador */
			// 	ft_echo(argv);
			if (ft_strcmp("exit", token) == 0) /* para hacer exit sin ctrl+C */
				msh->end_sig = 1;
			if (ft_strcmp("home", token) == 0)
				printf("%s\n", env->home);
		//	if (ft_strncmp("ls", input, 2))     /* execve rompe el bucle, hace exit */
		//		execve("/bin/ls", argv, NULL);
			free(token);
			token = ft_strtok(NULL, " \t\n");
		}
		free(input);
	}
}

/* Función principal que inicializa el entorno y estructuras, y lanza el bucle del shell */
int	main(int argc, char **argv, char **envs)
{
	t_env	*env;
	t_msh	msh;
	t_exe	*mpip;
	t_tok	*tok = NULL;

	if (argc != 1 || argv[1])
		exit (ft_fd_printf(2, "%s", E_EXECARG) * 0);
	ft_memset(&msh, 0, sizeof(t_msh));
	if (init_structs(&env, envs, &msh, &mpip, &tok) != 0)
		return (ft_fd_printf(2, "%s", E_MEMASF)* -1);
	init_env(env, envs); /* inicia el env, ya sea con el env del sistema o sin el */
	shell_loop(env, &msh); /* Este es el loop principal, que esta en la funcion shell_loop */
	free_structs(env, tok, mpip); /* Libera las estructuras que le pasemos */
	return (0);
}

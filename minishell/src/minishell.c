/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:25:04 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/30 18:43:51 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Bucle principal del shell que gestiona la entrada del usuario y ejecuta comandos */
void	shell_loop(t_msh *msh)
{
	char	*input;
	int		i;
	int		j;

	while (msh->end_sig == 0)
	{
		i = 0;
		rl_attempted_completion_function = cmd_comp;
		input = readline("\033[0;96mspace 👽 shell 🛸\e[0m> ");
		if (input == NULL)
			break ;
		if (*input)
			add_history(input);
		
		tokenize_input(input, msh);

		while (msh->tkns[i].cmd != NULL) /* este bucle hace print de tods los tokens */
		{
			printf("%s\n", msh->tkns[i].cmd);
			i++;
		}
		if (ft_strcmp("pwd", msh->tkns[0].cmd) == 0) /* pwd */
			printf("%s\n", msh->env->pwd);			
		if (ft_strcmp("clear", msh->tkns[0].cmd) == 0) /* clear :D */
		 	printf("%s", CLEAR);
		if (ft_strcmp("exit", msh->tkns[0].cmd) == 0) /* para hacer exit sin ctrl+C */
			msh->end_sig = 1;
		free(input);
		j = 0;
		while (j < i)
		{	
			free(msh->tkns[j].cmd);
			j++;	
		}
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
	if (init_strc(&env, &msh, &mpip, &tok) != 0)
		return (ft_fd_printf(2, "%s", E_MEMASF)* -1);
	if (envs != NULL)
		msh.envs = envs;
	init_env(env, &msh); /* inicia el env, ya sea con el env del sistema o sin el */
	shell_loop(&msh); /* Este es el loop principal, que esta en la funcion shell_loop */
	free_structs(env, tok, mpip); /* Libera las estructuras que le pasemos */
	return (0);
}

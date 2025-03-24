/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:25:04 by lprieto-          #+#    #+#             */
/*   Updated: 2025/03/16 18:58:23 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Bucle principal gestiona la entrada del usuario y ejecuta comandos */
void	shell_loop(t_msh *msh)
{
	char	*input;

	while (msh->end_sig == 0)
	{
		input = readline("\033[0;96m🛸 Space_shell 👽:\e[0m");
		if (!input)
			msh->end_sig = 1;
		else
			add_history(input);
		if (ft_strlen(input) > 0)
			check_tokens(input, msh);
		free(input);
	}
}

int	main(int argc, char **argv, char **envs)
{
	t_env	*env;
	t_msh	msh;
	t_exe	*mpip;
	t_tok	*tok;

	tok = NULL;
	if (argc != 1 || argv[1])
		exit (ft_fd_printf(2, "%s", E_EXECARG) * 0);
	ft_memset(&msh, 0, sizeof(t_msh));
	msh.envs = envs;
	if (init_structs(&env, &msh, &mpip, &tok) != TRUE)
		return (ft_fd_printf(2, "%s", E_MEMASF));
	if (envs != NULL)
		msh.envs = envs;
	msh.env_var_count = env_var_count(&msh);
	env_init_values(env, &msh);
	init_signals();
	shell_loop(&msh);
	free_structs(env, tok, mpip);
	return (msh.last_exit_code);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frol_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:43:55 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/17 20:28:44 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	err_end(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_printf("\n");
	ft_printf("   ╔═══════════════════════ SYNTAX PROTOTYPE ═══╗\n");
	ft_printf("   ║                                            ║\n");
	ft_printf("   ║    >>>>>>  ./fractol [fractal]   <<<<<<    ║\n");
	ft_printf("   ║                                            ║\n");
	ft_printf("   ║   Julia case:                              ║\n");
	ft_printf("   ║   ./fractol Julia [int param] [int param]  ║\n");
	ft_printf("   ║                                            ║\n");
	ft_printf("   ╚════════════════════════════════════════════╝\n");
	ft_printf("   ╔═══════════════ [fractal] COLLECTION SET ═══╗\n");
	ft_printf("   ║                                            ║\n");
	ft_printf("   ║     Mandelbrot  ||  Tricorn  ||  Julia     ║\n");
	ft_printf("   ║                                            ║\n");
	ft_printf("   ╚════════════════════════════════════════════╝\n");
	ft_printf("   ╔════════════════════════ SYNTAX EXAMPLES ═══╗\n");
	ft_printf("   ║                                            ║\n");
	ft_printf("   ║    ./fractol Mandelbrot    +   ↩ (return)  ║\n");
	ft_printf("   ║    ./fractol Julia 0 -1    +   ↩ (return)  ║\n");
	ft_printf("   ║    ./fractol Tricorn       +   ↩ (return)  ║\n");
	ft_printf("   ║                                            ║\n");
	ft_printf("   ╚════════════════════════════════════════════╝\n");
	exit(0);
}


int	arg_is_int(int argc, char **argv)
{
	int	i;
	int	j;

	i = 2;
	while (i < argc)
	{
		j = 0;
		if (argv[i] == NULL || !argv[i] || argv[i][j] == '\0')
			return (0);
		if (argv[i][j] == '-' && (ft_isdigit(argv[i][j + 1]) == 1))
			j++;
		if (argv[i][j] == '+' && (ft_isdigit(argv[i][j + 1]) == 1))
			j++;
		while (ft_isdigit(argv[i][j]) == 1 && argv[i][j] != '\0')
			j++;
		if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int	exit_click(void)
{
	ft_printf("\n   ╔ X ════════════ WINDOW CLOSED ════════════════╗\n");
	ft_printf("   ║                                              ║\n");
	ft_printf("   ║   HOPE YOU ENJOYED // Feb 2024 // lprieto-   ║\n");
	ft_printf("   ║                                              ║\n");
	ft_printf("   ╚══════════════ FRACTOL FINISHED ══════════════╝\n");
	exit(1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frol_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:43:55 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/16 08:57:09 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	err_end(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_printf("\n");
	ft_printf("   ╔═                                          ═╗\n");
	ft_printf("   ║    Syntax prototype: ./fractol [fractal]   ║\n");
	ft_printf("   ║      -     -     -     -      -     -      ║\n");
	ft_printf("   ║ [fractal] = Mandelbrot || Julia || Tricorn ║\n");
	ft_printf("   ╚═                                          ═╝\n");
	exit(0);
}

int	exit_click(void)
{
	ft_printf("\n╔════════════════ WINDOW CLOSED ═══════════════╗\n\n");
	ft_printf("║                               ..             ║\n");
	ft_printf("║                             .:+:-.           ║\n");
	ft_printf("║                           ..::*=:..          ║\n");
	ft_printf("║                        ....::####:...        ║\n");
	ft_printf("║                     ...-=::--*##=-::::=.     ║\n");
	ft_printf("║                   ....::##############=.     ║\n");
	ft_printf("║             ........::#░#############░:.     ║\n");
	ft_printf("║           ..:#::=::::-##################     ║\n");
	ft_printf("║         ....::*#####=##################+     ║\n");
	ft_printf("║     ......:==##########################.     ║\n");
	ft_printf("║   :::#:===+############ lprieto- ####-:.     ║\n");
	ft_printf("║      .....:--##########################:     ║\n");
	ft_printf("║          ...::*#####-##################+     ║\n");
	ft_printf("║            .:=::-::::=#################░     ║\n");
	ft_printf("║             .........:#+#############+:.     ║\n");
	ft_printf("║                   ....::#############░+.     ║\n");
	ft_printf("║                      ..:-:::-###=:::..:.     ║\n");
	ft_printf("║                        ....::####:...        ║\n");
	ft_printf("║                           ...:-=:..          ║\n");
	ft_printf("║                             .:#::.           ║\n\n");
	ft_printf("╚══════════════ FRACTOL FINISHED ══════════════╝\n");
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frol_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:26:05 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/19 12:20:05 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_display(t_f *f)
{
	if (ft_strncmp(f->name, "Julia", 5) == 0)
		julia_ascii();
	if (ft_strncmp(f->name, "Mandelbrot", 10) == 0)
		mandelbrot_ascii();
	if (ft_strncmp(f->name, "Tricorn", 10) == 0)
		tricorn_ascii();
	menu_optns();
}

void	menu_optns(void)
{
	ft_printf("\n ╔═ CONTROL KEYS ═╦════════════════╦════════════════╗\n");
	ft_printf(" ║   ╔══╝         ║ ╔═▲═╗    shift ║ ╔═▲═╗  ▲ shift ║\n");
	ft_printf(" ║   ║   scroll ▲ ║ ║ D ║ => color ║ ║ K ║     up   ║\n");
	ft_printf(" ║   ║   zoom in  ║ ╚═══╝     up   ║ ╚═══╝   shape  ║\n");
	ft_printf(" ║ ╔═▲═╗          ║ ═  ═  ═  ═  ═  ║ ═  ═  ═  ═  ═  ║\n");
	ft_printf(" ║ ║═▼═║ scroll ▼ ║ ╔═══╗    shift ║ ╔═══╗  ▼ shift ║\n");
	ft_printf(" ║ ║   ║ zoom out ║ ║ C ║ => color ║ ║ M ║    down  ║\n");
	ft_printf(" ║ ╚═══╝          ║ ╚═▼═╝    down  ║ ╚═▼═╝   shape  ║\n");
	ft_printf(" ╚══════ MANDELBROT + TRICORN ═════╩════ JULIA ═════╝\n");
	ft_printf("     WARNING!: shifting colors could affect you\n");
}

void	mandelbrot_ascii(void)
{
	ft_printf("\n   ╔════════════════ MANDELBROT ══════════════════╗\n");
	ft_printf("   ║                                              ║\n");
	ft_printf("   ║                               ..             ║\n");
	ft_printf("   ║                             .:+:-.           ║\n");
	ft_printf("   ║                           ..::*=:..          ║\n");
	ft_printf("   ║                        ....::####:...        ║\n");
	ft_printf("   ║                     ...-=::--*##=-::::=.     ║\n");
	ft_printf("   ║                   ....::##############=.     ║\n");
	ft_printf("   ║             ........::#░#############░:.     ║\n");
	ft_printf("   ║           ..:#::=::::-##################     ║\n");
	ft_printf("   ║         ....::*#####=##################+     ║\n");
	ft_printf("   ║     ......:==##########################.     ║\n");
	ft_printf("   ║   :::#:===+############ lprieto- ####-:.     ║\n");
	ft_printf("   ║      .....:--##########################:     ║\n");
	ft_printf("   ║          ...::*#####-##################+     ║\n");
	ft_printf("   ║            .:=::-::::=#################░     ║\n");
	ft_printf("   ║             .........:#+#############+:.     ║\n");
	ft_printf("   ║                   ....::#############░+.     ║\n");
	ft_printf("   ║                      ..:-:::-###=:::..:.     ║\n");
	ft_printf("   ║                        ....::####:...        ║\n");
	ft_printf("   ║                           ...:-=:..          ║\n");
	ft_printf("   ║                             .:#::.           ║\n");
	ft_printf("   ║                                              ║\n");
	ft_printf("   ╚══════════════════════════════════════════════╝\n");
}

void	julia_ascii(void)
{
	ft_printf("\n╔════════════════════════ JULIA ═══════════════════════╗\n");
	ft_printf("║                                                      ║\n");
	ft_printf("║  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ║\n");
	ft_printf("║  @@@@@@@@@@*,,,,,,,,,,,,,,*,,,,,,,,,,,,,,*@@@@@@@@@  ║\n");
	ft_printf("║  @@@@,,,,,,,,,,,,,,*/////////////,,,,,,,,,,,,,,#@@@  ║\n");
	ft_printf("║  @*,,,,,,,,,,*//////////((@/(//////////,,,,,,,,,,,@  ║\n");
	ft_printf("║  ,,,,,,*///////////(*/(/#(@(#*(*/(///////////,,,,,,  ║\n");
	ft_printf("║  ,/////(,((*/**/(*/(@@/d@@@@@(&&((//(/*///((,//////  ║\n");
	ft_printf("║  /@@@#@@@@@@@@@d@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#  ║\n");
	ft_printf("║  */////(,((((/,,**#/@@@@@@@@@(&&#(#**,,(((((,(/////  ║\n");
	ft_printf("║  ,,,,,,/////////////**///#@((//,/(////////////,,,,,  ║\n");
	ft_printf("║  @*,,,,,,,,,,///////////((@*(//////////*,,,,,,,,,,@  ║\n");
	ft_printf("║  @@@@,,,,,,,,,,,,,,///////(///////,,,,,,,,,,,,,,@@@  ║\n");
	ft_printf("║  @@@@@@@@@/,,,,,,,,,,, lprieto- ,,,,,,,,,,@@@@@@@@@  ║\n");
	ft_printf("║                                                      ║\n");
	ft_printf("╚══════════════════════════════════════════════════════╝\n");
}

void	tricorn_ascii(void)
{
	ft_printf("\n╔═══════════════════════ TRICORN ══════════════════════╗\n");
	ft_printf("║                                                      ║\n");
	ft_printf("║  .......................(((((......................  ║\n");
	ft_printf("║  ............../(((((((((((((((((((((/.............  ║\n");
	ft_printf("║  ........../((((((((((((((((((((,,,,//,/,(.........  ║\n");
	ft_printf("║  ........((((((((((((((((((((,,,,,/#(,/,,(((/......  ║\n");
	ft_printf("║  ......(((((((((((((((((((,,,,,,/.((.#,,,((((((....  ║\n");
	ft_printf("║  ....((((((((((((((((((,,,,,,/#/&@@/,,,,,(((((((...  ║\n");
	ft_printf("║  ...(((((((((((((((,,,,,,,//#.(@@@(,/,,,,((((((((/.  ║\n");
	ft_printf("║  ..((((((((((,,,,,,,,,,///#,/@@@@/#/,,,,((((((((((/  ║\n");
	ft_printf("║  .((((,,,,,,,,,,,.////#,.#(@@@@@.#//,,,,(((((((((((  ║\n");
	ft_printf("║  .(,,,,,./(/,/#(,,/(/(#@@@@@@@#/##/,,,,((((((((((((  ║\n");
	ft_printf("║  .#,/#(###@@@@@@ lprieto- @@@@(/#//,,,,((((((((((((  ║\n");
	ft_printf("║  .(((/////,(//###@@@@@@@@@@@@@//#//,,,,((((((((((((  ║\n");
	ft_printf("║  .(((((/##,(////#///#/((@@@@@@//#//,,,,((((((((((((  ║\n");
	ft_printf("║  ..((((((((,,,,,,,,,,,///#,/@@@@/,#/,,,,(((((((((((  ║\n");
	ft_printf("║  ..(((((((((((((((,,,,,,,.//#/@@@@(#/,,,.(((((((((.  ║\n");
	ft_printf("║  ....(((((((((((((((((,,,,,,./,(@@@.,,,,,((((((((..  ║\n");
	ft_printf("║  .....(((((((((((((((((((,,,,,,/./##.#,,,((((((....  ║\n");
	ft_printf("║  ..........((((((((((((((((((((,,,,//.//,((((......  ║\n");
	ft_printf("║  ..........((((((((((((((((((((,,,,//.//,(.........  ║\n");
	ft_printf("║  ................./((((((((((((((((.,,.............  ║\n");
	ft_printf("║                                                      ║\n");
	ft_printf("╚══════════════════════════════════════════════════════╝\n");
}

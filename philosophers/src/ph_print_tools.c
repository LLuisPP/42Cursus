/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_print_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:30:54 by lprieto-          #+#    #+#             */
/*   Updated: 2024/08/12 19:54:26 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	info(char c)
{
	if (c == 'a')
		printf("Error: wrong arg #nbr\n");
	if (c == 'd')
		printf("Error:  wrong arg/s\n");
	if (c == 'h')
		handling();
	if (c == 'v')
		printf("Error -> var init failure\n");
	if (c == 't')
		printf("Error -> thread creation failed\n");
	if (c == 'm')
		printf("Error -> thread monitor failed\n");
	if (c == 'k')
		printf("Error -> thread checker failed\n");
	return (-1);
}

void	handling(void)
{
	printf("\n");
	printf(" ╔══ PHILO HANDLING ══════════════════════════════╗\n");
	printf(" ║                                                ║\n");
	printf(" ║ ▐░▐░▐░ ./philo [philo][die][eat][sleep][meals] ║\n");
	printf(" ║ ▐░▐░▐░           ⇓      ⇓    ⇓     ⇓     ⇓     ║\n");
	printf(" ║ █▄█▄█░          prm1   prm2 prm3  prm4  prm5   ║\n");
	printf(" ║   █░             ⇓      ⇓    ⇓     ⇓     ⇓     ║\n");
	printf(" ║   █░            nbr    nbr  nbr   nbr   nbr    ║\n");
	printf(" ║   █░                                           ║\n");
	printf(" ║   █░   Ex: ./philo 5 400  500  200             ║\n");
	printf(" ║   █░       ./philo 6 200  400  100  3          ║\n");
	printf(" ║                                                ║\n");
	printf(" ╚════════════════════════════════════════════════╝\n");
}

void	initfeast(int argc, char **argv)
{
	printf("\n%s\n", "╔═ PHILOSOPHERS FEAST IS READY ══╗");
	printf("║\n%s %s\n", "║     _ .--. _     | philos:", argv[1]);
	printf("║   .'   %sP1%s   '.   |\n", GR, F);
	printf("║  · %sF1%s  ()  %sF2%s ·  | die: %s\n", BL, F, BL, F, argv[2]);
	printf("║ .              . |\n");
	printf("║ |%sP4%s ()    () %sP2%s| | eat: %s\n", GR, F, GR, F, argv[3]);
	printf("║ .              . |\n");
	printf("║  · %sF4%s  ()  %sF3%s ·  | sleep: %s\n", BL, F, BL, F, argv[4]);
	printf("║   '._  %sP3%s  _.'   |\n", GR, F);
	if (argc == 5)
		printf("║       '--'       | meals: ∞\n║\n");
	else
		printf("║       '--'       | meals: %s\n║\n", argv[5]);
	printf("╚════════════════════════════════╝\n\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg_select.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:03:28 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/28 15:36:49 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* chnk_size cuts the chunk in the size sent and pushes to b till s_size a 5 */

void	chnk_size(t_stack **stack_a, t_stack **stack_b, int s_size ,int strt, int chunk)
{
	int valor;

	valor = 0;
	while (strt <= (s_size - 5) && stack_size(*stack_a) > 5)
	{
		while (stack_size(*stack_b) <= strt  && stack_size(*stack_a) > 5)
		{
			// ft_printf("|v|v|v|v|v|v|v|v|v|v|v|v|v|v|v|v|v|v|v|v|v| STACK SIZE A |---->%d\n", stack_size(*stack_a));
			// ft_printf("SIZEEEEEEEE MOTHERFUCKER!! :     %d // %d\n", s_size, strt);
			if ((*stack_a)->index <= strt && stack_size(*stack_b) <= strt)
			{
					ft_printf("[]---->%d\n", stack_size(*stack_a));
					push_b(stack_a, stack_b);
					ft_printf("[]---->%d\n", stack_size(*stack_a));

				if (stack_size(*stack_b) == strt)
				{
					ft_printf("++ %d ++,++ %d ++,++ %d ++,++ %d ++,STRT\n", strt, strt, strt, strt);
					ft_printf("++++++++++++++++++++++++++++++++++++++++++++ STACK SIZE A |---->%d\n", stack_size(*stack_a));
					strt = strt + chunk;
					ft_printf("++ %d ++,++ %d ++,++ %d ++,++ %d ++,STRT\n", strt, strt, strt, strt);
					ft_printf("▶ ▶ ▶ ▶ ▶ ▶ NEW START ▶ ▶ ▶ ▶ ▶ ▶ ▶ CHECK: %d\n", strt);
				}
			}
			else
			{
				if ((f_chk_v(*stack_a, strt) != f_chk_vr(*stack_a, strt)) && stack_size(*stack_b) < strt)
				{
							ft_printf("| ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? | %d vs %d |\n", f_chk_v(*stack_a, strt), f_chk_vr(*stack_a, strt));
					if (cheaper_mv(stack_a, cheaper_fr(stack_a, f_chk_v(*stack_a, strt), f_chk_vr(*stack_a, strt))) == 0)
							rev_rot_a(stack_a);
					else if (cheaper_mv(stack_a, cheaper_fr(stack_a, f_chk_v(*stack_a, strt), f_chk_vr(*stack_a, strt))) == 1)
					{
							rot_a(stack_a);
					}
				}
				if ((f_chk_v(*stack_a, strt) == f_chk_vr(*stack_a, strt)) && stack_size(*stack_b) < strt)
				{
					ft_printf("| = = = = = = = = = = = = = = = = | %d vs %d |\n", f_chk_v(*stack_a, strt), f_chk_vr(*stack_a, strt));
					valor = f_chk_v(*stack_a, strt);
					ft_printf("| = = = = = = = = = = = = = = = = | %d vs %d |\n", f_chk_v(*stack_a, strt), f_chk_vr(*stack_a, strt));
					if (cheaper_mv(stack_a, valor) == 0)
						{
							ft_printf("|--------| WOOOP WOOP is the sound of the police |\n");
							ft_printf("| = = = = = = = = = = = = = = = = | %d vs %d |\n", f_chk_v(*stack_a, strt), f_chk_vr(*stack_a, strt));
							ft_printf("▶ ▶ ▶ ▶ ▶ ▶ WTF ▶ ▶ ▶ ▶ ▶ ▶ ▶ CHECK: %d\n", strt);
						rev_rot_a(stack_a);
							ft_printf("LlLlLlLLlLl£¢££¢£∞§¶•¶§∞¢£∞§¶•ª¶§∞¢∞§¶•ª¶§∞¢§¶•ªºª•¶§¶¨¥†¢£™¢∞®†¥©˙√∫µ∆˚˙∫µ≤");

						}
					else if (cheaper_mv(stack_a, valor) != 0)
							// ft_printf("▶ ▶ ▶ ▶ ▶ ▶ CAGADA ▶ ▶ ▶ ▶ ▶ ▶ ▶ CHECK: %d\n", strt);
						rot_a(stack_a);
							// ft_printf("▶ ▶ ▶ ▶ ▶ ▶ CAGADA2 ▶ ▶ ▶ ▶ ▶ ▶ ▶ CHECK: %d\n", strt);
					else if ((*stack_a)->index <= strt)
					{
							ft_printf("[]---->%d\n", stack_size(*stack_a));
						push_b(stack_a, stack_b);
							ft_printf("[]---->%d\n", stack_size(*stack_a));

						if (stack_size(*stack_b) == strt)
						{
								ft_printf("++ %d ++,++ %d ++,++ %d ++,++ %d ++,STRT\n", strt, strt, strt, strt);
								ft_printf("++++++++++++++++++++++++++++++++++++++++++++ STACK SIZE A |---->%d\n", stack_size(*stack_a));
							strt = strt + chunk;
							ft_printf("++ %d ++,++ %d ++,++ %d ++,++ %d ++,STRT\n", strt, strt, strt, strt);
							ft_printf("▶ ▶ ▶ ▶ ▶ ▶ NEW START ▶ ▶ ▶ ▶ ▶ ▶ ▶ CHECK: %d\n", strt);
						}
					}
				}
			}
		}
		
	}
	// alg_5(stack_a, stack_b);
	// print_status(*stack_a, *stack_b);
}

/* alg_selector choose better algorithm depending on stack_size */
void	alg_selector(t_stack **stack_a, t_stack **stack_b, int s_size)
{
	if (s_size <= 3)
		alg_3(stack_a);
	if (s_size == 4 && stack_rev_order(*stack_a) != 1)
		alg_4(stack_a, stack_b);
	if (s_size == 4 && stack_rev_order(*stack_a) == 1)
		alg_4_rev(stack_a);
	if (s_size == 5 && stack_rev_order(*stack_a) != 1)
		alg_5(stack_a, stack_b);
	if (s_size == 5 && stack_rev_order(*stack_a) == 1)
		alg_5_rev(stack_a, stack_b);
	if (s_size > 5 && s_size <= 10)
		alg_10(stack_a, stack_b, s_size);
	if (s_size > 10 && s_size <= 50)
		alg_50(stack_a, stack_b, s_size);
	if (s_size > 50 && s_size <= 100)
		alg_100(stack_a, stack_b, s_size);
	if (s_size > 100 && s_size <= 500)
		alg_100(stack_a, stack_b, s_size);
}
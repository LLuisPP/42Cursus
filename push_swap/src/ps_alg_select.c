/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg_select.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:03:28 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/07 10:29:25 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* chnk_size cuts the chnk in the size sent and pushes to b till s_size a 5 */

void	chnk_size(t_s **s_a, t_s **s_b, int strt, int chnk)
{
	int	size;

	size = s_size(*s_a);
	while (strt <= (size - 5) && s_size(*s_a) > 5)
	{
		if ((*s_a)->idx <= strt && s_size(*s_b) <= strt)
			push_b(s_a, s_b);
		if (s_size(*s_b) == strt)
			strt = strt + chnk;
		else
			chnk_sizeb(s_a, s_b, strt);
	}
}

void	chnk_sizeb(t_s **s_a, t_s **s_b, int strt)
{
	if ((chk_v(*s_a, strt) != chk_vr(*s_a, strt)) && s_size(*s_b) < strt)
	{
		if (chp_m(s_a, chp_v(s_a, chk_v(*s_a, strt), chk_vr(*s_a, strt)))
			== 0)
			rev_rot_a(s_a);
		else if (chp_m(s_a, chp_v(s_a, chk_v(*s_a, strt), chk_vr(*s_a, strt)))
			== 1)
			rot_a(s_a);
	}
	if ((chk_v(*s_a, strt) == chk_vr(*s_a, strt)) && s_size(*s_b) < strt)
	{
		if (chp_m(s_a, chk_v(*s_a, strt)) == 0)
			rev_rot_a(s_a);
		else if (chp_m(s_a, chk_v(*s_a, strt)) != 0)
			rot_a(s_a);
	}
}

/* alg_selector choose better algorithm depending on size */
void	alg_selector(t_s **s_a, t_s **s_b, int size)
{
	if (size <= 3)
		alg_3(s_a);
	if (size == 4 && s_rev_order(*s_a) != 1)
		alg_4(s_a, s_b);
	if (size == 4 && s_rev_order(*s_a) == 1)
		alg_4_rev(s_a);
	if (size == 5 && s_rev_order(*s_a) != 1)
		alg_5(s_a, s_b);
	if (size == 5 && s_rev_order(*s_a) == 1)
		alg_5_rev(s_a, s_b);
	if (size > 5 && size <= 10)
		alg_10(s_a, s_b, size);
	if (size > 10 && size <= 50)
		alg_50(s_a, s_b, size);
	if (size > 50 && size <= 100)
		alg_100(s_a, s_b, size);
	if (size > 100)
		alg_500(s_a, s_b, size);
}

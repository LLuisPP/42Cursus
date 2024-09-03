/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:01:15 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/01 10:46:58 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* error_end output msg error after checking all ss are clearead */
void	error_end(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(0);
}

/* print_s to print complete s to identify problems */
void	print_s(t_s *s)
{
	ft_printf("╰➤ ");
	while (s != NULL)
	{
		ft_printf("%d ", s->val);
		s = s->nxt;
	}
	ft_printf("\n");
}

void	print_status(t_s *s_a, t_s *s_b)
{
	ft_printf("╔═══════ ◀═\n");
	ft_printf("║ s a -> ");
	print_s(s_a);
	ft_printf("║ s b -> ");
	print_s(s_b);
	ft_printf("╚═══════ ═▶\n");
}

void	print_idx_status(t_s *s)
{
	ft_printf("║ SORTED I-I-I-I iiii -> ");
	while (s != NULL)
	{
		ft_printf("%d ", s->idx);
		s = s->nxt;
	}
	ft_printf("\n");
}

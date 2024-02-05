/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:45:28 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/01 10:32:54 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_s
{
	int				val;
	int				idx;
	struct s_s		*prv;
	struct s_s		*nxt;
}	t_s;

/* MAIN * * * * * * * * * * * * * * * * * */
void	push_swap(t_s **s_a, t_s **s_b, int size);

/* CHECKERS * * * * * * * * * * * * * * * */
int		arg_is_int(int argc, char **argv);
int		arg_range(int argc, char **argv);
int		arg_duplicate(int argc, char **argv);
int		arg_order(int argc, char **argv);
int		checkers(int argc, char **argv);

/* SWAP * * * * * * * * * * * * * * * */
void	swap_a(t_s **s_a);
void	swap_b(t_s **s_b);
void	swap_both(t_s **s_a, t_s **s_b);
/* PUSH * * * * * * * * * * * * * * * */
void	push_a(t_s **s_a, t_s **s_b);
void	push_b(t_s **s_a, t_s **s_b);
/* ROT * * * * * * * * * * * * * * * */
void	rot_a(t_s **s_a);
void	rot_b(t_s **s_b);
void	rot_both(t_s **s_a, t_s **s_b);
/* REV_ROT * * * * * * * * * * * * * * * */
void	rev_rot_a(t_s **s_a);
void	rev_rot_b(t_s **s_b);
void	rev_rot_both(t_s **s_a, t_s **s_b);

/* ALG_SELECTOR * * * * * * * * * * * * * * */
void	chnk_size(t_s **s_a, t_s **s_b, int strt, int chnk);
void	chnk_sizeb(t_s **s_a, t_s **s_b, int strt);
void	alg_selector(t_s **s_a, t_s **s_b, int size);

/* ALGORITHMS * * * * * * * * * * * * * * * */
void	alg_3(t_s **s_a);
void	alg_4(t_s **s_a, t_s **s_b);
void	alg_4_rev(t_s **s_a);
void	alg_5(t_s **s_a, t_s **s_b);
void	alg_5_rev(t_s **s_a, t_s **s_b);
void	alg_10(t_s **s_a, t_s **s_b, int size);
void	alg_10b(t_s **s_a, t_s **s_b);
void	alg_50(t_s **s_a, t_s **s_b, int size);
void	alg_100(t_s **s_a, t_s **s_b, int size);
void	alg_500(t_s **s_a, t_s **s_b, int size);

/* INDEX * * * * * * * * * * * * * * * * */
void	idx_s(t_s *s, int i);
int		all_idxed(t_s **s);
int		find_h_i(t_s *s);
int		find_l_i(t_s **s);

/* RANGE * * * * * * * * * * * * * * * * */
int		f_lowidx(t_s **s);
int		find_lowest(t_s *s);
int		find_highest(t_s *s);
int		f_last(t_s *s);

/* OPTIMIZER * * * * * * * * * * * * * * */
int		chp_v(t_s **s, int trgeta, int trgetb);
int		front_loop(t_s **s, int trgeta);
int		reverse_loop(t_s **s, int trgetb);

/* PRINT_TOOLS * * * * * * * * * * * * * */
void	error_end(char *msg);
void	print_s(t_s *s);
void	print_status(t_s *s_a, t_s *s_b);
void	print_idx_status(t_s *s);

/* STACKS * * * * * * * * * * * * * * * * */
void	free_s(t_s **s);
void	s_add(t_s **s, t_s *new_n);
void	get_nbrs(int argc, char **argv, t_s **s);
int		s_size(t_s *s);
void	s_add_top(t_s **s, t_s *new_n);

/* VALIDATE * * * * * * * * * * * * * * * */
int		s_rev_order(t_s *s);
int		s_order(t_s *s);
int		chp_m(t_s **s, int trgt);
int		chk_v(t_s *s, int strt);
int		chk_vr(t_s *s, int i);

/* ALG_50 * * * * * * * * * * * * * * * * */
void	chka_rcv(t_s **s_a, t_s **s_b);
void	chka_qut(t_s **s_a, t_s **s_b);
void	nohighatend(t_s **s_a, t_s **s_b);
void	highatend(t_s **s_a, t_s **s_b);

#endif
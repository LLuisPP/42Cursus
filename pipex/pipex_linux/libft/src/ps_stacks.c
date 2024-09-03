/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:21:23 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/01 06:51:53 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* free_s frees every element and set the pointer to NULL */
void	free_s(t_s **s)
{
	t_s	*tmp;

	if (!s || !(*s))
		return ;
	while (*s)
	{
		tmp = (*s)->nxt;
		free(*s);
		*s = tmp;
	}
	*s = NULL;
}

/* s_add adds new vals to a s */
void	s_add(t_s **s, t_s *new_nd)
{
	t_s	*curr;

	if (!new_nd)
		return ;
	if (!*s)
		*s = new_nd;
	else
	{
		curr = *s;
		while (curr->nxt != NULL)
		{
			curr = curr->nxt;
		}
		curr->nxt = new_nd;
		new_nd->prv = curr;
	}
}

/* get_nbrs fill the s and checks if its correct */
void	get_nbrs(int argc, char **argv, t_s **s)
{
	long	i;
	int		val;
	t_s		*new_nd;

	i = 1;
	while (i < argc)
	{
		val = ft_atoi(argv[i]);
		new_nd = malloc(sizeof(t_s));
		if (!new_nd)
			error_end("Error\n");
		new_nd->val = val;
		new_nd->idx = 0;
		new_nd->nxt = NULL;
		s_add(s, new_nd);
		i++;
	}
}

/* get_size counts elements in a s */
int	s_size(t_s *s)
{
	int	size;
	t_s	*temp;

	temp = s;
	size = 0;
	if (!temp)
		return (0);
	while (temp && temp != NULL)
	{
		size++;
		temp = temp->nxt;
	}
	return (size);
}

/* s_add adds new vals to a s */
void	s_add_top(t_s **s, t_s *new_nd)
{
	if (!new_nd)
		return ;
	if (!*s)
		*s = new_nd;
	else
	{
		new_nd->nxt = *s;
		(*s)->prv = new_nd;
		*s = new_nd;
	}
}

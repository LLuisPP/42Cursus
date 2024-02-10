/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:58:25 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/10 14:58:25 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstlast(t_list *lst)
{
    while (lst)
    {
        if (!lst->next)
            return (lst);
        lst = lst->next;
    }
    return (lst);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *last;

    if (lst)
    {
        if (*lst)
        {
            last = ft_lstlast(*lst);
            last->next = new;
        }
        else
            *lst = new;
    }
}
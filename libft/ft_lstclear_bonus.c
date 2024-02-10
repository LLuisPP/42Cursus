/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:53:41 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/10 15:53:41 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (!del)
        return ;
    if (lst)
    {
        (*del)(lst->content);
        free(lst);
    }
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list  *tmp;

    if (!del || !lst || !*lst)
        return ;
    while (lst && *lst)
    {
        tmp = (*lst)->next;
        ft_lstdelone(*lst, del);
        *lst = tmp;
    }
}
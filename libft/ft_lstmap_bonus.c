/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:02:25 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/10 16:02:25 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstnew(void *content)
{
    t_list  *new_node;

    new_node = (t_list*)malloc(sizeof(t_list *));
    if (!new_node)
        return (NULL);
    new_node->content = content;
    new_node->next = NULL;
    return (new_node);
}

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

static void    ft_lstadd_back(t_list **lst, t_list *new)
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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *first;
    t_list  *new;

    if (!f || !del)
        return (NULL);
    first = NULL;
    while (lst)
    {
        if (!((new) = ft_lstnew((*f)(lst->content))))
        {
            while (first)
            {
                new = first->next;
                (*del)(first->content);
                free(first);
                first = new;
            }
            lst = NULL;
            return (NULL);
        }
        ft_lstadd_back(&first, new);
        lst = lst->next;
    }
}
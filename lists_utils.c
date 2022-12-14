/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:20:30 by hlesny            #+#    #+#             */
/*   Updated: 2022/12/14 21:53:17 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"
#include <stddef.h>

t_elem    *ft_new_elem(int a)
{
    t_elem *new;

    new = malloc(sizeof(t_elem));
    if (!new)
        return (NULL);
    new->nb = a;
    new->prev = NULL;
    new->next = NULL;
    return (new);
}

t_fl    *ft_init_fl(void)
{
    t_fl *fl;
    t_elem *first;
    t_elem *last; 
    
    fl = malloc(sizeof(t_fl));
    first = ft_new_elem(0);
    last = ft_new_elem(0);
    if (!fl || !first || !last)
        return (NULL);
    fl->first = first;
    fl->first = last;
    return (fl);
}

void    ft_add_back(t_fl *fl, t_elem *new) // *fl equivalent a **first et **last
{
    if (!fl)
        return ;
    if (!fl->last) // ou !fl->first,ie si la liste est actuellement vide, et que va seulement ajouter le premier element
    {
        fl->last = new;
        fl->first = new;
    }
    else
    {
        fl->last->next = new;
        fl->last = new;
    }
}

void    ft_del_last(t_fl *fl)
{
    t_elem *tmp;

    if (!fl || !fl->last)
        return;
    tmp = fl->last;
    fl->last = fl->last->prev; // l'avant dernier devient le dernier
    free(tmp); // free "l'ancien dernier"
}

void    ft_clear(t_fl *fl)
{
    
}
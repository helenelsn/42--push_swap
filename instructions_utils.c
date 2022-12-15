/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:54:14 by hlesny            #+#    #+#             */
/*   Updated: 2022/12/15 15:20:39 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_utils.h"

// aura un fl par pile dans le code central

// Intervertit les 2 premiers éléments au sommet de la pile. Ne fait rien s’il n’y en a qu’un ou aucun.
void    ft_swap(t_fl *fl) 
{
    t_elem *tmp;
    
    if (!fl)
        return ;
    if (!fl->first || !fl->last || !ft_lst_size(fl))
        return ;
    tmp = fl->last; // dernier element, qui va devenir l'avant dernier
    fl->last = fl->last->prev; // met a jour *last
    fl->last->prev = tmp->prev->prev;
    fl->last->prev->next = tmp; // reordonne la fin de la liste 
    tmp->prev = fl->last->prev->next;
    tmp->next = fl->last;

    free(tmp);
}

// push a : Prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.
void    ft_push(t_fl *fl_a, t_fl *fl_b)
{
    t_elem *tmp;

    if (!fl_a || !fl_b)
        return ;
    if (!ft_lst_size(fl_a)) // ie si a est vide
        return ;
    tmp = fl_a->last; // element de la pile_a a deplacer sur la pile_b
    fl_a->last = fl_a->last->prev; // met a jour *last de la pile_a
    ft_add_back(fl_b, tmp); // rajoute l element au sommet (ie fin de liste) de la pile_b
    free(tmp);
}

//Décale d’une position vers le haut tous les élements de la pile. Le premier élément devient le dernier.
void    ft_rotate(t_fl *fl)
{
    t_elem *tmp;
    t_elem *tmp2;

    if (!fl || ft_lst_size(fl) < 2) // si fl null, ou si la pile a moins de deux elements 
        return ;
    tmp = fl->first;
    tmp2 = fl->last;
    fl->first = fl->first->next;
    fl->last = tmp;
    fl->last->prev = tmp2;
    fl->last->next = NULL;
    free(tmp);
}

// Décale d’une position vers le bas tous les élements de la pile. Le dernier élément devient le premier.
void    ft_rev_rotate(t_fl *fl)
{
    t_elem *tmp;
    t_elem *tmp2;

    if (!fl || ft_lst_size(fl) < 2) // si fl null, ou si la pile a moins de deux elements 
        return ;
    
}


void    double_swap(t_fl *fl_a, t_fl *fl_b) // utile ? pas sure
{
    
}

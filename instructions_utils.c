/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:54:14 by hlesny            #+#    #+#             */
/*   Updated: 2022/12/16 22:21:09 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_utils.h"
#include <stdlib.h>

// aura un fl par pile dans le code central

// Intervertit les 2 premiers éléments au sommet de la pile (ie a la find de la liste). 
// Ne fait rien s’il n’y en a qu’un ou aucun.
void    ft_swap(t_fl *fl, int a) 
{
    t_elem *tmp;
    
    if (!fl)
        return ;
    if (a)
        printf("sa\n");
    else
        printf("sb\n");  
    if (!fl->first || !fl->last || !ft_lst_size(fl))
        return ;
    /*
    tmp = fl->last; // dernier element, qui va devenir l'avant dernier
    fl->last = fl->last->prev; // met a jour *last
    fl->last->prev->next = tmp; // reordonne la fin de la liste 
    //fl->last->prev = tmp;//->prev->prev;
    tmp->next = fl->last;
    //tmp->prev = 
    fl->last->next = NULL;
    */

    tmp = fl->last;
    fl->last = fl->last->prev;
    tmp->prev = fl->last->prev;
    tmp->next = fl->last;
    fl->last->next = NULL;
    fl->last->prev->next = tmp;
    fl->last->prev = tmp;
    
    //free(tmp);
    
}

// push a : Prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.
void    ft_push(t_fl *fl_a, t_fl *fl_b, int a)
{
    t_elem *tmp;
    t_elem *tmpb;

    if (!fl_a || !fl_b)
        return ;
    if (a)
        printf("pa\n");
    else
        printf("pb\n");  
    if (!ft_lst_size(fl_a)) // ie si a est vide
        return ;
    
    tmp = fl_a->last;
    tmpb = fl_b->last;
    if (ft_lst_size(fl_a) == 1)
    {
        fl_a->first = NULL;
        fl_a->last = NULL;
    }
    else
    {
        fl_a->last = fl_a->last->prev;
        fl_a->last->next = NULL;
    }
    if (!ft_lst_size(fl_b)) // ie si b est vide
    {
        fl_b->last = tmp;
        fl_b->first = tmp;
    }
    else
    {
        fl_b->last->next = tmp;
        fl_b->last = tmp;
        fl_b->last->prev = tmpb;
    }
}

// Décale d’une position vers le haut tous les élements de la pile. 
// Le dernier élément de la liste devient le premier.
void    ft_rotate(t_fl *fl, int a)
{
    t_elem *tmp;

    if (!fl || !fl->first || !fl->last || ft_lst_size(fl) < 2)
        return ;
    if (a)
        printf("ra\n");
    else
        printf("rb\n");  
        
    tmp = fl->last;
    
    fl->last = fl->last->prev;
    fl->last->next = NULL;
    tmp->next = fl->first;
    tmp->prev = NULL;
    fl->first = tmp;
}

// Décale d’une position vers le bas tous les élements de la pile. 
// Le premier élément de la liste devient le dernier.
void    ft_rev_rotate(t_fl *fl, int a)
{
    t_elem *tmp;

    if (!fl || ft_lst_size(fl) < 2) // si fl null, ou si la pile a moins de deux elements 
        return ;
    if (a)
        printf("rra\n");
    else
        printf("rrb\n");  
        
    tmp = fl->first;
    
    fl->first = fl->first->next;
    fl->first->prev = NULL;
    
    tmp->prev = fl->last;
    fl->last->next = tmp;
    
    fl->last = tmp;
    fl->last->next = NULL;
}


void    double_swap(t_fl *fl_a, t_fl *fl_b) // utile ? pas sure
{
    
}

/*
    tmp = fl->first;
    tmp2 = fl->last;
    fl->first = fl->first->next;
    fl->last = tmp;
    fl->last->prev = tmp2;
    fl->last->next = NULL;
    free(tmp);
    */
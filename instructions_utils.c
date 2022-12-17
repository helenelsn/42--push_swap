/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:54:14 by hlesny            #+#    #+#             */
/*   Updated: 2022/12/17 04:59:04 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_utils.h"
#include <stdlib.h>

// aura un fl par pile dans le code central

// Intervertit les 2 premiers éléments au sommet de la pile (ie a la find de la liste). 
// Ne fait rien s’il n’y en a qu’un ou aucun.
void    ft_swap(t_elem **first, int a) 
{
    t_elem *tmp1;
    t_elem *tmp2;
    
    if (!first || !*first || ft_lst_size(first) < 2)
        return ;
    if (a)
        printf("sa\n");
    else
        printf("sb\n"); 
    
    tmp2 = (*first)->prev;
    tmp1 = (*first)->prev->prev;
    tmp1->prev->next = tmp2;
    tmp2->prev = tmp1->prev;
    tmp1->prev = tmp2;
    tmp1->next = *first;
    tmp2->next = tmp1;
    (*first)->prev = tmp1;
        
    /*
    tmp = fl->last;
    fl->last = fl->last->prev;
    tmp->prev = fl->last->prev;
    tmp->next = fl->last;
    fl->last->next = NULL;
    fl->last->prev->next = tmp;
    fl->last->prev = tmp;
    
    tmp = fl->first;
    fl->first = fl->first->next;
    tmp->next = fl->first->next;
    tmp->prev = fl->first;
    fl->first->next->prev = tmp;
    fl->first->next = tmp;
    fl->first->prev = NULL;
    */
}

// push a : Prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.
void    ft_push(t_elem **node_a, t_elem **node_b, int a)
{
    t_elem *tmp;

    if (!node_a || !*node_a || !node_b|| !ft_lst_size(node_a))
        return ;
    if (a)
        printf("pa\n");
    else
        printf("pb\n");  
        
    tmp = (*node_a)->prev;
    if (ft_lst_size(node_a) == 1)
        *node_a = NULL;
    else
    {
        (*node_a)->prev = (*node_a)->prev->prev;
        (*node_a)->prev->next = *node_a;
    }
    ft_add_back(node_b, tmp);
}

// Décale d’une position vers le haut tous les élements de la pile. 
// Le dernier élément de la liste devient le premier.
void    ft_rotate(t_elem **node, int a)
{
    if (!node || !*node || ft_lst_size(node) < 2)
        return ;
    if (a)
        printf("ra\n");
    else
        printf("rb\n");  
    *node = (*node)->prev;
}

// Décale d’une position vers le bas tous les élements de la pile. 
// Le premier élément de la liste devient le dernier.
void    ft_rev_rotate(t_elem **node, int a)
{
    if (!node || !*node || ft_lst_size(node) < 2)
        return ;
    if (a)
        printf("rra\n");
    else
        printf("rrb\n");  
    *node = (*node)->next;
}

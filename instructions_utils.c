/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:54:14 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/02 16:27:45 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_utils.h"
#include <stdlib.h>


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
    else if (!a)
        printf("sb\n"); 
    
    /*
    tmp2 = (*first)->prev;
    tmp1 = (*first)->prev->prev;
    tmp1->prev->next = tmp2;
    tmp2->prev = tmp1->prev;
    tmp1->prev = tmp2;
    tmp1->next = *first;
    tmp2->next = tmp1;
    (*first)->prev = tmp1;
    */

    tmp1 = *first; // le premier element de la liste est l'element au sommet de la pile (le premier argument)
    tmp2 = (*first)->next;
    tmp1->prev->next = tmp2;
    tmp2->prev = tmp1->prev;
    tmp1->prev = tmp2;
    tmp1->next = tmp2->next;
    tmp2->next = tmp1;
    (*first) = tmp2;
}


// push a : Prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.
void    ft_push(t_elem **node_a, t_elem **node_b, int a)
{
    t_elem *tmp;

    if (!node_a || !*node_a || !node_b|| !ft_lst_size(node_a))
        return ;
    if (a)
        printf("pa\n");
    else if (!a)
        printf("pb\n");  
        
    tmp = *node_a;
    if (ft_lst_size(node_a) == 1)
            *node_a = NULL;
    else
    {
        *node_a = (*node_a)->next;
        tmp->prev->next = *node_a;
        (*node_a)->prev = tmp->prev;
    }
    ft_add_back(node_b, tmp);
}


// Décale d’une position vers le haut tous les élements de la pile. 
// Le premier élément de la liste devient le dernier.
void    ft_rotate(t_elem **node, int a)
{
    if (!node || !*node || ft_lst_size(node) < 2)
        return ;
    if (a)
        printf("ra\n");
    else if (!a)
        printf("rb\n");  
    *node = (*node)->next;
}

void    ft_rrotate(t_elem **node_a, t_elem **node_b)
{
    ft_rotate(node_a, 2);
    ft_rotate(node_b, 2);
    printf("rr\n");
}

// Décale d’une position vers le bas tous les élements de la pile. 
// Le dernier élément de la liste devient le premier.
void    ft_rev_rotate(t_elem **node, int a)
{
    if (!node || !*node || ft_lst_size(node) < 2)
        return ;
    if (a)
        printf("rra\n");
    else if (!a)
        printf("rrb\n");  
    *node = (*node)->prev;
}

void    ft_rrev_rotate(t_elem **node_a, t_elem **node_b)
{
    ft_rev_rotate(node_a, 2);
    ft_rev_rotate(node_b, 2);
    printf("rrr\n");
}

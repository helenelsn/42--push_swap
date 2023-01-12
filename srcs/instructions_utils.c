/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:54:14 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/12 20:20:56 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/instructions_utils.h"
#include <stdlib.h>


// Intervertit les 2 premiers éléments au sommet de la pile (ie a la find de la liste). 
// Ne fait rien s’il n’y en a qu’un ou aucun.
void    ft_swap(t_elem **first, int a) 
{
    t_elem *tmp1;
    t_elem *tmp2;
    
    if (!first || !*first || ft_lst_size(first) < 2)
        return ;
    if (a == 1)
        printf("sa\n");
    else if (!a)
        printf("sb\n"); 

    tmp1 = *first; // le premier element de la liste est l'element au sommet de la pile (le premier argument)
    tmp2 = (*first)->next;
    tmp1->prev->next = tmp2;
    tmp2->prev = tmp1->prev;
    tmp1->prev = tmp2;
    tmp1->next = tmp2->next;
    tmp2->next->prev = tmp1;
    tmp2->next = tmp1;
    (*first) = tmp2;
}


// push b : Prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.
void    ft_push(t_elem **src, t_elem **dest, int a)
{
    t_elem *tmp;

    if (!src || !*src || !dest|| !ft_lst_size(src))
        return ;
    if (a == 1)
        printf("pa\n");
    else if (!a)
        printf("pb\n");  
        
    tmp = *src;
    if (ft_lst_size(src) == 1)
            *src = NULL; // est-ce aue ca met aussi tmp a NULL ? car ne veut pas ca
    else
    {
        *src = (*src)->next;
        tmp->prev->next = *src;
        (*src)->prev = tmp->prev;
    }
    ft_add_front(dest, tmp);
}


// Décale d’une position vers le haut tous les élements de la pile. 
// Le premier élément de la liste devient le dernier.
void    ft_rotate(t_elem **node, t_moves *moves, int a)
{
    if (!node || !*node || ft_lst_size(node) < 2)
        return ;
    else if (a == 1)
    {
        printf("ra\n");
        if (moves && moves->ra)
            moves->ra--;
    }
    else if (!a)
    {
        printf("rb\n");
        if (moves && moves->rb)
            moves->rb--;
    }
    *node = (*node)->next;
}

void    ft_rrotate(t_elem **node_a, t_elem **node_b, t_moves *moves)
{
    ft_rotate(node_a, moves, 2);
    ft_rotate(node_b, moves, 2);
    if (moves)
    {
        moves->ra--;
        moves->rb--;
    }
    printf("rr\n");
}

// Décale d’une position vers le bas tous les élements de la pile. 
// Le dernier élément de la liste devient le premier.
void    ft_rev_rotate(t_elem **node, t_moves *moves, int a)
{
    if (!node || !*node || ft_lst_size(node) < 2)
        return ;
    else if (a == 1)
    {
        printf("rra\n");
        if (moves && moves->rra)
            moves->rra--;
    }
    else if (!a)
    {
        printf("rrb\n");
        if (moves && moves->rrb)
            moves->rrb--;
    }
    *node = (*node)->prev;
}

void    ft_rrev_rotate(t_elem **node_a, t_elem **node_b, t_moves *moves)
{
    ft_rev_rotate(node_a, moves, 2);
    ft_rev_rotate(node_b, moves, 2);
    if (moves)
    {
        moves->rra--;
        moves->rrb--;
    }
    printf("rrr\n");
}

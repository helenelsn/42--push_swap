/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:54:14 by hlesny            #+#    #+#             */
/*   Updated: 2022/12/15 11:52:40 by hlesny           ###   ########.fr       */
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

void    double_swap(t_fl *fl_a, t_fl *fl_b) // utile ? pas sure
{

}

// push b : Prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.
void    ft_push(t_fl *fl_a, t_fl *fl_b)
{

}

//Décale d’une position vers le haut tous les élements de la pile. Le premier élément devient le dernier.
void    ft_rotate(t_fl *fl)
{
    
}

// Décale d’une position vers le bas tous les élements de la pile. Le dernier élément devient le premier.
void    ft_rev_rotate(t_fl *fl)
{
    
}
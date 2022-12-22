/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 04:14:47 by hlesny            #+#    #+#             */
/*   Updated: 2022/12/22 05:53:42 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "instructions_utils.h"

// max (a, b) = min (-a, -b)
int min(int a, int b)
{
    if (a > b)
        return (b);
    return (a);
}

void    get_cost(t_elem **node_a, t_elem **node_b, int nb, int pos, t_moves *moves_current)
{
    int pos_b;
    t_moves moves_inproved;
    t_elem *current_b;
    
    pos_b = 0;
    init_moves(moves_inproved);
    current_b = *node_b;
    while (current_b->nb < nb && current_b->next != *node_b)
    {
        pos_b++;
        current_b = current_b->next;
    }
    // commence par ra & rb
    /*
    cas 1 : cost_min = max(ra, rb)
    cas 2 : cost_min = max(rra, rrb)
    cas 3 : cost_min = ra + rrb
    cas 4 : cost_min = rra + rb
    */
}

void    get_min_cost(t_elem **node_a, t_elem **node_b, t_moves *moves)
{
    t_moves moves_current;
    t_elem *current_a;
    int position;

    position = 0;
    current_a = *node_a;
    while (current_a->next != *node_a)
    {
        init_moves(&moves_current);
        get_cost(node_a, node_b, current_a->nb, position, &moves_current);
        if (moves_current.cost < moves->cost)
            *moves = moves_current; // = marche avec les structs
        position++;
        current_a = current_a->next;
    }
}


void    move_data(t_elem **node_a, t_elem **node_b)
{
    t_moves moves;
   
    init_moves(&moves);
    get_min_cost(node_a, node_b, &moves);
}

void    sort_data(t_elem **node_a, t_elem **node_b)
{
    ft_push(node_a, node_b, 1);    
    ft_push(node_a, node_b, 1);
    
    while (ft_lst_size(node_a))
        move_data(node_a, node_b);
}
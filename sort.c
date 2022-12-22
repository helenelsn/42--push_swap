/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 04:14:47 by hlesny            #+#    #+#             */
/*   Updated: 2022/12/23 00:29:00 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "instructions_utils.h"

// max (a, b) = min (-a, -b)
int ft_min(int a, int b)
{
    if (a > b)
        return (b);
    return (a);
}

int     in_range(int a, int b, int n) // [a, b[
{
    int i = a;

    while (i < b)
    {
        if (i == n)
            return (1);
        i++;
    }
    return (0);
}

void    test_cases(int len_a, int len_b, t_moves *moves)
{
    int min;
    int nb_case;
    // tab[6] = [rr, ra, rb, rrr, rra, rrb]
    int rr =  ft_min(ra, rb);
    int rrr =  ft_min(rra, rrb);
    int tab[2][6] = {{rr, ra != rr, rb != rr, 0, 0, 0},
                    {0,0,0, rrr, rra != rrr, rrb != rrr}};
    int i = -1;
    while (++i < 2)
    {
        min = tab[i][0]*rr + tab[i][1]+tab[i][2]+tab[i][3]+tab[i][4]+tab[i][5];
        
    }
    moves->cost = -ft_min(-ra, -rb); // ie max(ra, rb)
    nb_case = 0;
    min = -ft_min(-rra, -rrb)
    if (cost > -in)
        nb_case = 1
    else
        min =
        //
        
        
    
}

void    get_cost(t_elem **node_a, t_elem **node_b, int nb, int pos_a, t_moves *moves_current)
{
    int pos_b;
    t_moves moves_inproved;
    t_elem *current_b;
    
    int min_b = 0, max_b = 0;
    pos_b = 0;
    init_moves(moves_inproved);
    current_b = *node_b;
    if (nb <= min_b || nb >= max_b)
    {
        while (current_b->nb != min_b && current_b->next != *node_b)
        {
            pos_b++;
            current_b = current_b->next;
        }
    }
    else
    {
        while (current_b->next != *node_b && !in_range(current_b->prev->nb, current_b->nb, nb))
        {
            pos_b++;
            current_b = current_b->next;
        }
    }
    moves_current->pos_b = pos_b;
    test_cases(ft_lst_size(node_a), ft_lst_size(node_b), moves_current);
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
        init_moves(&moves_current, position);
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
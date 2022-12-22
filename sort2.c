/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:23:10 by hlesny            #+#    #+#             */
/*   Updated: 2022/12/22 03:48:50 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* insertion sort :
- sorted list : pile b, initialement vide
- unsorted list : pile a

partially sort a and then use shell sort or quicksort ?

quicksort to partially sort the list, and then insertion sort to finish the sort?
*/

#include "instructions_utils.h"

int     get_cost(t_elem **node_a, t_elem **node_b, int nb_current, int i)
{
    t_elem *current_b;
    int cost[2];
    int cost_b;
    int len_a;
    int len_b;

    // si *node_b = NULL, alors n'a aucun element dans b 
    // (ce cas de figure ne devrait jamais arriver car l'on effectue tjr deux pa avant de calculer les couts pour le reste de node_a)
    if (!node_a || !*node_a || !node_b)
        return (-1);
    cost[0] = 1; // pa
    cost_b = 0;
    current_b = *node_b;
    len_a = ft_lst_size(node_a);
    len_b = ft_lst_size(node_b);
    if (i > len_a / 2)
        cost[0] += i;
    else
        cost[0] += (len_a - i); 
    while (current_b->nb < nb_current && current_b->next != *node_b)
    {
        cost_b++;
        current_b = current_b->next;
    }
    if (cost_b > len_b / 2)
    {
        cost[1] = 1; // devra rev reverse b
        cost_b = len_b - cost_b;
    }
    else
        cost[1] = 0; // devra reverse b
    cost[0] += cost_b;
    return (cost);
}


int    *helpwhichonedoipush(t_elem **node_a, t_elem **node_b) // determine le nombre d'instructions necessaires pour un element 
{
    t_elem *current;
    t_elem *current_min;
    int costs[2]; // position dans la liste de l'element a push, et cout total
    int cost_min;
    int cost_current;
    int i;
    
    if (!node_a || !*node_a)
        return (-1);
    
    i = 0;
    cost_min = 0;
    cost_current = 0;
    current_min = *node_a;
    
    // calculer pour *node_a separement au debut
    
    current = (*node_a)->next;
    while (current && current != *node_a)
    {
        cost_current = get_cost(node_a, node_b, current->nb, i);
        if (cost_current < cost_min)
        {
            cost_min = cost_current;
            current_min = current;
            costs[0] = i;   
        }
        i++;
        current = current->next;
    }
    costs[1] = cost_min;
    return (costs);
}

void    make_move(t_elem **node_a, t_elem **node_b, int cost[2]) // cost[0] = position dans la liste de l'element a push, cost[1] = cout total
{
    int len_a;
    int len_b;
    int cost_b;

    cost_b = cost[1] - (1 + cost[0]);
    len_a = ft_lst_size(node_a);
    len_b = ft_lst_size(node_b);
    if (cost[0] < len_a / 2)
    {
        while (cost[0])
        {
            ft_rotate(node_a, 1);
            cost[0]--;
        }
    }
    else
    {
        while (len_a > cost[0] -1)
        {
            ft_rev_rotate(node_a, 1);
            cost[0]++;
        }
    }
    if (cost_b < len_b / 2)
    {
        while (cost_b)
        {
            ft_rotate(node_b, 0);
            cost_b--;
        }
    }
    else
    {
        while (len_b > cost_b -1)
        {
            ft_rev_rotate(node_b, 0);
            cost_b++;
        }
    }
    ft_push(node_a, node_b, 1);
}

void    sort_data(t_elem **node_a, t_elem **node_b)
{
    ft_push(node_a, node_b, 1);
    ft_push(node_a, node_b, 1);
    
    // ou alors trier partiellement avec la mediane de node_a

    make_move();
}

/*
element en haut de la liste a : cherche sa position dans la liste + ou - triee node_b, 
et calcule les differents nombres de coups totaux pour le deplacer selon les differents cas de figure
*/
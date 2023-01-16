/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:36:53 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/16 19:11:14 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sort_small_list.h"

// mettre ces deux prorotypes dans le .h ?
void    get_in_order_small(t_elem **node, int a, t_min_max m);
void    move_data(t_elem **src, t_elem **dest, t_min_max *min_max_dest, int a_to_b) ;

void    sort_three(t_elem **node)
{  
    int x;
    int y;
    int z;
     
    x = (*node)->nb;
    y = (*node)->next->nb;
    z = (*node)->prev->nb;
    if (x > y && y > z)
    {
        ft_swap(node, 1);
        ft_rev_rotate(node, NULL, 1);  
    }
    else if (x > y && y < z)
    {
        if (z < x)
            ft_rotate(node, NULL, 1);
        else
            ft_swap(node, 1);
    }
    else if (x < y && y > z)
    {
        if (z < x)
            ft_rev_rotate(node, NULL, 1);
        else
        {
            ft_swap(node, 1);
            ft_rotate(node, NULL, 1);
        }
    }
}

int     get_min(t_elem **node)
{
    int min;
    t_elem *current;

    min = (*node)->nb;
    current = (*node)->next;
    while (current != *node)
    {
        if (current->nb < min)
            min = current->nb;
        current = current->next;
    }
    return (min);
}

void    sort_small(t_elem **node_a, t_elem **node_b)
{
    t_min_max m;
    
    m.min = get_min(node_a); 
    while (ft_lst_size(node_a) > 3)
    {
        m.min = get_min(node_a);
        if (get_pos(node_a, m.min) < ft_lst_size(node_a) / 2)
        {
            while ((*node_a)->nb != m.min)
                ft_rotate(node_a, NULL, 1);
        }
        else
        {
            while ((*node_a)->nb != m.min)
                ft_rev_rotate(node_a, NULL, 1);
        }
        ft_push(node_a, node_b, 0);
    }
    sort_three(node_a);
    m.min = (*node_a)->nb; // car la pile a est mtn triée
    m.max = (*node_a)->prev->nb; // car la pile a est mtn triée
    while (ft_lst_size(node_b))
        move_data(node_b, node_a, &m, 0); 
    get_in_order_small(node_a, 1, m);
}

void    sort_small_list(t_elem **node_a, t_elem **node_b)
{
    int size_a;
    
    if (!node_a || !node_b || !(*node_a)) // ne teste pas la pile b car elle est censee etre vide au debut
        return ;
    size_a = ft_lst_size(node_a);
    if (size_a == 2)
    {
        if ((*node_a)->nb > (*node_a)->next->nb)
            ft_rotate(node_a, NULL, 1);    
    }
    else if (size_a == 3)
        sort_three(node_a);
    else // if (size_a < 6)
        sort_small(node_a, node_b);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 04:14:47 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/16 19:06:21 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sort.h"


void print_bot(t_elem *node_a, t_elem *node_b);

int    get_and_check_data(int argc, char **argv, t_elem **node_a) // a mettre dans push_swap.c aussi
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (!check_list(node_a, argv[i])) 
        {
            ft_clear(node_a); // pas la peine de free node_b car est encore a NULL ici 
            write(2, "Error\n", 6);
            return (0);
        }  
        i++;
    }
    return (1);
}

int     get_pos(t_elem **node, int nb)
{
    int pos;
    t_elem *current;

    if (!node || !(*node)) // ie si pointeur null ou alors que la pile est vide
        return (-1);
    if (ft_lst_size(node) == 1)
    {
        if ((*node)->nb == nb)
            return (0);
        return (-1);
    }
    pos = 0;
    current = (*node)->next;
    while (current != *node)
    {
        if (current->nb == nb)
            return (pos);
        pos++;
        current = current->next;
    }
    
    return (-1);
}

void    get_in_order(t_elem **node, int a, t_min_max m) // mettre dans ordre decroissant car ensuite va tout push dans a
{
    if (!node)
        return ;
    if (get_pos(node, m.max) < ft_lst_size(node) / 2)
    {
        while ((*node)->nb != m.max)
            ft_rotate(node, NULL, a);
    }
    else
    {
        while ((*node)->nb != m.max)
            ft_rev_rotate(node, NULL, a);
    }
}

void    get_in_order_small(t_elem **node, int a, t_min_max m) // mettre dans ordre croissant car à déjà push dans a
{
    if (!node)
        return ;
    if (get_pos(node, m.max) < ft_lst_size(node) / 2)
    {
        while ((*node)->nb != m.min)
            ft_rotate(node, NULL, a);
    }
    else
    {
        while ((*node)->nb != m.min)
            ft_rev_rotate(node, NULL, a);
    }
}

void    init_moves(t_moves *moves, int pos_a)
{
    int i;

    i = 4;
    moves->cost = 0;
    moves->ra = 0;
    moves->rb = 0;
    moves->rra = 0;
    moves->rrb = 0;
    while(i--)
        moves->instruct[i] = 0;
    moves->pos_a = pos_a;
}

int     update_moves(t_moves *move, int ra, int rb, int rra, int rrb)
{
    move->instruct[0] = ra;
    move->instruct[1] = rb;
    move->instruct[2] = rra;
    move->instruct[3] = rrb;

    return (1);
}

void    optimise_cost(t_moves *moves)
{
    int cases[4] = {-ft_min(-moves->ra, -moves->rb), // cas ra_rb
                    -ft_min(-moves->rra, -moves->rrb), // cas rra, rrb
                    moves->ra + moves->rrb, // cas ra_rrb
                    moves->rra + moves->rb}; //cas rra_rb
    update_moves(moves, 1, 1, 0, 0);
    int current_min = cases[0]; // set le min au cout du cas 1, puis compare avec le cout des 3 autres cas
    
    if (current_min > cases[1] && update_moves(moves, 0, 0, 1, 1))
        current_min = cases[1];
    if (current_min > cases[2] && update_moves(moves, 1, 0, 0, 1))
        current_min = cases[2];
    if (current_min > cases[3] && update_moves(moves, 0, 1, 1, 0))
        current_min = cases[3];
    
    moves->cost = current_min;
    moves->ra *= moves->instruct[0];
    moves->rb *= moves->instruct[1];
    moves->rra *= moves->instruct[2];
    moves->rrb *= moves->instruct[3];
}

void    get_cost_small(t_elem **node_a, t_elem **node_b, int nb, t_moves *moves_current, t_min_max *m)
{
    int pos_b;
    t_elem *current_b;
    
    pos_b = 0;
    current_b = *node_b;
    if (nb < m->min || nb > m->max) // ie si l'élément a insérer va devenir le nouveau min ou max
    {
        // se déplace dans la pile b jusqu'à avoir l'élément min au sommet 
        while (current_b->next != *node_b && current_b->nb != m->min)
        {
            pos_b++;
            current_b = current_b->next;
        }
    }
    else
    {
        // itère sur pos_b tant que n'arrive pas à un élement n tel que nb (de la pile a) 
        // est dans l'intervalle [n_prev, n]
        while (current_b->next != *node_b && (nb < current_b->prev->nb || nb > current_b->nb)) 
        {
            pos_b++;
            current_b = current_b->next;
        }
    }
    moves_current->ra = moves_current->pos_a;
    moves_current->rb = pos_b;
    moves_current->rra = ft_lst_size(node_a) - moves_current->pos_a;
    moves_current->rrb = ft_lst_size(node_b) - pos_b;
    optimise_cost(moves_current);
}

void    get_cost(t_elem **node_a, t_elem **node_b, int nb, t_moves *moves_current, t_min_max *min_max_b)
{
    int pos_b;
    t_elem *current_b;
    
    pos_b = 0;
    current_b = *node_b;
    if (nb < min_max_b->min || nb > min_max_b->max) // ie si l'élément a insérer va devenir le nouveau min ou max
    {
        // se déplace dans la pile b jusqu'à avoir l'élément max au sommet 
        while (current_b->next != *node_b && current_b->nb != min_max_b->max)
        {
            pos_b++;
            current_b = current_b->next;
        }
    }
    else
    {
        // itère sur pos_b tant que n'arrive pas à un élement n tel que nb (de la pile a) 
        // est dans l'intervalle ]n, n_prev[
        while (current_b->next != *node_b && (current_b->nb == min_max_b->max || (nb < current_b->nb || nb > current_b->prev->nb)))
        {
            pos_b++;
            current_b = current_b->next;
        }
    }
    moves_current->ra = moves_current->pos_a % ft_lst_size(node_a);
    moves_current->rb = pos_b % ft_lst_size(node_b);
    moves_current->rra = (ft_lst_size(node_a) - moves_current->pos_a) % ft_lst_size(node_a);
    moves_current->rrb = (ft_lst_size(node_b) - pos_b) % ft_lst_size(node_b);
    optimise_cost(moves_current);
}

void    get_min_cost(t_elem **node_a, t_elem **node_b, t_moves *moves, t_min_max *min_max_b, int a_to_b)
{
    t_moves moves_current;
    t_elem *current_a;
    int pos_a;

    pos_a = 0; // 0 correspond à l'élément au sommet de la pile
    init_moves(&moves_current, pos_a);
    if (a_to_b)
        get_cost(node_a, node_b, (*node_a)->nb, &moves_current, min_max_b);
    else
        get_cost_small(node_a, node_b, (*node_a)->nb, &moves_current, min_max_b);
    *moves = moves_current;
    current_a = (*node_a)->next;
    while (current_a != *node_a)
    {
        pos_a++;
        init_moves(&moves_current, pos_a);
        if (a_to_b)
            get_cost(node_a, node_b, current_a->nb, &moves_current, min_max_b);
        else
            get_cost_small(node_a, node_b, current_a->nb, &moves_current, min_max_b);
        if (moves_current.cost < moves->cost)
            *moves = moves_current; // = marche avec les structs
        current_a = current_a->next;
    }
}

// Si a_to_b = 1, trie par ordre décroissant
// Si a_to_b = 0, trie par ordre croissant
void    move_data(t_elem **src, t_elem **dest, t_min_max *min_max_dest, int a_to_b) 
{
    t_moves moves;
    
    init_moves(&moves, 0);
    get_min_cost(src, dest, &moves, min_max_dest, a_to_b);
    while (moves.ra && moves.rb)
        ft_rrotate(src, dest, &moves, 0);
    while (moves.rra && moves.rrb)
        ft_rrev_rotate(src, dest, &moves, 0); 
    while (moves.ra)
        ft_rotate(src, &moves, 1);
    while (moves.rb)
        ft_rotate(dest, &moves, 0);
    while (moves.rra)
        ft_rev_rotate(src, &moves, 1);
    while (moves.rrb)
        ft_rev_rotate(dest, &moves, 0);
    if (a_to_b)
        ft_push(src, dest, 0);
    else
        ft_push(src, dest, 1);
    if ((*dest)->nb < min_max_dest->min)
            min_max_dest->min = (*dest)->nb;
    else if ((*dest)->nb > min_max_dest->max)
        min_max_dest->max = (*dest)->nb;
}

void    sort_data(t_elem **node_a, t_elem **node_b)
{
    t_min_max min_max_b;
    
    ft_push(node_a, node_b, 0);    
    ft_push(node_a, node_b, 0);
    min_max_b.min = ft_min((*node_b)->nb, (*node_b)->next->nb);
    min_max_b.max = -ft_min(-(*node_b)->nb, -(*node_b)->next->nb);

    while (ft_lst_size(node_a))
        move_data(node_a, node_b, &min_max_b, 1);

    //print_bot(*node_a, *node_b);
   get_in_order(node_b, 0, min_max_b);
   //print_bot(*node_a, *node_b);
   while (ft_lst_size(node_b))
        ft_push(node_b, node_a, 1);
    //print_bot(*node_a, *node_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 04:14:47 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/10 23:30:50 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sort.h"
#include <limits.h>
// #include "instructions_utils.h"

// check si certains parametres ne sont pas des doublons, 
// ne sont pas des nombres, ou ne tiennent pas dans un int

long long	ft_atoi(const char *nptr);

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int     are_identicals(char *s1, char *s2)
{
    int i;

    if (ft_strlen(s1) != ft_strlen(s2))
        return (0);
    i = 0;
    while (s1[i]) // ou s2[i], pareil car font la meme taille
    {
        if (s1[i] != s2[i])
            return (0);
        i++;
    }
    return (1);
}

int     is_a_number(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-')
        i++;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int     is_an_int(char *str)
{
    long long n;

    n = ft_atoi(str);
    if (n < INT_MIN || n > INT_MAX)
        return (0);
    return (1);
}

int     check_params(char **params, int argc)
{
    int i;

    i = 1;
    while (i < argc - 1)
    {
        if (are_identicals(params[i], params[argc - 1]))
            return (0);
        if (!is_a_number(params[i]))
            return (0);
        if (!is_an_int(params[i]))
            return (0);
        i++;
    }
    // teste ensuite pour params[argc - 1], ie le dernier paramètre
    if (!is_a_number(params[i]))
        return (0);
    if (!is_an_int(params[i]))
        return (0);
    return (1);
}

// max (a, b) = min (-a, -b)
int     ft_min(int a, int b)
{
    if (a > b)
        return (b);
    return (a);
}

int     in_range(int a, int b, int n) //]a, b[ 
{
    int i = a;

    while (i <= b)
    {
        if (i == n)
            return (1);
        i++;
    }
    return (0);
}

int     in_range_small(int a, int b, int n) // modif : ]b, a[ car trie b en décroissant 
{
    int i = a;

    while (i >= b)
    {
        if (i == n)
            return (1);
        i--;
    }
    return (0);
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

void    get_in_order_small(t_elem **node, int a, t_min_max m) // mettre dans ordre croissant car à déjà push dans a
{
    if (!node)
        return ;
    if (get_pos(node, m.max) < ft_lst_size(node) / 2)
    {
        while ((*node)->nb != m.min)
            ft_rotate(node, a);
    }
    else
    {
        while ((*node)->nb != m.min)
            ft_rev_rotate(node, a);
    }
}

void    get_in_order(t_elem **node, int a, t_min_max m) // mettre dans ordre decroissant car ensuite va tout push dans a
{
    if (!node)
        return ;
    if (get_pos(node, m.max) < ft_lst_size(node) / 2)
    {
        while ((*node)->nb != m.max)
            ft_rotate(node, a);
    }
    else
    {
        while ((*node)->nb != m.max)
            ft_rev_rotate(node, a);
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

// matrice 4x4 pour les 4 cas differents, et matrice 4x1 pour les ra, rb, etc, 
// et multiplie les 2 a la fin pour obtenir les ra, rb, etc finaux ?
// implementer un .c et un .h pour les operations sur les matrices ? peut etre utile pour plus tard
void    optimise_cost(t_moves *moves)
{
    int cases[4] = {-ft_min(-moves->ra, -moves->rb), // cas ra_rb
                    -ft_min(-moves->rra, -moves->rrb), // cas rra, rrb
                    moves->ra + moves->rrb, // cas ra_rrb
                    moves->rra + moves->rb}; //cas rra_rb
    int instruct[4] = {1, 1, 0, 0}; // initialiser ou inutile ? très TRÈS utile
    int current_min = cases[0]; // set le min au cout du cas 1, puis compare avec le cout des 3 autres cas
    
    while (1)
    {
        if (current_min > cases[1] && update_moves(moves, 0, 0, 1, 1))
            current_min = cases[1];
        else if (current_min > cases[2] && update_moves(moves, 1, 0, 0, 1))
            current_min = cases[2];
        else if (current_min > cases[3] && update_moves(moves, 0, 1, 1, 0))
            current_min = cases[3];
        else // ie si le current cout minimal est le cout minimal parmi tous les cas 
            break;
    }
    moves->cost = current_min;
    moves->ra *= instruct[0];
    moves->rb *= instruct[1];
    moves->rra *= instruct[2];
    moves->rrb *= instruct[3];
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
        while (current_b->next != *node_b && !in_range_small(current_b->prev->nb, current_b->nb, nb)) 
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
        // est dans l'intervalle [n_prev, n]
        while (current_b->next != *node_b && !in_range(current_b->nb, current_b->prev->nb, nb)) 
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

void    get_min_cost(t_elem **node_a, t_elem **node_b, t_moves *moves, t_min_max *min_max_b, int a_to_b)
{
    t_moves moves_current;
    t_elem *current_a;
    int pos_a;

    pos_a = 0; // 0 correspond à l'élément au sommet de la pile
    current_a = *node_a;
    init_moves(&moves_current, pos_a);
    if (a_to_b)
        get_cost(node_a, node_b, current_a->nb, &moves_current, min_max_b);
    else
        get_cost_small(node_a, node_b, current_a->nb, &moves_current, min_max_b);
    *moves = moves_current;
    while (current_a->next != *node_a)
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
    int rr;
    int rrr;
   
    init_moves(&moves, 0);
    get_min_cost(src, dest, &moves, min_max_dest, a_to_b); // détermine quelles instructions éffectuer sur les piles a et b afin d'obtenir un cout minimal
    // puis effectue cette suite d'instructions, stockée dans moves
    rr = ft_min(moves.ra, moves.rb);
    rrr = ft_min(moves.rra, moves.rrb);
    while (rr)
    {
        ft_rrotate(src, dest);
        rr--;
        moves.ra--;
        moves.rb--;
    }
    while (rrr)
    {
        // ou alors passer &move en argument des fonctions push, swap, rotate etc 
        // et decrementer ra, rb, rr, etc direct ds ces fonctions la
        ft_rrev_rotate(src, dest); 
        rrr--;
        moves.rra--;
        moves.rrb--;
    }
    while (moves.ra)
    {
        ft_rotate(src, 1);
        moves.ra--;
    }
    while (moves.rb)
    {
        ft_rotate(dest, 0);
        moves.rb--;
    }
    while (moves.rra)
    {
        ft_rev_rotate(src, 1);
        moves.rra--;
    }
    while (moves.rrb)
    {
        ft_rev_rotate(dest, 0);
        moves.rrb--;
    }
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
    t_min_max min_max_b; // écrire une fonction qui intialise à 0 ou par la peine car les initialise 2 lignes plus bas ?
    
    ft_push(node_a, node_b, 0);    
    ft_push(node_a, node_b, 0);
    min_max_b.min = ft_min((*node_b)->nb, (*node_b)->next->nb);
    min_max_b.max = -ft_min(-(*node_b)->nb, -(*node_b)->next->nb);

    while (ft_lst_size(node_a))
        move_data(node_a, node_b, &min_max_b, 1);
    
    /* remet la pile b dans l'ordre croissant (ie avec des rb ou rrb, 
     selon si le min_b / max_b est dans la première ou deuxième moitié de la pile)
    current = *node_b;
    if (get_pos(node_b, min_max_b.min) < ft_lst_size(node_b) / 2)
    {
        while ((*node_b)->nb != min_max_b.min)
            ft_rotate(node_b, 0);
    }
    else
    {
        while ((*node_b)->nb != min_max_b.min)
            ft_rev_rotate(node_b, 0);
    }
    */
   get_in_order(node_b, 0, min_max_b);
   while (ft_lst_size(node_b))
        ft_push(node_b, node_a, 1);
}

/*
void    move_small_data(t_elem **node_a, t_elem **node_b)
{
    
}
*/

void    sort_three(t_elem **node)
{  
    int x;
    int y;
    int z;
     
    if (!node)
        return ;
    x = (*node)->nb;
    y = (*node)->next->nb;
    z = (*node)->prev->nb;
    if (x > y && y > z)
    {
        ft_swap(node, 1);
        ft_rev_rotate(node, 1);  
    }
    else if (x > y && y < z)
    {
        if (z < x)
            ft_rotate(node, 1);
        else
            ft_swap(node, 1);
    }
    else if (x < y && y > z)
    {
        if (z < x)
            ft_rev_rotate(node, 1);
        else
        {
            ft_swap(node, 1);
            ft_rotate(node, 1);
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
                ft_rotate(node_a, 1);
        }
        else
        {
            while ((*node_a)->nb != m.min)
                ft_rev_rotate(node_a, 1);
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
            ft_rotate(node_a, 1);    
    }
    else if (size_a == 3)
        sort_three(node_a);
    else // if (size_a < 6)
        sort_small(node_a, node_b);
    //else
    //    sort_seven(node_a, node_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 04:14:47 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/03 20:04:29 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
// #include "instructions_utils.h"

// max (a, b) = min (-a, -b)
int ft_min(int a, int b)
{
    if (a > b)
        return (b);
    return (a);
}

int     in_range(int a, int b, int n) // [a, b] 
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

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dst;
	size_t			i;

	dst = s;
	i = 0;
	while (i < n)
	{
		dst[i] = (unsigned char)c;
		i++;
	}
	return (s);
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

/*
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
    min = -ft_min(-rra, -rrb);
    if (moves->cost > min)
        nb_case = 1;
    
}

cas 1 : cost_min = max(ra, rb)
cas 2 : cost_min = max(rra, rrb)
cas 3 : cost_min = ra + rrb
cas 4 : cost_min = rra + rb
*/

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
    int cases[4] = {-ft_min(-moves->ra, -moves->rb), // ra_rb
                    -ft_min(-moves->rra, -moves->rrb), // rra, rrb
                    moves->ra + moves->rrb, // ra_rrb
                    moves->rra + moves->rb}; //rra_rb
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

void    get_cost(t_elem **node_a, t_elem **node_b, int nb, t_moves *moves_current, t_min_max *min_max_b)
{
    int pos_b;
    t_elem *current_b;
    
    pos_b = 0;
    current_b = *node_b;
    if (nb <= min_max_b->min || nb >= min_max_b->max) // ie si l'élément a insérer va devenir le nouveau min ou max
    {
        // se déplace dans la pile b jusqu'à avoir l'élément min au sommet 
        while (current_b->next != *node_b && current_b->nb != min_max_b->min)
        {
            pos_b++;
            current_b = current_b->next;
        }
    }
    else
    {
        // itère sur pos_b tant que n'arrive pas à un élement n tel que nb (de la pile a) 
        // est dans l'intervalle [n_prev, n]
        while (current_b->next != *node_b && !in_range(current_b->prev->nb, current_b->nb, nb)) 
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

void    get_min_cost(t_elem **node_a, t_elem **node_b, t_moves *moves, t_min_max *min_max_b)
{
    t_moves moves_current;
    t_elem *current_a;
    int pos_a;

    pos_a = 0; // 0 correspond à l'élément au sommet de la pile
    current_a = *node_a;
    init_moves(&moves_current, pos_a);
    get_cost(node_a, node_b, current_a->nb, &moves_current, min_max_b);
    *moves = moves_current;
    while (current_a->next != *node_a)
    {
        pos_a++;
        init_moves(&moves_current, pos_a);
        get_cost(node_a, node_b, current_a->nb, &moves_current, min_max_b);
        if (moves_current.cost < moves->cost)
            *moves = moves_current; // = marche avec les structs
        current_a = current_a->next;
    }
}


void    move_data(t_elem **node_a, t_elem **node_b, t_min_max *min_max_b)
{
    t_moves moves;
    int rr;
    int rrr;
   
    init_moves(&moves, 0);
    get_min_cost(node_a, node_b, &moves, min_max_b); // détermine quelles instructions éffectuer sur les piles a et b afin d'obtenir un cout minimal
    // puis effectue cette suite d'instructions, stockée dans moves
    rr = ft_min(moves.ra, moves.rb);
    rrr = ft_min(moves.rra, moves.rrb);
    
    /*
    while (rr--)
        ft_rrotate(node_a, node_b);
    while (moves.ra-- || moves.rb--) // doit mettre a jour ra et rb quand initialise rr
    {
        
    }
    */
}

void    sort_data(t_elem **node_a, t_elem **node_b)
{
    t_min_max min_max_b; // écrire une fonction qui intialise à 0 ou par la peine car les initialise 2 lignes plus bas ?
    
    ft_push(node_a, node_b, 1);    
    ft_push(node_a, node_b, 1);
    min_max_b.min = ft_min((*node_b)->nb, (*node_b)->next->nb);
    min_max_b.max = -ft_min(-(*node_b)->nb, -(*node_b)->next->nb);

    while (ft_lst_size(node_a))
        move_data(node_a, node_b, &min_max_b);
    // rajouter une fonction qui remet la pile b dans l'ordre 
    // (ie avec des rb ou rrb, selon si le min_b / max_b est dans la première ou deuxième moitié de la pile)
}
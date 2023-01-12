/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:23:16 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/12 14:12:07 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

#include "instructions_utils.h"
#include "sort_utils.h"

typedef struct s_nodes
{
    t_elem **node_a;
    t_elem **node_b;
    int size_a;
    int size_b;
}               t_nodes; // pointeurs sur premiers éléments des piles a et b, ainsi que la taille des deux piles, mise a jour

#endif

int     check_params(char **params, int argc);
int     ft_min(int a, int b);
int     in_range(int a, int b, int n); // [a, b[
void    ft_init_moves(t_moves *moves, int pos_a);
int     update_moves(t_moves *move, int ra, int rb, int rra, int rrb);
void    optimise_cost(t_moves *moves);
void    get_cost(t_elem **node_a, t_elem **node_b, int nb, t_moves *moves_current, t_min_max *min_max_b);
void    get_min_cost(t_elem **node_a, t_elem **node_b, t_moves *moves, t_min_max *min_max_b, int a_to_b);
void    move_data(t_elem **src, t_elem **dest, t_min_max *min_max_dest, int a_to_b);
void    sort_data(t_elem **node_a, t_elem **node_b);
void    sort_small_list(t_elem **node_a, t_elem **node_b);
void    sort_three(t_elem **node);
void    sort_small(t_elem **node_a, t_elem **node_b);
int     get_min(t_elem **node);
int     get_pos(t_elem **node, int nb);
void    get_in_order_small(t_elem **node, int a, t_min_max m);
void    get_in_order(t_elem **node, int a, t_min_max m);
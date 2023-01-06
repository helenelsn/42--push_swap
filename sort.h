/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:23:16 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/06 19:02:48 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

#include "instructions_utils.h"

typedef struct s_moves
{
    int cost;
    int pos_a;
    int ra;
    int rb; // rr = min(ra, rb)
    int rra;
    int rrb; // rrr = min(rra, rrb)
    int instruct[4];
}           t_moves;

typedef struct s_min_max
{
    int min;
    int max;
}               t_min_max;

#endif

int     ft_min(int a, int b);
int     in_range(int a, int b, int n); // [a, b[
void    ft_init_moves(t_moves *moves, int pos_a);
int     update_moves(t_moves *move, int ra, int rb, int rra, int rrb);
void    optimise_cost(t_moves *moves);
void    get_cost(t_elem **node_a, t_elem **node_b, int nb, t_moves *moves_current, t_min_max *min_max_b);
void    get_min_cost(t_elem **node_a, t_elem **node_b, t_moves *moves, t_min_max *min_max_b);
void    move_data(t_elem **node_a, t_elem **node_b, t_min_max *min_max_b);
void    sort_data(t_elem **node_a, t_elem **node_b);
void    sort_small_list(t_elem **node_a, t_elem **node_b);
void    sort_three(t_elem **node_a, t_elem **node_b);
void    sort_five(t_elem **node_a, t_elem **node_b);
void    sort_seven(t_elem **node_a, t_elem **node_b);
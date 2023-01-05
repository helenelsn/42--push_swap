/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:23:16 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/03 17:59:23 by Helene           ###   ########.fr       */
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

int ft_min(int a, int b);
int     in_range(int a, int b, int n); // [a, b[
void	*ft_memset(void *s, int c, size_t n);
void    ft_init_moves(t_moves *moves, int pos_a);
int     update_moves(t_moves *move, int ra, int rb, int rra, int rrb);
void    optimise_cost(t_moves *moves);
void    get_cost(t_elem **node_a, t_elem **node_b, int nb, t_moves *moves_current, t_min_max *min_max_b);
void    get_min_cost(t_elem **node_a, t_elem **node_b, t_moves *moves, t_min_max *min_max_b);
void    move_data(t_elem **node_a, t_elem **node_b, t_min_max *min_max_b);
void    sort_data(t_elem **node_a, t_elem **node_b);



// ra, rb etc sont à 0 ou 1, et en déduit le nbre de moves grace au cout total
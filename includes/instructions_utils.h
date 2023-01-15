/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:02:14 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/15 21:52:48 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_UTILS_H
# define INSTRUCTIONS_UTILS_H

#include "lists_utils.h" 
//#include "sort.h" // autre maniere de faire ? en a besoin pr la definition de la structure t_moves 

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

void    ft_swap(t_elem **first, int a);
void    ft_sswap(t_elem **node_a, t_elem **node_b);
void    ft_push(t_elem **src, t_elem **dest, int a);
void    ft_rotate(t_elem **node, t_moves *moves, int a);
void    ft_rrotate(t_elem **node_a, t_elem **node_b, t_moves *moves, int checker);
void    ft_rev_rotate(t_elem **node, t_moves *moves, int a);
void    ft_rrev_rotate(t_elem **node_a, t_elem **node_b, t_moves *moves, int checker);

#endif
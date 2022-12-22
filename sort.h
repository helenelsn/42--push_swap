/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:23:16 by hlesny            #+#    #+#             */
/*   Updated: 2022/12/23 00:24:27 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

typedef struct s_moves
{
    int min;
    int cost;
    int pos_a;
    int pos_b;
    int ra;
    int rb; // rr = min(ra, rb)
    int rra;
    int rrb; // rrr = min(rra, rrb)
    int tab_min[6]
}           t_moves;

#endif
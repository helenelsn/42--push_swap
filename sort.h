/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:23:16 by hlesny            #+#    #+#             */
/*   Updated: 2022/12/22 04:29:38 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

typedef struct s_moves
{
    int cost;
    int ra;
    int rb;
    int rr;
    int rra;
    int rrb;
    int rrr;
}           t_moves;

#endif
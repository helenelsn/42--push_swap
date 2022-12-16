/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:02:14 by hlesny            #+#    #+#             */
/*   Updated: 2022/12/16 15:02:12 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_UTILS_H
# define INSTRUSCTIONS_UTILS_H

#include "lists_utils.h" 

enum e_instr
{
    swap,
    push,
    rotate,
    rev_rotate
};

void    ft_swap(t_fl *fl, int a);
void    ft_push(t_fl *fl_a, t_fl *fl_b, int a);
void    ft_rotate(t_fl *fl, int a);
void    ft_rev_rotate(t_fl *fl, int a);


#endif
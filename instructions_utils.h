/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:02:14 by hlesny            #+#    #+#             */
/*   Updated: 2022/12/17 04:39:14 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_UTILS_H
# define INSTRUSCTIONS_UTILS_H

#include "lists_utils.h" 

void    ft_swap(t_elem **first, int a) ;
void    ft_push(t_elem **node_a, t_elem **node_b, int a);
void    ft_rotate(t_elem **node, int a);
void    ft_rev_rotate(t_elem **node, int a);


#endif
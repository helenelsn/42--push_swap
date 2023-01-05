/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:02:14 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/03 17:55:10 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_UTILS_H
# define INSTRUCTIONS_UTILS_H

#include "lists_utils.h" 

void    ft_swap(t_elem **first, int a) ;
void    ft_push(t_elem **node_a, t_elem **node_b, int a);
void    ft_rotate(t_elem **node, int a);
void    ft_rrotate(t_elem **node_a, t_elem **node_b);
void    ft_rev_rotate(t_elem **node, int a);
void    ft_rrev_rotate(t_elem **node_a, t_elem **node_b);

#endif
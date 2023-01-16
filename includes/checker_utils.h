/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:22:58 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/16 18:57:29 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_UTILS_H
# define CHECKER_UTILS_H

#include "get_next_line.h"
#include "sort.h"

# define PA 'a'
# define PB 'b'
# define SA 'c'
# define SB 'd'
# define SS 'e' 
# define RA 'f'
# define RB 'g'
# define RR 'h'
# define RRA 'i'
# define RRB 'j'
# define RRR 'k'

int     ft_check(t_elem **node_a, t_elem **node_b, char *instructions);
char    *read_instructions();

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:02:14 by hlesny            #+#    #+#             */
/*   Updated: 2022/12/15 15:20:39 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_UTILS_H
# define INSTRUSCTIONS_UTILS_H

#include "lists_utils.h" 
#include <stddef.h>

enum e_instr
{
    swap,
    push,
    rotate,
    rev_rotate
};

#endif
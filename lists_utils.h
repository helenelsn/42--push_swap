/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:54:51 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/03 19:10:43 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LISTS_H 
# define FT_LISTS_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_elem
{
    int nb;
    struct s_elem *prev;
    struct s_elem *next;
}               t_elem;

int     ft_lst_size(t_elem **first);
t_elem    *ft_new_elem(int nb);
void    ft_add_back(t_elem **first, t_elem *new);

#endif
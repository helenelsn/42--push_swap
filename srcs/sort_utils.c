/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:10:31 by Helene            #+#    #+#             */
/*   Updated: 2023/01/12 20:47:57 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sort_utils.h"

int     ft_min(int a, int b)
{
    if (a > b)
        return (b);
    return (a);
}

// check si la LISTE est triee (par ordre croissant)
// int     is_sorted(t_elem **node)
// {
//     t_elem *current;

//     if ()
//     current = 
// }
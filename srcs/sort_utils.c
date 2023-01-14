/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:10:31 by Helene            #+#    #+#             */
/*   Updated: 2023/01/13 19:53:08 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sort_utils.h"

int     ft_min(int a, int b)
{
    if (a > b)
        return (b);
    return (a);
}

int     is_sorted(t_elem *node)
{
    t_elem *current;

    if (!node)
        return (-1);
    current = node->next;
    while (current != node)
    {
        if (current->prev->nb > current->nb)
            return (0);
        current = current->next;
    }
    return (1); // retourne 1 meme si la liste n'a qu'un élément car la considère comme triée ?
}

// check si la LISTE est triee (par ordre croissant)
// int     is_sorted(t_elem **node)
// {
//     t_elem *current;

//     if ()
//     current = 
// }
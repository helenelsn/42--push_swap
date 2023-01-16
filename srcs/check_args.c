/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:27:13 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/16 19:03:14 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/check_args.h"

// check si certains parametres ne sont pas des doublons, 
// ne sont pas des nombres, ou ne tiennent pas dans un int

int     check_list(t_elem **node, char *s) 
{
    t_elem *current;
    long long i;
    int k;
    
    if (!node)
        return (0);
    i = 0;
    k = 0;
    while (s[i]) // check le argv[i] entier pour verifier que l'on a uniquement des nombres
    {
        if ((s[i] < '0' || s[i] > '9') && s[i] != '-' && s[i] != ' ')
            return (0);
        i++;
    }
    if (!(*node)) // ie la pile est pr l'instant vide 
    {
        i = ft_atoi(s, &k);
        if (i < INT_MIN || i > INT_MAX)
            return (0);
        ft_add_back(node, ft_new_elem(i)); 
    }
    if ((*node)->next == *node && s[k]) // ie si n'a qu'un seul element dans la pile
    {
        i = ft_atoi(s, &k);
        if (i < INT_MIN || i > INT_MAX || i == (*node)->nb) // || ((*node)->next == *node && i == (*node)->nb)
            return (0);
        ft_add_back(node, ft_new_elem(i)); 
    }
    while (s[k])
    {
        i = ft_atoi(s, &k);
        if (i < INT_MIN || i > INT_MAX || i == (*node)->nb)
            return (0);
        current = (*node)->next;
        while (current != *node)
        {
            if (current->nb == i)
                return (0);
            current = current->next;
        }
        // si le/les arguments passes via argv[i] sont valides, le/les ajoute a la pile
        ft_add_back(node, ft_new_elem(i)); 
    }
    return (1);     
}

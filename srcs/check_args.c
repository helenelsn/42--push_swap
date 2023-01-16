/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:27:13 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/16 19:49:15 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/check_args.h"

// check si certains parametres ne sont pas des doublons, 
// ne sont pas des nombres, ou ne tiennent pas dans un int

int     check_and_add(t_elem **node, char *s)
{
    int i;
    long long n;
    t_elem *current;
    
    i = 0;
    while (s[i])
    {
        n = ft_atoi(s, &i);
        if (n < INT_MIN || n > INT_MAX || (ft_lst_size(node) > 0 && n == (*node)->nb)) // teste pr l'element au sommet de la pile
            return (0);
        if (!(*node)) // ie la pile est pr l'instant vide 
            return (ft_add_back(node, ft_new_elem(n)), 1);
        current = (*node)->next;
        while (current != *node)
        {
            if (current->nb == n)
                return (0);
            current = current->next;
        }
        // si le/les arguments passes via argv[i] sont valides, le/les ajoute a la pile
        ft_add_back(node, ft_new_elem(n)); 
    }
    return (1);
}

int     check_list(t_elem **node, char *s) 
{
   
    int i;
    
    if (!node)
        return (0);
    i = 0;
    while (s[i]) // check le argv[i] entier pour verifier que l'on a uniquement des nombres
    {
        if ((s[i] < '0' || s[i] > '9') && s[i] != '-' && s[i] != ' ')
            return (0);
        i++;
    }
    
    if (!check_and_add(node, s))
        return (0);
    return (1);     
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:27:13 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/15 21:45:26 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/check_args.h"

 // le mettre dans le .h ?

int     ft_strlen(char *str)
{
    int i;
    
    if (!str)
        return (0);
    i = 0;
    while (str[i])
        i++;
    return (i);
}

int     are_identicals(char *s1, char *s2)
{
    int i;

    if (ft_strlen(s1) != ft_strlen(s2))
        return (0);
    i = 0;
    while (s1[i]) // ou s2[i], pareil car font la meme taille
    {
        if (s1[i] != s2[i])
            return (0);
        i++;
    }
    return (1);
}

int     is_a_number(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-')
        i++;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int     is_an_int(char *str)
{
    long long n;

    n = ft_atoi(str, 0);
    if (n < INT_MIN || n > INT_MAX)
        return (0);
    return (1);
}

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
        if (i < INT_MIN || i > INT_MAX || i == (*node)->nb)
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

/*
int     check_params(char **argv, int argc)
{
    int i;
    int j;

    if (!is_a_number(argv[1]))
        return (0);
    if (!is_an_int(argv[1]))
        return (0);
    i = 2;
    while (i < argc)
    {
        j = i;
        while (--j > 0)
        {
            if (are_identicals(argv[j], argv[i]))
                return (0);
        }
        if (!is_a_number(argv[i]))
            return (0);
        if (!is_an_int(argv[i]))
            return (0);
        i++;
    }
    return (1);
}
*/

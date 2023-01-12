/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:27:13 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/12 13:48:30 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/check_args.h"

long long	ft_atoi(const char *nptr); // le mettre dans le .h ?

int     ft_strlen(char *str)
{
    int i;

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

    n = ft_atoi(str);
    if (n < INT_MIN || n > INT_MAX)
        return (0);
    return (1);
}

// check si certains parametres ne sont pas des doublons, 
// ne sont pas des nombres, ou ne tiennent pas dans un int
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

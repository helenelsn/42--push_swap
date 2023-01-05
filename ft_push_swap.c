/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:20:33 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/03 19:17:45 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int main(int argc, char **argv)
{
    int i;
    t_elem *node_a;
    t_elem *node_b;
    
    if (argc == 1)
        return 0;
    
    i = 1;
    node_a = NULL;
    node_b = NULL;
    while (i < argc)
    {
        ft_add_back(&node_a, ft_new_elem(atoi(argv[i])));
        i++;
    }
    sort_data(&node_a, &node_b);
}
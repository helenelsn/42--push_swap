/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:56:54 by Helene            #+#    #+#             */
/*   Updated: 2023/01/16 18:39:56 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void print_bot(t_elem *node_a, t_elem *node_b);


// DOIT STOPPER LE PROGRAMME DES QU'A UNE ERREUR DANS LE PARSING 
int main(int argc, char **argv)
{
    int check;
    t_elem *node_a;
    t_elem *node_b;
    
    if (argc < 2)
        return 0;
    node_a = NULL;
    node_b = NULL;
    if (!get_and_check_data(argc, argv, &node_a))
        return (0); 
    check = ft_check(&node_a, &node_b, read_instructions());
    if (!check)
        write(1, "KO\n", 3);
    else if (check == 1)
        write(1, "OK\n", 3);
    else 
        write(2, "Error\n", 6);
    return (ft_clear(&node_a), ft_clear(&node_b), 0);
}






void print_elem(t_elem * elem, t_elem *first)
{
    if (elem && elem != first)
        printf("%3d", elem->nb);
    else 
        printf("   ");
}

void print_bot(t_elem *node_a, t_elem *node_b)
{
    t_elem *elem_a = NULL;
    t_elem *elem_b = NULL;
    
    print_elem(node_a, NULL);
    print_elem(node_b, NULL);
    
    if (node_a)
        elem_a = node_a->next;
    if (node_b)
        elem_b = node_b->next;
    
    while ((node_a && elem_a && elem_a != node_a) || (node_b && elem_b && elem_b != node_b))
    {
        printf("\n");
        print_elem(elem_a, node_a);
        if (elem_a && node_a && elem_a != node_a)
            elem_a = elem_a->next;
        print_elem(elem_b, node_b);
        if (elem_b && node_b && elem_b != node_b)
            elem_b = elem_b->next;
        
    }

    printf("\n a     b \n");
    printf("___   ___\n\n");
}
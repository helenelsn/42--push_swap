/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:20:33 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/14 19:22:07 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sort.h"
#include "../includes/check_args.h"
#include "../includes/sort_utils.h"

void print_bot(t_elem *node_a, t_elem *node_b);

// !!!!!! REMPLACER LES ATOI PAR MON FT_ATOI DANS LE CODE

int main(int argc, char **argv)
{
    int i;
    int j;
    int nb;
    t_elem *node_a;
    t_elem *node_b;
    
    if (argc < 2)
        return 0;
    if (!check_params(argv, argc))
    {
        write(2, "Error\n", 6);
        return (-1);
    }
    
    i = 1;
    nb = 0; // utile ?
    node_a = NULL;
    node_b = NULL;
    // implementer fonction void get_and_check_data(int argc, char **argv, t_elem **node_a)
    while (i < argc)
    {
        j = 0;
        while (argv[i][j]) // les string argv[i] sont bien null-terminated ouais ? oui
        {
            nb = ft_atoi(argv[i], &j);
            ft_add_back(&node_a, ft_new_elem(nb));
        }
        i++;
    }
    if (is_sorted(node_a))
        return (0);
    if (ft_lst_size(&node_a) < 8)
        sort_small_list(&node_a, &node_b);
    else
        sort_data(&node_a, &node_b);
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
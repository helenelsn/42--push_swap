/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:44:14 by hlesny            #+#    #+#             */
/*   Updated: 2022/12/21 01:17:32 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_utils.h"
//#include "lists_utils.h"

// void    print_center(int nb, char *color);
// void print_list4(t_fl *fl, t_fl *fl2);


void print_both(t_elem **node_a, t_elem **node_b);
void print_bot(t_elem *node_a, t_elem *node_b);

int main(int argc, char **argv)
{
    if (argc < 2) 
        return 0;
    int i = 1;
    t_elem *node_a = ft_new_elem(0);
    t_elem *node_b = ft_new_elem(0);
    while (i < argc)
    {
        ft_add_back(&node_a, ft_new_elem(atoi(argv[i])));
        i++;
    }
    print_bot(node_a, node_b);
    ft_push(&node_a, &node_b, 1);
    print_bot(node_a, node_b);
}

void print_both_save(t_elem **node_a, t_elem **node_b)
{
    t_elem *elem;
    t_elem *elem2;
    if (!node_a || !*node_a || !node_b || !*node_b)
        return ;
    elem = (*node_a);
    elem2 = (*node_b);
    while (elem->next != *node_a || (elem2 && elem2->next != *node_b))
    {
        if (elem->next != *node_a)
        {
            printf("%3d", elem->nb);
            elem = elem->next;
        }
        else 
            printf("   ");
        printf("   ");
        if (elem2 && elem2->next != *node_b)
        {
            printf("%3d\n", elem2->nb);
            elem2 = elem2->next;
        }
        else
            printf("   \n");
    }
    printf("%3d", elem->nb);
    printf("   %3d\n", elem2->nb);
    printf("\n a     b \n");
    printf("___   ___\n\n");
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
    t_elem *elem_a;
    t_elem *elem_b;
    
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
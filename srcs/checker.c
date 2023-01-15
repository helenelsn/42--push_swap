/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:56:54 by Helene            #+#    #+#             */
/*   Updated: 2023/01/15 22:43:40 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

#include<stdio.h>
void print_bot(t_elem *node_a, t_elem *node_b);

void    apply_instr(t_elem **node_a, t_elem **node_b, char instruction)
{
    if (!node_a || !node_b || !instruction)
        return ;
    if (instruction == PA)
        ft_push(node_b, node_a, 2);
    else if (instruction == PB)
        ft_push(node_a, node_b, 2);
    else if (instruction == SA)
        ft_swap(node_a, 2);
    else if (instruction == SB)
        ft_swap(node_b, 2);
    else if (instruction == SS)
        ft_sswap(node_a, node_b);
    else if (instruction == RA)
        ft_rotate(node_a, NULL, 2);
    else if (instruction == RB)
        ft_rotate(node_b, NULL, 2);
    else if (instruction == RRA)
        ft_rev_rotate(node_a, NULL, 2);
    else if (instruction == RRB)
        ft_rev_rotate(node_b, NULL, 2);
    else if (instruction == RR)
        ft_rrotate(node_a, node_b, NULL, 1);
    else if (instruction == RRR)
        ft_rrev_rotate(node_a, node_b, NULL, 1);
}

int     same_string(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    if (s1[i] || s2[i])
        return (0);
    return (1);
}

int    set_instructions(char *tmp, char *c)
{
    if (same_string(tmp, "pa\n"))
        *c = PA;
    else if (same_string(tmp, "pb\n"))
        *c = PB;
    else if (same_string(tmp, "sa\n"))
        *c = SA;
    else if (same_string(tmp, "sb\n"))
        *c = SB;
    else if (same_string(tmp, "ss\n"))
        *c = SS;
    else if (same_string(tmp, "ra\n"))
        *c = RA;
    else if (same_string(tmp, "rb\n"))
        *c = RB;
    else if (same_string(tmp, "rr\n"))
        *c = RR;
    else if (same_string(tmp, "rra\n"))
        *c = RRA;
    else if (same_string(tmp, "rrb\n"))
        *c = RRB;
    else if (same_string(tmp, "rrr\n"))
        *c = RRR;
    else
        return (0);
    return (1);
}

// reads the list of instructions displayed on the terminal and returns it in a 2D array, deleting the '\n'
char *read_instructions() 
{
    char *instructions;
    char *tmp;
    char c;

    instructions = NULL;
    tmp = get_next_line(0);
    while (tmp)
    {
        if (!set_instructions(tmp, &c))   
            return (free(tmp), free(instructions), NULL);
        instructions = ft_strncat(instructions, &c, 1);
        free(tmp);
        tmp = get_next_line(0);
    }
    // instructions est null terminated dans ft_strncat, pas besoin de le faire ici
    return (instructions);
}

// checks if the liste of instructions sorts the stack a properly, and if the stack b isn't empty at the end
int     ft_check(t_elem **node_a, t_elem **node_b, char *instructions)
{
    int i;
    if (!node_a || !(*node_a) || !node_b || !instructions)
        return (-1);
    
    i = 0;
    
    while (instructions[i])
    {
        printf("instructions[%d] = %c\n", i, instructions[i]);
        apply_instr(node_a, node_b, instructions[i++]);
    }
    free(instructions);
    return (!ft_lst_size(node_b) && is_sorted(node_a));
    // retourne 0 if isn't sorted mais qu'il n'y a pas eu d'erreur d'imput
}


// !!!!!!!!! DOIT STOPPER LE PROGRAMME DES QU'A UNE ERREUR DANS LE PARSING 
int main(int argc, char **argv)
{
    int i;
    int check;
    int nb;
    t_elem *node_a;
    t_elem *node_b;
    
    if (argc < 2)
        return 0;
    
    i = 1;
    nb = 0; // utile ?
    node_a = 0;
    node_b = 0;
    // implementer fonction void get_and_check_data(int argc, char **argv, t_elem **node_a)
    while (i < argc)
    {
        if (!check_list(&node_a, argv[i])) 
        {
            ft_clear(&node_a); // pas la peine de free node_b car est encore a NULL ici 
            write(2, "Error\n", 6);
            return (-1);
        }  
        i++;
    }
    print_bot(node_a, node_b);
    check = ft_check(&node_a, &node_b, read_instructions());
    print_bot(node_a, node_b);
    ft_clear(&node_a);
    ft_clear(&node_b);
    if (!check)
        write(1, "KO\n", 3);
    else if (check == 1)
        write(1, "OK\n", 3);
    else 
        write(2, "Error\n", 6);
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
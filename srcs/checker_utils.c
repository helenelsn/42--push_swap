/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:22:45 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/16 18:40:53 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_utils.h"

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
        apply_instr(node_a, node_b, instructions[i++]);
    free(instructions);
    // retourne 0 if isn't sorted mais qu'il n'y a pas eu d'erreur d'imput
    return (!ft_lst_size(node_b) && is_sorted(node_a));
}
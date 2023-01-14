/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:56:54 by Helene            #+#    #+#             */
/*   Updated: 2023/01/14 21:25:57 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int    apply_instr(t_elem **node_a, t_elem **node_b, char *instruction)
{
    if (!node_a || !(*node_a) || !node_b || !instruction)
        return (0);
    if (instruction == "pa")
        ft_push(node_b, node_a, 2);
    else if (instruction == "pb")
        ft_push(node_a, node_b, 2);
    else if (instruction == "sa")
        ft_swap(node_a, 2);
    else if (instruction == "sb")
        ft_swap(node_b, 2);
    else if (instruction == "ra")
        ft_rotate(node_a, 0, 2);
    else if (instruction == "rb")
        ft_rotate(node_b, 0, 2);
    else if (instruction == "rra")
        ft_rev_rotate(node_a, 0, 2);
    else if (instruction == "rrb")
        ft_rev_rotate(node_b, 0, 2);
    else if (instruction == "rr")
        ft_rrotate(node_a, node_b, 0);
    else if (instruction == "rrr")
        ft_rrev_rotate(node_a, node_b, 0);
    else
        return (0);
    return (1);
}

// checks if the liste of instructions sorts the stack a properly, and if the stack b isn't empty at the end
int     ft_check(t_elem **node_a, t_elem **node_b, char **instructions)
{
    int i;
    if (!node_a || !(*node_a) || !node_b || !instructions)
        return (0);
    
    i = 0;
    while (instructions)
    {
        if (apply_instr(node_a, node_b, instructions[i]))
            i++;
        else 
            return (-1); // ie si il a une erreur dans le parsing des instructions
    }
    if (is_sorted(node_a) && !ft_lst_size(node_b))
        return (1);
    return (0); // if isn't sorted mais qu'il n'y a pas eu d'erreur d'imput
    
    // ne doit pas oublier de free instructions
}

// reads the list of instructions displayed on the terminal and returns it in a 2D array, deleting the '\n'
char **get_instructions() 
{
    // renvoie un char** AVEC COMME DERNIER ELEMENT UN POINTEUR NULL
    char **instructions;
    int i;

    i = 1;
    instructions[0] = get_next_line(0); // inclure les fichiers de gnl. À combien set buffer_size ? s'en blc en soi, 4 fera l'affaire
    while (instructions[i]) // ie while instrctions[i] != NULL, right ?
    {
        instructions[i] = get_next_line(0);
        i++;
    }
    
}

int main(int argc, char **argv)
{
    int i;
    int j;
    int check;
    t_elem *node_a;
    t_elem *node_b;
    
    if (argc < 2) // if no argument is given, the checker stops and displays nothing
        return 0;
    if (!check_params(argv, argc))
    {
        write(2, "Error\n", 6);
        return (-1);
    }
    
    i = 1;
    j = 0;
    node_a = 0;
    node_b = 0;
    while (i < argc)
    {
        while (argv[i][j]) // les string argv[i] sont bien null-terminated ouais ?
        {
            ft_add_back(&node_a, ft_new_elem(atoi(argv[i][j])));
            j++;
        }
        i++;
    }
    check = ft_check(&node_a, &node_b, get_instructions());
    if (!check)
        write(1, "KO\n", 3);
    else if (check == 1)
        write(1, "OK\n", 3);
    else 
        write(2, "Error\n", 6);
}
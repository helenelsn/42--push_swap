/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:18:43 by hlesny            #+#    #+#             */
/*   Updated: 2022/12/16 15:06:02 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
# define reset "\033[00m"

# define italic "\033[3m"
# define bold "\033[1m"
# define underline "\033[4m"

# define white "\033[37m"
# define red "\033[38;5;124m"
# define green "\033[38;5;33m"
# define yellow "\033[33m"
# define blue "\033[34m"
# define magenta "\e[38;5;222m"
# define veligreen "\e[38;5;41m"



void print_list(t_fl *fl)
{
    if (!fl)
        return ;
    t_elem *elem;
    elem = fl->first;
    while (elem)
    {
        printf("elem : %d\n", elem->nb);
        if (elem->prev)
            printf("  prev : %d\n", elem->prev->nb);
        if (elem->next)
            printf("  next : %d\n\n", elem->next->nb);
        elem = elem->next;
    }
}

void print_list2(t_fl *fl)
{
    if (!fl)
        return ;
    t_elem *elem;
    elem = fl->first;
    while (elem)
    {
        printf("%d", elem->nb);
        elem = elem->next;
        if(elem)
            printf(" --> ");
    }
    printf("\n");
}

void print_list3(t_fl *fl)
{
    if (!fl)
        return ;
    t_elem *elem;
    elem = fl->first;
    while (elem)
    {
        if (elem->prev)
            printf("%d --> ", elem->prev->nb);
        else
            printf("      ");
        printf("%d", elem->nb);
        if (elem->next)
            printf("--> %d", elem->next->nb);
        printf("\n      |  \n");
        printf("      |  \n");
        elem = elem->next;
    }
    printf("\n");
}

void    print_center(int nb, char *color)
{
	printf("%s", color);
    if (nb < 10)
        printf(" %d ", nb);
	else if (nb < 100)
		printf("%d ", nb);
	else
		printf("%d", nb);
	printf("%s", reset);
}

void print_list4(t_fl *fl, t_fl *fl2)
{
    t_elem *elem;
    t_elem *elem2;
    
    elem = fl->first;
    elem2 = fl2->first;
    
    while (elem || elem2)
    {
        if (elem)
        {
            if (elem->prev)
			{
				print_center(elem->prev->nb, reset);
                printf(" %s-->%s ", veligreen, reset);
			}
            else
                printf("        ");
            print_center(elem->nb, magenta);
            if (elem->next)
			{
                printf(" %s-->%s ", veligreen, reset);
				print_center(elem->next->nb, reset);
				printf("    ");
			}
            else
                printf("            ");
        }
        else
            printf("                       ");
        if (elem2)
        {
            if (elem2->prev)
			{
				print_center(elem2->prev->nb, reset);
                printf(" %s-->%s ", green, reset);
			}
            else
                printf("        ");
            print_center(elem2->nb, red);
            if (elem2->next)
			{
                printf(" %s-->%s ", green, reset);
				print_center(elem2->next->nb, reset);
				printf("    ");
			}

        }
        if (elem)
            elem = elem->next;
        if (elem2)
            elem2 = elem2->next;
        if (elem || elem2)
        {
            if (elem && !elem2)
                printf("\n         %s|  \n         |  \n", magenta);
            else if (!elem && elem2)
                printf("\n                                %s|\n                                |\n", red);
            else
                printf("\n         %s|                      %s|  \n         %s|                      %s|  \n", magenta, red, magenta, red);
			printf("%s", reset);
        }
    }
    printf("\n");
}









int main(int argc, char **argv)
{
    if (argc < 2) 
        return 0;
    int i = 1;
    t_fl *fl_a = ft_init_fl();
    t_fl *fl_b = ft_init_fl();
    while (i < argc)
    {
        ft_add_back(fl_a, ft_new_elem(atoi(argv[i])));
        i++;
    }
    print_list4(fl_a, fl_b);
    ft_swap(fl_a, 1);
    
    // i = 1;
    // while (i < argc)
    // {
    //     ft_add_back(fl_a, ft_new_elem(10 * atoi(argv[i])));
    //     ft_add_back(fl_a, ft_new_elem(100 * atoi(argv[i])));
	// 	ft_add_back(fl_a, ft_new_elem(atoi(argv[i])));
    //     i++;
    // }
   
   // print_list4(fl_a, fl_b);
   
}
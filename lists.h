/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:54:51 by hlesny            #+#    #+#             */
/*   Updated: 2022/12/14 21:54:10 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LISTS_H 
# define FT_LISTS_H

typedef struct s_elem
{
    int nb;
    struct s_elem *prev;
    struct s_elem *next;
}               t_elem;

typedef struct s_fl
{
    t_elem *first;
    t_elem *last;
}               t_fl;

t_fl    *ft_init_fl(void);
t_elem    *ft_new_elem(int a);
void    ft_add_back(t_fl *fl, t_elem *new);
void    ft_del_last(t_fl *fl);
void    ft_clear(t_fl *fl);

#endif
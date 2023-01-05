/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:20:30 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/03 19:10:29 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_utils.h"
#include <stdlib.h>

t_elem    *ft_new_elem(int nb)
{
	t_elem *new;

	new = malloc(sizeof(t_elem));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void    ft_add_back(t_elem **first, t_elem *new) // *fl equivalent a **first et **last
{
	if (!first)
		return ;
	if (!*first || !(*first)->next) // ie si la liste est actuellement vide, et que va seulement ajouter le premier element
	{
		*first = new;
		(*first)->prev = new;
		(*first)->next = new;
	}
	else
	{
		new->prev = (*first)->prev; // first->prev est le dernier element de la liste
		(*first)->prev->next = new; 
		(*first)->prev = new;
		new->next = *first; 
	}
}

int     ft_lst_size(t_elem **first)
{
	int     size;
	t_elem  *elem;

	if (!first || !*first)
		return (0);
	if (*first && (*first)->next == *first)
		return (1);
	size = 1;
	elem = (*first)->next;
	while (elem != *first)
	{
		size++;
		elem = elem->next;
	}
	return (size);
}

void	ft_clear(t_elem **node_a, t_elem **node_b)
{
	// free and delete all elements of both lists
}
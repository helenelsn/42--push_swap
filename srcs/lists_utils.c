/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:20:30 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/12 16:33:27 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lists_utils.h"
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

void	ft_add_front(t_elem **first, t_elem *new)
{
	if (!first)
		return ;
	if (!*first || !(*first)->next)
	{
		*first = new;
		(*first)->prev = new;
		(*first)->next = new;
	}
	else
	{
		new->next = *first;
		new->prev = (*first)->prev;
		(*first)->prev->next = new;
		(*first)->prev = new;
		*first = new;
	}
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


// la transformer en liste simplement chainee et ensuite seulemt tout free ? 

// free and delete all elements of a list
void	ft_clear(t_elem **node)
{
	t_elem *tmp;
	int size = ft_lst_size(node);
	
	if (!node || !*node) // ie si la liste n'existe pas, ou si elle est vide
		return ;
	tmp = *node;
	while (size )
	{
		*node = (*node)->next;
		tmp->prev = NULL;
		tmp->next = NULL;
		free(tmp);
		tmp = NULL;
		tmp = *node;
		size--;
	}
	// free(tmp->prev);
	// tmp->prev = NULL;
	// tmp->next = NULL;
	// free(tmp);
	// tmp = NULL;
}

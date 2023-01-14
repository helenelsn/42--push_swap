/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:26:47 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/14 20:49:31 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ARGS_H
# define  CHECK_ARGS_H

#include <limits.h>
#include "lists_utils.h"

int     check_list(t_elem **node, char *s);
long long	ft_atoi(const char *nptr, int *j); // ok de le mettre ici ?

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 01:58:05 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/14 18:46:55 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\n'
		|| c == '\t' || c == '\v'
		|| c == '\f' || c == '\r');
}

long long	ft_atoi(const char *nptr, int *j)
{
	int	i;
	int	neg;
	long long	number;

	i = 0;
	if (j)
		i = *j;
	neg = 1;
	number = 0;
	while (nptr[i] && is_whitespace(nptr[i]))
		i++;
	if (nptr[i] && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			neg = -neg;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9') && number <= __INT_MAX__ )
	{
		number = number * 10 + (nptr[i] - 48);
		i++;
	}
	if (j)
		*j = i;
	return (neg * number);
}

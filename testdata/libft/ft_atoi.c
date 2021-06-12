/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchristo <bchristo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 02:53:22 by bchristo          #+#    #+#             */
/*   Updated: 2021/05/26 21:18:18 by bchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	ft_atoi_helper(char *n, int s, int r)
{
	int				result;
	unsigned int	digit;
	int				sign;
	const char		*nptr;

	result = r;
	sign = s;
	nptr = n;
	while (nptr)
	{
		digit = *nptr - '0';
		if (digit > 9)
			break ;
		result = (10 * result) + digit;
		nptr++;
	}
	if (sign)
		return (-result);
	return (result);
}

int	ft_atoi(const char *nptr)
{
	int				result;
	int				sign;

	result = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign = 1;
		nptr++;
	}
	else
	{
		sign = 0;
		if (*nptr == '+')
			nptr++;
	}
	result = ft_atoi_helper((char *) nptr, sign, result);
	return (result);
}

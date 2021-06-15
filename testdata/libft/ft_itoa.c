/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchristo <bchristo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 03:00:41 by bchristo          #+#    #+#             */
/*   Updated: 2021/05/28 02:40:02 by bchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*helperPlus(char *p, int *n)
{
	*--p = '0' + (*n % 10);
	*n /= 10;
	return (n);
}

static int	*helperMinus(char *p, int *n)
{
	*--p = '0' - (*n % 10);
	*n /= 10;
	return (n);
}

char	*ft_itoa(int n)
{
	static char	buf[19 + 2];
	char		*p;

	p = buf + 19 + 1;
	if (n >= 0)
	{
		while (*helperPlus(p--, &n))
			continue ;
		return (ft_substr(p, 0, ft_strlen(p)));
	}
	else
	{
		while (*helperMinus(p--, &n))
			continue ;
		*--p = '-';
	}
	return (ft_substr(p, 0, ft_strlen(p)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchristo <bchristo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:29:47 by bchristo          #+#    #+#             */
/*   Updated: 2021/06/10 20:25:23 by bchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t		srclen;

	srclen = ft_strlen(src);
	if (++srclen < n)
		ft_memcpy(dest, src, srclen);
	else if (n)
	{
		ft_memcpy(dest, src, --n);
		dest[n] = 0;
	}
	return (--srclen);
}

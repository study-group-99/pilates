/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchristo <bchristo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 21:39:31 by bchristo          #+#    #+#             */
/*   Updated: 2021/05/29 13:53:29 by bchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		len;
	size_t		dlen;

	d = dest;
	s = src;
	len = n;
	while (len-- && *d)
		d++;
	dlen = d - dest;
	len = n - dlen;
	if (len == 0)
		return (dlen + ft_strlen(s));
	while (*s)
	{
		if (len != 1)
		{
			*d++ = *s;
			len--;
		}
		s++;
	}
	*d = 0;
	return (dlen + (s - src));
}

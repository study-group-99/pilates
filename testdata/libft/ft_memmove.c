/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchristo <bchristo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:45:29 by bchristo          #+#    #+#             */
/*   Updated: 2021/06/09 04:37:35 by bchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*d;

	d = dest;
	if (dest < src)
		while (n--)
			*(char *) dest++ = *(char *) src++;
	else
	{
		src += n;
		dest += n;
		while (n--)
			*(char *)--dest = *(char *)--src;
	}
	return (d);
}

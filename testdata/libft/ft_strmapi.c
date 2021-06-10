/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchristo <bchristo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:50:58 by bchristo          #+#    #+#             */
/*   Updated: 2021/06/10 20:25:23 by bchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*r;
	unsigned int	i;

	r = (char *)malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!r)
		return (NULL);
	i = 0;
	while (*s)
	{
		r[i] = (*f)(i, *s++);
		i++;
	}
	r[i] = 0;
	return (r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchristo <bchristo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 04:01:59 by bchristo          #+#    #+#             */
/*   Updated: 2021/05/29 13:53:16 by bchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	l;
	size_t	i;
	char	*r;

	l = ft_strlen(s);
	r = malloc(++l * sizeof(char));
	if (!r)
		return (0);
	i = 0;
	while (--l)
		r[i++] = *s++;
	r[i] = 0;
	return (r);
}

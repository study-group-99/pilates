/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchristo <bchristo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 00:35:26 by bchristo          #+#    #+#             */
/*   Updated: 2021/05/28 20:11:58 by bchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	len;

	if (!*s2)
		return ((char *) s1);
	len = ft_strlen(s2);
	if (!(n < len) || !*s1)
	{
		n -= --len;
		while (n-- && *s1)
		{
			str1 = (char *) s1;
			str2 = (char *) s2;
			while (*str2 && *str1 == *str2)
			{
				str1++;
				str2++;
			}
			if (!*str2)
				return ((char *) s1);
			s1++;
		}
	}
	return (NULL);
}

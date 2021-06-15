/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchristo <bchristo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:10:01 by bchristo          #+#    #+#             */
/*   Updated: 2021/06/03 01:25:38 by bchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static size_t	sizeHelper(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
		if (*s != c && ++i)
			while (*s && *s++ != c)
				continue ;
	else
		s++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**r;
	size_t	i;

	r = (char **)malloc((sizeHelper(s, c) + 1) * sizeof(char *));
	if (!r)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!ft_strchr(s, (int) c))
			{
				r[i++] = ft_substr(s, 0, ft_strlen(s));
				break ;
			}
			r[i++] = ft_substr(s, 0, ft_strchr(s, (int) c) - s);
			s = ft_strchr(s, (int) c);
		}
		else
			s++;
	}
	r[i] = 0;
	return (r);
}

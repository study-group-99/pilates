/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchristo <bchristo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:19:16 by bchristo          #+#    #+#             */
/*   Updated: 2021/06/10 19:09:00 by bchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	void	*s;
	size_t	l1;
	size_t	l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	s = malloc(++l1 + ++l2 * sizeof(char));
	if (!s)
		return (NULL);
	ft_strlcpy((char *) s, s1, l1 + l2);
	ft_strlcat((char *) s, s2, l1 + l2);
	return ((char *) s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:23:02 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/27 12:09:42 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Compares the first 'n' bytes of the memory areas 's1' and 's2'.
 * 
 * @param s1 The first memory area.
 * @param s2 The second memory area.
 * @param n The number of bytes to compare.
 * 
 * @return An integer less than, equal to, or greater than zero if 's1' is found,
 * respectively, to be less than, to match, or be greater than 's2'.
 */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (n > i && p1[i] == p2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return (p1[i] - p2[i]);
}

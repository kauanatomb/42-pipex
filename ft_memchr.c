/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:25:58 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/24 11:15:32 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Scans the first 'n' bytes of the memory area pointed to by 's'
 * for the first occurrence of the byte 'c'.
 * 
 * @param s The memory area to search.
 * @param c The byte to look for.
 * @param n The number of bytes to examine.
 * 
 * @return A pointer to the matching byte, or NULL if the byte is not found
 * within the first 'n' bytes.
 */

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	uc;

	uc = (unsigned char)c;
	str = (unsigned char *)s;
	while (n > 0)
	{
		if (*str == uc)
			return ((void *)str);
		n--;
		str++;
	}
	return (0);
}

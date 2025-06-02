/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:55:09 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/23 21:09:58 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Copies 'len' bytes from memory area 'src' to memory area 'dst'.
 * The memory areas may overlap; the copy is always done in a safe way.
 * 
 * @param dst The destination buffer.
 * @param src The source buffer.
 * @param len The number of bytes to copy.
 * 
 * @retval NULL If both 'dst' and 'src' are NULL.
 * @return A pointer to the destination buffer 'dst'.
 */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*b_dst;
	unsigned char	*b_src;
	size_t			i;

	i = 0;
	if (!dst && !src)
		return (dst);
	b_dst = (unsigned char *) dst;
	b_src = (unsigned char *) src;
	if (b_dst < b_src)
	{
		while (i < len)
		{
			b_dst[i] = b_src[i];
			i++;
		}
	}
	else
	{
		while (len--)
		{
			b_dst[len] = b_src[len];
		}
	}
	return (dst);
}

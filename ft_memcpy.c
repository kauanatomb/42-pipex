/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:27:11 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/27 12:16:18 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Copies 'n' bytes from memory area 'src' to memory area 'dst'.
 * The memory areas must not overlap.
 * 
 * @param dst The destination buffer.
 * @param src The source buffer.
 * @param n The number of bytes to copy.
 * 
 * @retval NULL If both 'dst' and 'src' are NULL.
 * @return A pointer to the destination buffer 'dst'.
 * 
 * @note If the memory areas overlap, the behavior is undefined.
 */

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*b_dst;
	unsigned char	*b_src;

	if (!src && !dst)
		return (dst);
	b_dst = (unsigned char *) dst;
	b_src = (unsigned char *) src;
	while (n > 0)
	{
		*(b_dst++) = *(b_src++);
		n--;
	}
	return (dst);
}

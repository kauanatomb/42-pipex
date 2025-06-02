/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:35:00 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/22 17:42:35 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Fills the first 'len' bytes of the memory area pointed to by 'b'
 * with the constant byte 'c'.
 * 
 * @param b Pointer to the memory area to fill.
 * @param c The byte to fill the memory with.
 * @param len The number of bytes to fill.
 * 
 * @return A pointer to the memory area 'b'.
 */

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*buffer;

	buffer = (unsigned char *) b;
	while (len > 0)
	{
		*(buffer++) = (unsigned char) c;
		len--;
	}
	return (b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:00:46 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/23 19:25:55 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Sets the first `n` bytes of the memory area pointed to by `s` to zero.
 * 
 * @param s Pointer to the memory area to be set to zero.
 * @param n Number of bytes to set to zero.
 * 
 * @return None. The function modifies the memory in place.
 */

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*buffer;

	buffer = (unsigned char *) s;
	while (n > 0)
	{
		*(buffer++) = 0;
		n--;
	}
}

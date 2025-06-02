/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:34:38 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/23 21:45:46 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Appends the string src to the end of dst, ensuring that the result is
 *        null-terminated and does not exceed dstsize characters.
 * @param dst The destination string.
 * @param src The source string.
 * @param dstsize The size of the destination buffer.
 * @return size_t The total length of the string that would have been created
 *                if there was enough space in dst.
 */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = 0;
	i = 0;
	while (dest_len < dstsize && dst[dest_len])
	{
		dest_len++;
	}
	if (dstsize <= dest_len)
		return (dstsize + src_len);
	while (src[i] && (dest_len + i) < (dstsize - 1))
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}

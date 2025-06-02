/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 09:47:56 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/30 18:14:53 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Allocates memory for an array of `count` elements, each of size `size`,
 * and initializes all bytes to zero.
 * 
 * @param count The number of elements to allocate.
 * @param size The size of each element.
 * 
 * @return A pointer to the allocated memory, or NULL if the allocation fails.
 */

void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp;
	size_t	total_size;

	if (count && size && count > INT_MAX / size)
		return (NULL);
	total_size = count * size;
	if (total_size == 0)
		total_size = 1;
	tmp = malloc(total_size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, total_size);
	return (tmp);
}

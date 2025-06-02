/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:32:25 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/24 13:47:34 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Locates the first occurrence of the null-terminated string needle
 * in the string haystack, where not more than len characters are searched.
 * @param haystack The string to search.
 * @param needle The substring to locate.
 * @param len The maximum number of characters to search in haystack.
 * @return char*
 * @retval A pointer to the beginning of the located substring, or NULL if
 * needle is not found in haystack.
 */

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	size_t	i;

	i = 0;
	if (!needle || !haystack)
		return (NULL);
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i] && len > i)
	{
		j = 0;
		while (len > (i + j) && haystack[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}

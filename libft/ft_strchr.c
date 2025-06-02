/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:50:58 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/27 12:10:19 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Locates the first occurrence of character 'c' in the string 's'.
 * 
 * @param s The string to search in.
 * @param c The character to search for, interpreted as an unsigned char.
 * 
 * @retval NULL If the character is not found.
 * @return A pointer to the first occurrence of 'c' in 's', 
 * or to the null terminator if 'c' is '\0'.
 */

char	*ft_strchr(const char *s, int c)
{
	char	uc;

	uc = (char)c;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == uc)
		{
			return ((char *)s);
		}
		s++;
	}
	if (uc == *s)
		return ((char *)s);
	return (0);
}

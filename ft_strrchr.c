/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:20:08 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/24 09:39:52 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Locates the last occurrence of c in the string pointed to by s.
 * @param s The string to search.
 * @param c The character to locate.
 * @return char*
 * @retval A pointer to the last occurrence of c in s
 * @retval pointer to the last occurence of c in string s.
*/

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;
	char		uc;

	uc = (char)c;
	if (!s)
		return (0);
	p = 0;
	while (*s)
	{
		if (*s == uc)
			p = s;
		s++;
	}
	if (*s == uc)
		return ((char *)s);
	return ((char *)p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:23:55 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/25 11:03:58 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Allocates (with malloc) and returns a copy of the string 's1'.
 * @param s1 The string to duplicate.
 * @retval NULL If 's1' is NULL or if the memory allocation fails.
 * @return A pointer to the newly allocated copy of the string.
 */

static char	*ft_strcpy(char *dest, const char *src);

char	*ft_strdup(const char *s1)
{
	char	*dest;

	if (!s1)
		return (NULL);
	dest = malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	return (ft_strcpy(dest, s1));
}

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:54:17 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/27 19:44:35 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief
 * Removes all leading and trailing characters from 's1' 
 * that are present in 'set'.
 * @param s1 The original string to be trimmed.
 * @param set The set of characters to trim from the beginning and end of 's1'.
 * @return A newly allocated string with the trimmed content.
 *         Returns an empty string if all characters are trimmed.
 *         Returns NULL if memory allocation fails.
 */

static int	to_trim(const char *set, char c);

static char	*new_str(const char *s1, size_t start, size_t len);

char	*ft_strtrim(const char *s1, const char *set)
{
	int	start;
	int	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	if (*s1 == 0)
		return (ft_strdup(""));
	while (s1[start] && to_trim(set, s1[start]))
		start++;
	while (end > start && to_trim(set, s1[end - 1]))
		end--;
	return (new_str(s1, start, end - start));
}

static char	*new_str(const char *s1, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	return (str);
}

static int	to_trim(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

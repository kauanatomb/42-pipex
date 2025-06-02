/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 08:48:45 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/29 11:47:26 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @fn char **ft_split(const char *s, char c)
 * Splits the string s on the char c and returns an array of string pointers
 * @param s string to split
 * @param c char to split the string on
 * @return char**
 * @retval NULL terminated array of char*
*/

static int	word_count(const char *str, char c);
static char	**ft_free(char **strs, int count);
static char	*fill_word(const char *start, size_t len);

char	**ft_split(const char *s, char c)
{
	char		**res;
	size_t		i;
	const char	*start;

	i = 0;
	if (!s)
		return (NULL);
	res = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			start = s;
			while (*s && *s != c)
				s++;
			res[i] = fill_word(start, s - start);
			if (!res[i++])
				return (ft_free(res, i - 1));
		}
	}
	return (res);
}

static int	word_count(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

static char	**ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(strs[i++]);
	free(strs);
	return (NULL);
}

static char	*fill_word(const char *start, size_t len)
{
	char	*word;
	size_t	i;

	i = 0;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:33:54 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/29 11:51:07 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Applies a function to each character of a string, 
 * creating a new string from the results.
 * Iterates over the input string `s`, applying the function `f` 
 * to each character and its index.
 * A new string is allocated to store the results of these function applications.
 *
 * Memory for the new string is obtained with malloc(3) 
 * and must be freed by the caller.
 *
 * @param s The input string to iterate over.
 * @param f The function to apply to each character and its index.
 * @return A pointer to the newly allocated string resulting from 
 * the function applications, or NULL if memory allocation fails or 
 * if `s` or `f` is NULL.
 */

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (!s || !f)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

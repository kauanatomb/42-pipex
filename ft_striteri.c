/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:39:28 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/29 12:27:14 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies a function to each char of a string, modifying it in place.
 *
 * Iterates through the string `s`, applying the function `f` to each character.
 * The function `f` receives the index of the character and a pointer to the 
 * character itself, allowing modification of the original string.
 *
 * @param s The string to iterate over and modify.
 * @param f The function to apply to each character, which takes the index and 
 * a pointer to the character.
 */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:08:22 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/22 16:59:46 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h" 

/**
 * @brief Checks if the given character is an alphabetic letter (A-Z or a-z).
 * 
 * @param c The character to check.
 * 
 * @return 1 if the character is alphabetic (between 'A' and 'Z' or 'a' and 'z'),
 * otherwise 0.
 */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

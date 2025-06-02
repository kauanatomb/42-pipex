/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:58:17 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/28 14:13:08 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts an integer into its corresponding ASCII string representation.
 *
 * This function allocates a new null-terminated string representing 
 * the given integer `n`. Handles negative numbers and zero correctly.
 *
 * Memory for the resulting string is obtained with malloc(3) 
 * and must be freed by the caller.
 * @param n The integer to convert.
 * @return A pointer to the newly allocated string, or NULL if the 
 * allocation fails.
 */

static int	count_int(long n);

char	*ft_itoa(int n)
{
	size_t	len;
	long	nbr;
	char	*res;
	int		i;

	nbr = n;
	len = count_int(nbr);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nbr == 0)
		res[0] = '0';
	if (nbr < 0)
	{
		nbr = -nbr;
		res[0] = '-';
	}
	i = len - 1;
	while (nbr > 0)
	{
		res[i--] = ((nbr % 10) + '0');
		nbr = nbr / 10;
	}
	return (res);
}

static int	count_int(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:47:56 by ktombola          #+#    #+#             */
/*   Updated: 2025/05/12 13:48:28 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned int n, char c)
{
	int	count;
	int	res;

	count = 0;
	res = 0;
	if (n >= 16)
	{
		res = ft_puthex(n / 16, c);
		if (ft_safeadd(&count, res) == -1)
			return (-1);
	}
	if (c == 'X')
		res = ft_putchar("0123456789ABCDEF"[n % 16]);
	else
		res = ft_putchar("0123456789abcdef"[n % 16]);
	if (ft_safeadd(&count, res) == -1)
		return (-1);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:43:44 by ktombola          #+#    #+#             */
/*   Updated: 2025/05/12 13:44:06 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	int		count;
	int		res;
	long	nb;

	nb = n;
	count = 0;
	res = 0;
	if (nb < 0)
	{
		res = ft_putchar('-');
		if (ft_safeadd(&count, res) == -1)
			return (-1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		res = ft_putnbr(nb / 10);
		if (ft_safeadd(&count, res) == -1)
			return (-1);
	}
	res = ft_putchar('0' + (nb % 10));
	if (ft_safeadd(&count, res) == -1)
		return (-1);
	return (count);
}

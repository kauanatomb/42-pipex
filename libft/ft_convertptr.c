/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:41:21 by ktombola          #+#    #+#             */
/*   Updated: 2025/05/15 16:26:22 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_address(uintptr_t n, int count)
{
	int	res;

	res = 0;
	if (n >= 16)
	{
		res = ft_print_address(n / 16, res);
		if (ft_safeadd(&count, res) == -1)
			return (-1);
	}
	res = ft_putchar("0123456789abcdef"[n % 16]);
	if (ft_safeadd(&count, res) == -1)
		return (-1);
	return (count);
}

int	ft_convertptr(void *ptr)
{
	uintptr_t		n;
	int				count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	n = (uintptr_t)ptr;
	count = 0;
	count = ft_putstr("0x");
	if (count != 2)
		return (-1);
	return (ft_print_address(n, count));
}

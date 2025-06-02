/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:49:33 by ktombola          #+#    #+#             */
/*   Updated: 2025/05/12 13:49:38 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	int	count;
	int	res;

	if (!s)
		return (ft_putstr("(null)"));
	count = 0;
	res = 0;
	while (*s)
	{
		res = ft_putchar(*s++);
		if (ft_safeadd(&count, res) == -1)
			return (-1);
	}
	return (count);
}

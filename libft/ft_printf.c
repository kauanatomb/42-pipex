/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:06:58 by ktombola          #+#    #+#             */
/*   Updated: 2025/05/15 16:25:30 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_format(char c, va_list *args)
{
	if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'c')
		return (ft_putchar((char) va_arg(*args, int)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_putunsign_int(va_arg(*args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), c));
	else if (c == '%')
		return (ft_putchar(c));
	else if (c == 'p')
		return (ft_convertptr(va_arg(*args, void *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		count;
	int		res;

	count = 0;
	va_start(args, str);
	i = 0;
	while (str[i])
	{
		res = 0;
		if (str[i] == '%' && str[i + 1])
			res = check_format(str[++i], &args);
		else
			res = ft_putchar(str[i]);
		if (ft_safeadd(&count, res) == -1)
			return (-1);
		i++;
	}
	va_end(args);
	return (count);
}

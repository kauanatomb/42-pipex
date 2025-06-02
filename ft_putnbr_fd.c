/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:19:57 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/29 13:42:07 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief ft_putnbr_fd - Outputs an integer to the given file descriptor.
 *
 * @param n: The integer to be written.
 * @param fd: The file descriptor on which to write.
 *
 * This function prints the integer `n` to the specified file descriptor `fd`
 * using only the `write` system call. It handles negative numbers,
 * including the edge case of INT_MIN (-2147483648), by writing each digit 
 * individually without converting the number into a string.
 */

void	ft_putnbr_fd(int n, int fd)
{
	char	s_nbr;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
		{
			s_nbr = n + 48;
			write(fd, &s_nbr, 1);
		}
	}
}

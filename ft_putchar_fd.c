/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:20:55 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/29 12:24:54 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a character to the given file descriptor.
 *
 * Sends the character `c` to the output specified by the file descriptor `fd`.
 *
 * @param c The character to write.
 * @param fd The file descriptor on which to write (e.g., 1 for stdout, 
 * 2 for stderr).
 */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:43:23 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/29 13:14:18 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a string to the specified file descriptor, 
 * followed by a newline.
 *
 * Outputs the string `s` to the file descriptor `fd`, followed by 
 * a newline character (`\n`).
 * If `s` is NULL, the function does nothing.
 *
 * @param s The string to write.
 * @param fd The file descriptor to write to.
 */

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

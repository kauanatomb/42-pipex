/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:55:26 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/30 08:41:24 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Creates a new list node.
 *
 * Allocates (with malloc) and returns a new node.
 * The member var `content` is initialized with the value parameter `content`.
 * The `next` pointer is set to NULL.
 *
 * @param content The content to store in the new node.
 * @return A pointer to the new node, or NULL if the allocation fails.
 */

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:47:33 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/30 10:53:25 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Returns the last node of a linked list.
 *
 * Iterates through the list starting from the given node,
 * and returns a pointer to the last node (i.e., the one
 * whose 'next' is NULL).
 *
 * @param lst A pointer to the first node of the list.
 *
 * @return A pointer to the last node of the list,
 *         or NULL if the list is empty.
 */

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

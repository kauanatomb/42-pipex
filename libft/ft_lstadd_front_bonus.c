/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:26:32 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/30 09:42:56 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds the node 'new' at the beginning of the list.
 *
 * This function sets the 'next' pointer of the 'new' node to point to
 * the current head of the list, then updates the list's head to be 'new'.
 *
 * @param lst A pointer to the pointer to the first node of the list.
 * @param new The node to add to the front of the list.
 */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

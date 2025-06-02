/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:42:54 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/30 12:59:00 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Deletes and frees all nodes of a list.
 *
 * Iterates through the list and applies the 'del' function
 * to the content of each node, then frees each node.
 * Finally, sets the list pointer to NULL.
 *
 * @param lst A pointer to the pointer to the first node.
 * @param del A function to delete the content of each node.
 */

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}

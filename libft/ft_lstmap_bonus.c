/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:41:08 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/30 14:01:42 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Applies a function to each node's content and builds a new list.
 *
 * Iterates through the given list, applies function 'f' to the content
 * of each node, and creates a new list resulting from the successive
 * applications of 'f'. The 'del' function is used to delete the content
 * of a node if allocation fails at any point.
 *
 * @param lst The list to iterate through.
 * @param f The function to apply to each node's content.
 * @param del The function to delete content in case of failure.
 * @return A new list, or NULL if allocation fails.
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:09:50 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/30 13:16:08 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Iterates through the list and applies a function 
 * to each node's content.
 *
 * Applies the function 'f' to the content of each node in the list.
 * Does not modify the list structure itself.
 *
 * @param lst A pointer to the first node of the list.
 * @param f A function to apply to each node's content.
 */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (!lst || !f)
		return ;
	tmp = lst;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}

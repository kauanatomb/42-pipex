/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:25:24 by ktombola          #+#    #+#             */
/*   Updated: 2025/04/30 12:31:52 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * @brief Deletes and frees a single list node.
 *
 * The function applies the provided 'del' function to the node's content,
 * and then frees the memory of the node itself.
 * The memory of the 'next' node is not affected.
 *
 * @param lst The node to delete.
 * @param del A function to delete the content of the node.
 */

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

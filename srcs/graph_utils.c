/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 19:46:05 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/21 20:30:28 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*get_node_by_name(t_anthill *anthill, char *name)
{
	t_list	*node_list;

	if ((node_list = anthill->nodes) == NULL)
		return (NULL);
	while (node_list)
	{
		if (ft_strequ(((t_node *)(node_list->content))->node_name, name))
			return ((t_node *)(node_list->content));
		node_list = node_list->next;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 19:46:05 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/22 22:46:54 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node			*get_node_by_name(t_anthill *anthill, char *name)
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

static void		disp_links_data(t_list *links)
{
	ft_dprintf(2, "Linked to \'%s\' .\n",
		(char *)((t_node *)links->content)->node_name);
}

static void		disp_node_data(t_list *elem)
{
	t_node *node;

	node = (t_node*)(elem->content);
	ft_dprintf(2, "Node \'%s\' (weight %d) at %d %d .\n",
		node->node_name, node->weight,
		node->coord_x, node->coord_y);
	if (node->links)
		ft_lstiter(node->links, disp_links_data);
}

void			disp_graph_data(t_anthill *anthill)
{
	ft_putendl("This is the content of the graph (after applying weights):");
	ft_lstiter(anthill->nodes, disp_node_data);
	ft_putchar('\n');
}

void			ft_free_exit(t_anthill *anthill, char *message,
				int disp_errno, int must_exit)
{
	empty_anthill(anthill);
	ft_exit(message, disp_errno, must_exit);
}

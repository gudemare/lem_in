/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:15:17 by mgonon            #+#    #+#             */
/*   Updated: 2018/02/21 20:46:31 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Call apply_weight with end_node and weight 0
*/

void	apply_weight(t_node *node, int weight)
{
	t_list	*links;

	links = node->links;
	while (links && node != start_node)
	{
		if (node->weight == -1 || weight < node->weight)
			node->weight = weight;
		if (links->next->content->weight == -1 || links->next->content->weight > node->weight)
			apply_weight(links->next->content, weight++);
		links = links->next;
	}
}

/*
** Call shortest_path with start_node
*/

t_links	*shortest_path(t_node *node)
{
	t_list	*links;
	int		weight;

	links = node->links;
	weight = node->weight;
	if (weight == 0)
		ft_exit("Debug exit: Sucess to find end_node.", 0, 1);
	node = links->content;
    while (node->weight != weight - 1 && links->next)
	{
        links = links->next;
		node = links->content;
	}
	if (link_weight == weight - 1)
		shortest_path(node);
	else
		ft_exit("Error : No path found.", 0, 1);
}
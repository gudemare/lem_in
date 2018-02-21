/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:15:17 by mgonon            #+#    #+#             */
/*   Updated: 2018/02/21 21:37:34 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Call apply_weight with end_node and weight 0
*/

static void	apply_weight(t_node *node, t_node *start_node, int weight)
{
	t_list	*links;

	printf("weight = %d\n", weight);
	links = node->links;
	while (links)
	{
		printf("name = %s\n", node->node_name);
		
	}
	// if (node == start_node)
	// {
	// 	node->weight = weight;
	// 	return ;
	// }
	// while (links)
	// {
	// 	if (node->weight == -1 || weight < node->weight)
	// 		node->weight = weight;
	// 	if (((t_node *)(links->content))->weight == -1
	// 		|| ((t_node *)(links->content))->weight > node->weight + 1)
	// 		apply_weight(links->next->content, start_node, weight + 1);
	// 	links = links->next;
	// }
}

/*
** Call shortest_path with start_node
*/
/*
t_list	*shortest_path(t_node *node, t_list *shortest_path)
{
	t_list	*links;
	int		weight;

	return (NULL);
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
		shortest_path(node, shortest_path);
	else
		ft_exit("Error : No path found.", 0, 1);
}*/

void	resolve_graph(t_anthill *anthill)
{
	apply_weight(anthill->end_node, anthill->start_node, 0);
//	shortest_path(anthill->start_node, anthill->shortest_path);
}
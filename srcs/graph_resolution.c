/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:15:17 by mgonon            #+#    #+#             */
/*   Updated: 2018/02/22 17:03:02 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

/*
** Call apply_weight with end_node and weight 0
*/

static void	apply_weight(t_node *node, t_node *start_node, int weight)
{
	t_list	*links;

	// printf("weight = %d\n", weight);
	// printf("%s->", node->node_name);
	links = node->links;
	if (node == start_node)
	{
		// printf("\ndone\n");
		node->weight = weight;
		return ;
	}
	while (links)
	{
		if (node->weight == -1 || weight < node->weight)
			node->weight = weight;
		if (((t_node *)(links->content))->weight == -1
			|| ((t_node *)(links->content))->weight > node->weight + 1)
		{
			// printf("%s->", ((t_node *)(links->content))->node_name);			
			// printf("next = %s\n\n", ((t_node *)(links->next->content))->node_name);			
			apply_weight(((t_node *)(links->content)), start_node, weight + 1);
		}
		links = links->next;
	}
}

/*
** Call get_shortest_path with start_node and empty t_list for shortest_path
*/

t_list	*get_shortest_path(t_node *node, t_list *shortest_path)
{
	t_list	*links;
	int		weight;

	// return (NULL);
	links = node->links;
	weight = node->weight;
	if (weight == 0)
		ft_exit("Debug exit: Sucess to find end_node.", 0, 1);
	node = ((t_node *)(links->content));
    while (node->weight != weight - 1 && links->next)
	{
        links = links->next;
		node = ((t_node *)(links->content));
	}
	if (node->weight == weight - 1)
	{
		printf("node = %s\n", node->node_name);
		// add_link_list(((t_node *)(shortest_path->content)), node);
		get_shortest_path(node, shortest_path->next);
	}
	else
		ft_exit("Error : No path found.", 0, 1);
	return (NULL);
}

void	resolve_graph(t_anthill *anthill)
{
	// if (!(anthill->shortest_path = ft_lstnew(NULL, 0)))
	// 	ft_exit("Error : Insufficient memory.", 1, 1);
	// anthill->shortest_path->content_size = sizeof(t_node *);
	// anthill->shortest_path->content = (void *)anthill->start_node;
	apply_weight(anthill->end_node, anthill->start_node, 0);
	get_shortest_path(anthill->start_node, anthill->shortest_path);
}
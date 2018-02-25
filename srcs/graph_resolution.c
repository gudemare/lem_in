/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:15:17 by mgonon            #+#    #+#             */
/*   Updated: 2018/02/25 16:52:53 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

/*
** Parameters: node = end_node, weight = 0
*/

static void		apply_weight(t_node *node, t_node *start_node, int weight,
				t_anthill *anthill)
{
	t_list	*links;

	if (!node || !start_node || !(links = node->links))
		ft_free_exit(anthill, "Error : No path found.", 0, 1);
	if (node == start_node)
	{
		node->weight = weight;
		return ;
	}
	while (links)
	{
		if (node->weight == -1 || weight < node->weight)
			node->weight = weight;
		if (((t_node *)(links->content))->weight == -1
			|| ((t_node *)(links->content))->weight > node->weight + 1)
			apply_weight(((t_node *)(links->content)), start_node, weight + 1,
				anthill);
		links = links->next;
	}
}

/*
** Parameters: node = start_node, i = 1
*/

static void		get_shortest_path(t_node *node, char **shortest_path, int i,
				t_anthill *anthill)
{
	t_list	*links;
	int		weight;

	if (!(links = node->links))
		ft_free_exit(anthill, "Error : No path found.", 0, 1);
	weight = node->weight;
	if (weight == 0)
		return ;
	node = ((t_node *)(links->content));
	while (node->weight != weight - 1 && links->next)
	{
		links = links->next;
		node = ((t_node *)(links->content));
	}
	if (node->weight == weight - 1)
	{
		if (!(shortest_path[i] = ft_strdup(node->node_name)))
			ft_free_exit(anthill, "Malloc error.", 1, 1);
		get_shortest_path(node, shortest_path, i + 1, anthill);
	}
	else
		ft_free_exit(anthill, "Error : No path found.", 0, 1);
}

void			resolve_graph(t_anthill *anthill)
{
	size_t	path_size;

	apply_weight(anthill->end_node, anthill->start_node, 0, anthill);
	path_size = (size_t)(anthill->start_node->weight + 1);
	anthill->path_length = path_size;
	if (!(anthill->shortest_path =
		(char **)malloc(sizeof(char *) * path_size + 1)))
		ft_free_exit(anthill, "Error : Insufficient memory.", 1, 1);
	if (!(anthill->shortest_path[0] =
		ft_strdup(anthill->start_node->node_name)))
		ft_free_exit(anthill, "Error : Insufficient memory.", 1, 1);
	anthill->shortest_path[path_size] = NULL;
	get_shortest_path(anthill->start_node, anthill->shortest_path, 1, anthill);
}

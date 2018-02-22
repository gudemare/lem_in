/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:15:17 by mgonon            #+#    #+#             */
/*   Updated: 2018/02/22 18:46:47 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

/*
** Call apply_weight with end_node and weight 0
*/

static void		apply_weight(t_node *node, t_node *start_node, int weight)
{
	t_list	*links;

	links = node->links;
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
			apply_weight(((t_node *)(links->content)), start_node, weight + 1);
		links = links->next;
	}
}

/*
** Call get_shortest_path with start_node and empty t_list for shortest_path
*/

static void		get_shortest_path(t_node *node, char **shortest_path, int i)
{
	t_list	*links;
	int		weight;

	links = node->links;
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
		shortest_path[i] = ft_strdup(node->node_name);
		get_shortest_path(node, shortest_path, i + 1);
	}
	else
		ft_exit("Error : No path found.", 0, 1);
}

static void		debug_path(char **shortest_path)
{
	int	i;

	i = -1;
	ft_printf("The shortest path is: ");
	while (shortest_path[++i])
		ft_printf("%s ", shortest_path[i]);
	ft_printf("\n");
}

void			resolve_graph(t_anthill *anthill)
{
	int	path_size;

	apply_weight(anthill->end_node, anthill->start_node, 0);
	path_size = anthill->start_node->weight + 1;
	if (!(anthill->shortest_path =
		(char **)malloc(sizeof(char *) * path_size + 1)))
		ft_exit("Error : Insufficient memory.", 1, 1);
	if (!(anthill->shortest_path[0] =
		ft_strdup(anthill->start_node->node_name)))
		ft_exit("Error : Insufficient memory.", 1, 1);
	anthill->shortest_path[path_size] = NULL;
	get_shortest_path(anthill->start_node, anthill->shortest_path, 1);
	debug_path(anthill->shortest_path);
}

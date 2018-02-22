/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:41:28 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/22 19:41:51 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"

void		empty_node_links(void *links_input, size_t size)
{
	return ;
	(void)size;
	(void)links_input;
}

void		empty_node(void *node_input, size_t size)
{
	t_node	*node;

	(void)size;
	node = (t_node *)node_input;
	if (node->node_name)
		ft_strdel(&(node->node_name));
	if (node->links)
		ft_lstdel(&(node->links), empty_node_links);
	free(node);
}

static void	empty_anthill(t_anthill *anthill)
{
	if (anthill->entry_file)
		ft_strdel(&(anthill->entry_file));
	if (anthill->shortest_path)
		ft_free_arr(anthill->shortest_path);
	if (anthill->nodes)
		ft_lstdel(&(anthill->nodes), empty_node);
	free(anthill);
}

int			main(void)
{
	t_anthill	*anthill;

	anthill = fill_anthill();
	ft_putendl(anthill->entry_file);
	resolve_graph(anthill);
	display_path(anthill->shortest_path,
		anthill->path_length, anthill->ant_nb);
	empty_anthill(anthill);
	return (0);
}

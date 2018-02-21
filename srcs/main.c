/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:41:28 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/21 21:25:13 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"

void		empty_node_links(void *links_input, size_t size)
{
	t_list	*links;

	(void)size;
	ft_dprintf(2, "Emptying node links...\n");
	links = (t_list *)links_input;
	if (links->content)
		ft_strdel((char **)&(links->content));
}

void		empty_node(void *node_input, size_t size)
{
	t_node	*node;

	(void)size;
	node = (t_node *)node_input;
	ft_dprintf(2, "Emptying node \'%s\' (weight %d) at %d %d...\n", node->node_name, node->weight, node->coord_x, node->coord_y);
	if (node->node_name)
		ft_strdel(&(node->node_name));
	if (node->links)
		ft_lstdel(&(node->links), empty_node_links);
}

static void	empty_anthill(t_anthill *anthill)
{
	if (anthill->entry_file)
		ft_strdel(&(anthill->entry_file));
	ft_dprintf(2, "Emptying anthill...\n");
	if (anthill->nodes)
		ft_lstdel(&(anthill->nodes), empty_node);
	free(anthill);
}

int			main(void)
{
	t_anthill	*anthill;

	anthill = fill_anthill();
	ft_putendl(anthill->entry_file);
	ft_putendl("Here comes the resolution.");
	resolve_graph(anthill);
	empty_anthill(anthill);
	return (0);
}

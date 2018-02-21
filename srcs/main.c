/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:41:28 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/21 17:21:42 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"

void		empty_node_links(void *links_input, size_t size)
{
	t_list	*links;

	(void)size;
	links = (t_list *)links_input;
	if (links->content)
		ft_strdel((char **)&(links->content));
}

void		empty_node(void *node_input, size_t size)
{
	t_node	*node;

	(void)size;
	node = (t_node *)node_input;
	if (node->node)
		ft_strdel(&(node->node));
	if (node->links)
		ft_lstdel(&(node->links), empty_node_links);
}

static void	empty_anthill(t_anthill *anthill)
{
	if (anthill->entry_file)
		ft_strdel(&(anthill->entry_file));
	if (anthill->start_node)
		ft_strdel(&(anthill->start_node));
	if (anthill->end_node)
		ft_strdel(&(anthill->end_node));
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
	empty_anthill(anthill);
	return (0);
}

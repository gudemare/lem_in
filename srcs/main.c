/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:41:28 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/23 13:23:43 by mgonon           ###   ########.fr       */
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

void		empty_anthill(t_anthill *anthill)
{
	if (anthill->entry_file)
		ft_strdel(&(anthill->entry_file));
	if (anthill->shortest_path)
		ft_free_arr(anthill->shortest_path);
	if (anthill->nodes)
		ft_lstdel(&(anthill->nodes), empty_node);
	free(anthill);
}

static void	display_path(char **path, size_t path_len, int ant_nb)
{
	int		last_ant;
	int		last_ant_pos;
	int		pos;

	last_ant = 1;
	last_ant_pos = 1;
	while (last_ant_pos < (int)path_len)
	{
		ft_printf("L%d-%s", last_ant, path[last_ant_pos]);
		pos = 1;
		while (last_ant - pos > 0 && path[last_ant_pos + pos])
		{
			ft_printf(" L%d-%s", last_ant - pos, path[last_ant_pos + pos]);
			pos++;
		}
		ft_putchar('\n');
		if (last_ant == ant_nb)
			last_ant_pos++;
		else
			last_ant++;
	}
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

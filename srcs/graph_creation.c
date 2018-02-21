/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:29:02 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/21 19:27:05 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** If a node is incorrect, then we have no links because input stops.
** We just have to display an error and exit. // NO (memory leak !)
** The char* input on both functions is the untreated entry line.
*/

static t_node	*get_node_data(char *node_input)
{
	t_node		*node;
	int			i;

	if (!(node = ft_memalloc(sizeof(t_node))))
		ft_exit("Error : Insufficient memory.", 1, 1);
	i = ft_strchr_loc(node_input, ' ') + 1;
	if (!(node->node_name = ft_strsub(node_input, 0, i)))
		ft_exit("Error : Insufficient memory.", 1, 1);
	node->coord_x = ft_atoi(node_input + i);
	i += (node_input[i] == '+' || node_input[i] == '-');
	while (ft_isdigit(node_input[i]))
		i++;
	if (node_input[i] != ' ')
		ft_exit("Error : Bad X coordinates formating.", 0, 1);
	i++;
	node->coord_y = ft_atoi(node_input + i);
	i += (node_input[i] == '+' || node_input[i] == '-');
	while (ft_isdigit(node_input[i]))
		i++;
	if (node_input[i] != '\0')
		ft_exit("Error : Bad Y coordinates formating.", 0, 1);
	node->weight = -1;
	node->links = NULL;
	return (node);
}

int				add_node(t_anthill *anthill, char *node_input, int last_command)
{
	t_node		*node;
	t_list		*node_list;

	if (!(node_list = ft_lstnew(NULL, 0)))
		ft_exit("Error : Insufficient memory.", 1, 1);
	node_list->content_size = sizeof(t_node);
	node = get_node_data(node_input);
	node_list->content = (void *)node;
	ft_lstadd(&(anthill->nodes), node_list);
	if (last_command == e_START)
		anthill->start_node = node;
	else if (last_command == e_END)
		anthill->end_node = node;
	return (1);
}

int				add_link(t_anthill *anthill, char *link_input)
{
	(void)anthill;
	(void)link_input;
	return (1);
}

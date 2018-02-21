/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:29:02 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/21 20:48:17 by gudemare         ###   ########.fr       */
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
	i = ft_strchr_loc(node_input, ' ');
	if (!(node->node_name = ft_strsub(node_input, 0, i)))
		ft_exit("Error : Insufficient memory.", 1, 1);
	i++;
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
	t_list		*node_list_new;

	if (!(node_list_new = ft_lstnew(NULL, 0)))
		ft_exit("Error : Insufficient memory.", 1, 1);
	node_list_new->content_size = sizeof(t_node);
	node = get_node_data(node_input);
	node_list_new->content = (void *)node;
	ft_lstadd(&(anthill->nodes), node_list_new);
	if (last_command == e_START)
		anthill->start_node = node;
	else if (last_command == e_END)
		anthill->end_node = node;
	return (1);
}

static int		add_link_list(t_node *link_start, t_node *link_end)
{
	t_list	*link_list_new;

	if (!(link_list_new = ft_lstnew(NULL, 0)))
		ft_exit("Error : Insufficient memory.", 1, 1);
	link_list_new->content_size = sizeof(t_node *);
	link_list_new->content = (void *)link_end;
	ft_lstadd(&(link_start->links), link_list_new);
	return (1);
}

int				add_link(t_anthill *anthill, char *link_input)
{
	t_node	*link_start;
	t_node	*link_end;
	char	*tmp_name;

	if (ft_strchr_count(link_input, '-') > 1)
		return (0);
	if (!(tmp_name = ft_strsub(link_input, 0, ft_strchr_loc(link_input, '-'))))
		ft_exit("Error : Insufficient memory.", 1, 1);
	if (!(link_start = get_node_by_name(anthill, tmp_name)))
		ft_exit("Error : Bad node name in link.", 1, 1);
	ft_strdel(&tmp_name);
	if (!(tmp_name = ft_strsub(link_input, ft_strchr_loc(link_input, '-') + 1,
		ft_strlen(link_input))))
		ft_exit("Error : Insufficient memory.", 1, 1);
	if (!(link_end = get_node_by_name(anthill, tmp_name)))
		ft_exit("Error : Bad node name in link.", 1, 1);
	ft_strdel(&tmp_name);
	return (add_link_list(link_start, link_end));
}

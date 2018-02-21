/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 04:52:57 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/21 21:29:57 by mgonon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

/*
** Graph data structure is as follows :
** t_anthill is the whole graph.
** |-entry_file is the complete, unchanged text copy of the valid input.
** |-ant_nb is the number of ants. (duh)
** |-start_node is the *name* of the start node.
** |-end_node is the *name* of the end node.
** |-nodes is a linked list containing all nodes.
** This linked list contains a t_node struct as its *content, as follows :
** |-node is the name of the node.
** |-coord_x and coord_y are coordinates of the node in 2D space.
** |-links is a linked list containing each individual node *name*
**			linked to this node.
*/

typedef struct		s_node
{
	char			*node_name;
	int				weight;
	int				coord_y;
	int				coord_x;
	t_list			*links;
}					t_node;

typedef struct		s_anthill
{
	char			*entry_file;
	int				ant_nb;
	t_node			*start_node;
	t_node			*end_node;
	t_list			*nodes;
	t_list			*shortest_path;
}					t_anthill;

enum				e_line_type
{
	e_COMMAND,
	e_COMMENT,
	e_NODE,
	e_LINK,
	e_INCORRECT
};

enum				e_command
{
	e_START,
	e_END,
	e_OTHER
};

t_anthill			*fill_anthill(void);
int					get_line_type(char *str);
int					get_command(char *str);
int					add_node(t_anthill *anthill, char *node_input,
					int last_command);
int					add_link(t_anthill *anthill, char *link_input);
t_node				*get_node_by_name(t_anthill *anthill, char *name);
void				resolve_graph(t_anthill *anthill);

#endif

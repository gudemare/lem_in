/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 04:52:57 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/20 23:39:53 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef struct		s_anthill
{
	char			*entry_file;
	t_list			nodes;
	int				ant_nb;
	char			*start_node;
	char			*end_node;
}					t_anthill;

typedef struct		s_node
{
	char			*node;
	int				coord_y;
	int				coord_x;
	t_list			*links;
}					t_node;

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
int					add_node(t_anthill *anthill, char *node, int last_command);
int					add_link(t_anthill *anthill, char *link);

#endif

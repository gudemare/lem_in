/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 20:46:43 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/22 20:44:15 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Parsing does not support whitespaces differences.
** Format supported is strictly :
** "[nb]" for first line
** "[name] [nb] [nb]" for nodes
** "[name]-[name]" for edges
** "##*" for commands.
** "#*" for comments.
** A ft_strip_whitespaces may get bonus points for supported formats ?
** Probably not worth it.
*/

static void		get_ant_nb(t_anthill *anthill)
{
	char	*str;
	int		i;

	if (get_next_line(0, &str, 64) != 1)
		ft_exit("Error : Cannot read input.", 1, 1);
	if (!*str)
	{
		ft_strdel(&str);
		ft_exit("Error : No ant number.", 0, 1);
	}
	i = (*str == '+');
	while (str[i])
		if (!ft_isdigit(str[i++]))
		{
			ft_strdel(&str);
			ft_exit("Error : Bad ant number formating.", 0, 1);
		}
	anthill->ant_nb = ft_atoi(str);
	anthill->entry_file = ft_strjoin(str, "\n");
	ft_strdel(&str);
	if (anthill->ant_nb <= 0)
		ft_exit("Error : Bad ant number.", 0, 1);
	if (!anthill->entry_file)
		ft_exit("Error : Insufficient memory.", 1, 1);
}

static int		add_data(t_anthill *anthill, char *str, int line_type)
{
	static int	last_command = e_OTHER;
	static int	type_processed = e_NODE;
	int			ret;

	ret = 0;
	if (line_type == e_COMMENT || line_type == e_COMMAND)
		ret = 1;
	else if (line_type == e_LINK)
	{
		type_processed = e_LINK;
		ret = add_link(anthill, str);
	}
	else if (line_type == e_NODE)
	{
		ret = (type_processed == e_LINK) ? 0 :
			add_node(anthill, str, last_command);
	}
	last_command = get_command(str, last_command);
	return (ret);
}

static void		get_graph(t_anthill *anthill)
{
	char	*str;
	int		ret;
	int		line_type;

	ret = get_next_line(0, &str, 64);
	while (ret == 1 && (line_type = get_line_type(str)) != e_INCORRECT)
	{
		if (!add_data(anthill, str, line_type))
			break ;
		if (!(anthill->entry_file = ft_strjoin(anthill->entry_file, str))
			|| !(anthill->entry_file = ft_strjoin(anthill->entry_file, "\n")))
			ft_exit("Error : Insufficient memory.", 1, 1);
		ft_strdel(&str);
		ret = get_next_line(0, &str, 64);
	}
	ft_strdel(&str);
	if (anthill->end_node)
		anthill->end_node->weight = 0;
}

t_anthill		*fill_anthill(void)
{
	t_anthill	*anthill;

	if (!(anthill = ft_memalloc(sizeof(t_anthill))))
		ft_exit("Error : Insufficient memory.", 1, 1);
	anthill->nodes = NULL;
	anthill->start_node = NULL;
	anthill->end_node = NULL;
	anthill->shortest_path = NULL;
	get_ant_nb(anthill);
	get_graph(anthill);
	return (anthill);
}

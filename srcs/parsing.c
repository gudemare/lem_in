/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 20:46:43 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/20 22:35:48 by gudemare         ###   ########.fr       */
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

static void		get_nodes(t_anthill *anthill)
{
	char	*str;
	int		ret;

	ret = get_next_line(0, &str, 64);
	while (ret == 1)
	{
		ret = get_next_line(0, &str, 64);
	}
	(void)anthill;
	ft_strdel(&str);
}

t_anthill		*fill_anthill(void)
{
	t_anthill	*anthill;

	if (!(anthill = ft_memalloc(sizeof(t_anthill))))
		ft_exit("Error : Insufficient memory.", 1, 1);
	get_ant_nb(anthill);
	get_nodes(anthill);
	return (anthill);
}

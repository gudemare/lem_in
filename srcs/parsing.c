/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 20:46:43 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/20 20:53:06 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		get_ant_nb(void)
{
	int		ant_nb;
	char	*str;
	int		i;

	if (get_next_line(0, &str, 64) != 1)
	{
		ft_strdel(&str);
		ft_exit("Cannot read input.", 1, 1);
	}
	while (ft_is_whitespace(*str))
		str++;
	i = 1;
	if (!*str || (*str != '+' && !ft_isdigit(*str)))
		ft_exit("Bad ant number formating.", 0, 1);
	while (str[i])
		if (!ft_isdigit(str[i++]))
			ft_exit("Bad ant number formating.", 0, 1);
	if ((ant_nb = ft_atoi(str)) < 0)
	{
		ft_strdel(&str);
		ft_exit("Bad ant number.", 0, 1);
	}
	return (ant_nb);
}

static void		get_nodes(t_anthill *anthill)
{
	(void)anthill;
}

t_anthill		*fill_anthill(void)
{
	t_anthill	*anthill;

	if (!(anthill = ft_memalloc(sizeof(t_anthill))))
		ft_exit("Insufficient memory.", 1, 1);
	anthill->ant_nb = get_ant_nb();
	get_nodes(anthill);
	return (anthill);
}

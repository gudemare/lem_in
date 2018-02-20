/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 20:46:43 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/20 21:26:48 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		get_ant_nb(t_anthill *anthill)
{
	char	*str;
	int		i;

	if (get_next_line(0, &str, 64) != 1)
		ft_exit("Cannot read input.", 1, 1);
	while (ft_is_whitespace(*str))
		str++;
	i = 1;
	if (!*str || (*str != '+' && !ft_isdigit(*str)))
		ft_exit("Bad ant number formating.", 0, 1);
	while (str[i])
		if (!ft_isdigit(str[i++]))
			ft_exit("Bad ant number formating.", 0, 1);
	if ((anthill->ant_nb = ft_atoi(str)) <= 0)
		ft_exit("Bad ant number.", 0, 1);
	if (!(anthill->entry_file = ft_strjoin(str, "\n")))
		ft_exit("Insufficient memory.", 1, 1);
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
	get_ant_nb(anthill);
	get_nodes(anthill);
	return (anthill);
}

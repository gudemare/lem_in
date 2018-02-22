/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 18:54:12 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/22 19:45:00 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		disp_moves(int last_ant, int last_ant_pos, char **path)
{
	int		pos;

	ft_printf("L%d-%s", last_ant, path[last_ant_pos]);
	pos = 1;
	while (last_ant - pos > 0 && path[last_ant_pos + pos])
	{
		ft_printf(" L%d-%s", last_ant - pos, path[last_ant_pos + pos]);
		pos++;
	}
	ft_putchar('\n');
}

void			display_path(char **path, int path_len, int ant_nb)
{
	int	last_ant;
	int	last_ant_pos;

	last_ant = 1;
	last_ant_pos = 1;
	while (last_ant_pos < path_len)
	{
		disp_moves(last_ant, last_ant_pos, path);
		if (last_ant == ant_nb)
			last_ant_pos++;
		else
			last_ant++;
	}
}

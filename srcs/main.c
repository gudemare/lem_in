/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:41:28 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/21 00:05:09 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Properly freeing the whole graph will be a bit of a bitch.
** It's lists in struts in lists, after all.
*/

static void	empty_anthill(t_anthill *anthill)
{
	(void)anthill;
}

int			main(void)
{
	t_anthill	*anthill;

	anthill = fill_anthill();
	ft_putendl(anthill->entry_file);
	ft_putendl("Here comes the resolution.");
	empty_anthill(anthill);
	return (0);
}

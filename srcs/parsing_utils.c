/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:18:41 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/22 20:16:34 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** get_line_type() makes simples checks to divide between categories.
** Incorrect lines CAN be returned as e_NODE or e_LINK, but complete checking
** shall be done in link or node-adding function.
*/

int		get_line_type(char *str)
{
	if (!*str)
		return (e_INCORRECT);
	if (*str == '#')
		return ((str[1] == '#') ? e_COMMAND : e_COMMENT);
	if (ft_strchr_count(str, ' ') == 2)
		return (e_NODE);
	if (ft_strchr(str, '-'))
		return (e_LINK);
	return (e_INCORRECT);
}

int		get_command(char *str, int last_command)
{
	if (ft_strequ(str, "##start"))
	{
		if (last_command == e_END || last_command == e_BOTH)
			return (e_BOTH);
		return (e_START);
	}
	if (ft_strequ(str, "##end"))
	{
		if (last_command == e_START || last_command == e_BOTH)
			return (e_BOTH);
		return (e_END);
	}
	return (e_OTHER);
}

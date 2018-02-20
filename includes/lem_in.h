/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 04:52:57 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/20 21:31:23 by gudemare         ###   ########.fr       */
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

t_anthill			*fill_anthill(void);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 04:52:57 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/20 20:53:37 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef struct		s_anthill
{
	t_list			nodes;
	int				ant_nb;
	int				start_node;
	int				end_node;
}					t_anthill;

typedef struct		s_node
{
	char			*node;
	t_list			*links;
}					t_node;

t_anthill			*fill_anthill(void);

#endif

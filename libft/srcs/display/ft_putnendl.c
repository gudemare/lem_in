/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnendl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:25:48 by gudemare          #+#    #+#             */
/*   Updated: 2017/07/11 10:59:10 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnendl(char const *s, size_t n)
{
	write(1, s, ft_min(ft_strlen(s), n));
	write(1, "\n", 1);
}

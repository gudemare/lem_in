/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudemare <gudemare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 21:51:57 by gudemare          #+#    #+#             */
/*   Updated: 2018/02/22 22:20:26 by gudemare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*dst;

	if (!(dst = malloc(sizeof(char) * size)))
		return (NULL);
	while (size > 0)
		*((unsigned char *)dst + size--) = 0;
	*(unsigned char *)dst = 0;
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:24:40 by pclement          #+#    #+#             */
/*   Updated: 2017/11/15 15:24:43 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*allocated_mem;
	size_t	i;

	if (!(allocated_mem = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		((unsigned char *)allocated_mem)[i] = 0;
		i++;
	}
	return (allocated_mem);
}

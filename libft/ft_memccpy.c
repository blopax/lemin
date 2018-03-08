/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:26:46 by pclement          #+#    #+#             */
/*   Updated: 2017/11/13 14:38:48 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dst_char;
	char	*src_char;

	i = 0;
	dst_char = (char *)dst;
	src_char = (void *)src;
	while (i < n)
	{
		dst_char[i] = src_char[i];
		if (src_char[i] == (char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}

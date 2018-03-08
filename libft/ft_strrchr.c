/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:56:47 by pclement          #+#    #+#             */
/*   Updated: 2017/11/13 18:56:48 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	char		c_ascii;
	const char	*dest;

	i = 0;
	dest = NULL;
	if (c < 0)
		c_ascii = 256 + c % 256;
	else
		c_ascii = c % 256;
	while (s[i] != '\0')
	{
		if (s[i] == c_ascii)
			dest = s + i;
		i++;
	}
	if (s[i] == c_ascii)
		dest = s + i;
	return ((char *)dest);
}

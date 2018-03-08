/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:55:34 by pclement          #+#    #+#             */
/*   Updated: 2017/11/13 19:04:20 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c_ascii;

	i = 0;
	if (c < 0)
		c_ascii = 256 + c % 256;
	else
		c_ascii = c % 256;
	while (s[i] != c_ascii && s[i] != '\0')
		i++;
	if (s[i] == c_ascii)
		return ((char *)(s + i));
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:34:02 by pclement          #+#    #+#             */
/*   Updated: 2017/11/16 14:31:44 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_blank(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static int		ft_fresh_str_len(char const *s)
{
	int	len;
	int	start;
	int	i;

	start = 0;
	len = 0;
	i = 0;
	while (ft_is_blank(s[start]))
		start++;
	while (s[start + len + i] != 0)
	{
		while (!(ft_is_blank(s[start + len])) && s[start + len + i] != 0)
			len++;
		if (ft_is_blank(s[start + len + i]))
		{
			while (ft_is_blank(s[start + len + i]) && s[start + len + i] != 0)
				i++;
			if (s[start + len + i] != 0)
			{
				len = len + i;
				i = 0;
			}
		}
	}
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*fresh_str;
	int		fresh_str_len;
	int		start;
	int		i;

	if (!s)
		return (NULL);
	start = 0;
	fresh_str_len = ft_fresh_str_len(s);
	i = 0;
	while (ft_is_blank(s[start]))
		start++;
	if (!(fresh_str = (char *)malloc(sizeof(char) * (fresh_str_len + 1))))
		return (NULL);
	while (i < fresh_str_len)
	{
		fresh_str[i] = ((char *)s)[start + i];
		i++;
	}
	fresh_str[i] = 0;
	return (fresh_str);
}

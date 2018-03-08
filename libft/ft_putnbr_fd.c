/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:19:22 by pclement          #+#    #+#             */
/*   Updated: 2017/11/15 19:30:18 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	result;
	char	c;

	result = (long)n;
	if (result < 0)
	{
		write(fd, "-", 1);
		result = -result;
	}
	if (result / 10 > 0)
		ft_putnbr_fd(result / 10, fd);
	c = result % 10 + 48;
	write(fd, &c, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:07:43 by pclement          #+#    #+#             */
/*   Updated: 2017/12/21 16:20:42 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		limits_check(unsigned long long result, int sign, int count)
{
	if ((result >= 9223372036854775807 || count > 19) && sign == 1)
		return (-1);
	else if ((result > 9223372036854775807 || count > 19) && sign == -1)
		return (0);
	else
		return (1);
}

static void		ft_init(int *i, unsigned long long *result, int *sign)
{
	*i = 0;
	*result = 0;
	*sign = 1;
}

int				ft_atoi(const char *str)
{
	int					i;
	int					start;
	unsigned long long	result;
	int					sign;

	if (!str)
		return (0);
	ft_init(&i, &result, &sign);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	start = i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
		if (limits_check(result, sign, i - start) != 1)
			return (limits_check(result, sign, i - start));
	}
	return (sign * result);
}

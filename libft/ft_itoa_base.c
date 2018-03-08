#include "libft.h"

static int			ft_neg(intmax_t value, int base_size)
{
	if (value < 0)
	{
		if (base_size == 10)
			return (2);
	}
	return (1);
}

/*
**Doesn't take into account sign if base different from 10
*/

static uintmax_t	ft_abs(intmax_t value)
{
	if (value < 0)
		return ((uintmax_t)(-value));
	return ((uintmax_t)value);
}

char				*ft_itoa_base(long value, char *base)
{
	char		*tab;
	int			tab_len;
	uintmax_t	result;
	int			neg;
	int			i;

	neg = ft_neg(value, ft_strlen(base));
	result = ft_abs(value);
	tab_len = neg;
	while ((result = result / ft_strlen(base)) >= 1)
		tab_len++;
	if (!(tab = ft_strnew(tab_len + 1)))
		return (0);
	result = ft_abs(value);
	i = 0;
	while (++i <= tab_len)
	{
		tab[tab_len - i] = base[result % ft_strlen(base)];
		result = result / ft_strlen(base);
	}
	if (neg == 2)
		tab[0] = '-';
	return (tab);
}

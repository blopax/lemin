#include "libft.h"

char	*ft_safe_free(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (str);
}

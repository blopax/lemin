/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclement <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:02:18 by pclement          #+#    #+#             */
/*   Updated: 2017/11/16 18:44:22 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*elt;
	t_list	*buf;

	elt = *alst;
	while (elt)
	{
		buf = elt->next;
		ft_lstdelone(&elt, del);
		elt = buf;
	}
	*alst = NULL;
}

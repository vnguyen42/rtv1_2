/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:11:41 by vnguyen           #+#    #+#             */
/*   Updated: 2016/03/14 17:16:15 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *res;
	t_list *appli;

	res = NULL;
	if (lst != NULL && f != NULL)
	{
		res = (*f)(lst);
		if (res == NULL)
			return (NULL);
		list = res;
		lst = lst->next;
		while (lst != NULL)
		{
			appli = (*f)(lst);
			if (appli == NULL)
				return (res);
			list->next = appli;
			list = appli;
			lst = list->next;
		}
	}
	return (res);
}

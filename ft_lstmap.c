/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitormar <aitormar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:17:46 by aitormar          #+#    #+#             */
/*   Updated: 2024/11/13 12:14:22 by aitormar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*res;
	t_list	*auxres;

	aux = lst;
	res = ft_calloc(sizeof(t_list), 1);
	if (!res)
		return (NULL);
	auxres = res;
	while (aux)
	{
		auxres->content = f(aux->content);
		auxres->next = ft_calloc(sizeof(t_list), 1);
		if (!auxres->next)
			ft_lstclear(&aux, del);
		aux = aux->content;
		auxres = auxres->next;
	}
	return (res);
}

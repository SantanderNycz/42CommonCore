/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:30:05 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/15 14:48:44 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_obj;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_obj = ft_lstnew(new_content);
		if (!new_obj)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_obj);
		lst = lst->next;
	}
	return (new_list);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
	t_list	*original = NULL;
	t_list	*mapped = NULL;

	ft_lstadd_back(&original, ft_lstnew(strdup("du")));
	ft_lstadd_back(&original, ft_lstnew(strdup("dudu")));
	ft_lstadd_back(&original, ft_lstnew(strdup("edu")));

	printf("Lista original:\n");
	print_list(original);

	mapped = ft_lstmap(original, dup_str, del_str);

	printf("\nLista mapeada:\n");
	print_list(mapped);

	ft_lstclear(&original, del_str);
	ft_lstclear(&mapped, del_str);

	return (0);
}
*/
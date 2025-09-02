/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:30:05 by lsantand          #+#    #+#             */
/*   Updated: 2025/05/05 21:50:46 by lsantand         ###   ########.fr       */
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void del(void *e)
{
	free(e);
}

void *upper(void *g)
{
	char *b = (char *)g;
	int i;
	
	i = 0;

	while (i <= 2)
	{
		b[i] = b[i] - 32;
		i++;
	}
	return(b);
}
int		main(void)
{
	t_list	*original = ft_lstnew(strdup("du"));
	t_list	*mapped = ft_lstmap(original, upper, del);
	
	
	// ft_lstadd_back(&original, ft_lstnew(strdup("du")));
	// ft_lstadd_back(&original, ft_lstnew(strdup("dudu")));
	// ft_lstadd_back(&original, ft_lstnew(strdup("edu")));

	printf("%s\n", (char *)original -> content);
	printf("%s\n", (char *)mapped -> content);

	ft_lstdelone(original, del);
	ft_lstdelone(mapped, del);

//	mapped = ft_lstmap(original, dup_str, del_str);

//	printf("\nLista mapeada:\n");
//	print_list(mapped);
	return (0);
}


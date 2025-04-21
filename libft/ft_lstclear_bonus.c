/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:29:46 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/15 14:04:43 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
t_list *a = malloc(sizeof(t_list));
	t_list *b = malloc(sizeof(t_list));
	t_list *c = malloc(sizeof(t_list));

	a->content = "Node A";
	b->content = "Node B";
	c->content = "Node C";

	a->next = b;
	b->next = c;
	c->next = NULL;

	printf("Antes do ft_lstclear:\n");
	printf("%p: %s\n", (void *)a, (char *)a->content);
	printf("%p: %s\n", (void *)b, (char *)b->content);
	printf("%p: %s\n", (void *)c, (char *)c->content);

	ft_lstclear(&a, free);

	// Após limpeza
	printf("\nDepois do ft_lstclear:\n");
	printf("a = %p\n", (void *)a);

	return (0);
}
*/
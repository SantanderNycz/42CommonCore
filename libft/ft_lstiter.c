/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:29:57 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/15 14:10:57 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
    void *duplicate(void *s)
    {
        return strdup((char *)s);
    }
    void del_content(void *s) { free(s); }
    t_list *mapped = ft_lstmap(head, duplicate, del_content);
    printf("ft_lstmap: ");
    print_list(mapped);

    ft_lstclear(&head, free);
    ft_lstclear(&mapped, free);

	return (0);
}
*/
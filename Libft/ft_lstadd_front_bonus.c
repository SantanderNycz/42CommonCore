/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:28:37 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/15 14:50:17 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
    t_list *head = ft_lstnew(strdup("Porto"));
    t_list *new_front = ft_lstnew(strdup("42"));
    ft_lstadd_front(&head, new_front);
    printf("ft_lstadd_front: ");
    print_list(head);
    
	return (0);
}
*/
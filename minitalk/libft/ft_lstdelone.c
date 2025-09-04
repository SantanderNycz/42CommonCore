/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:29:32 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/15 14:52:36 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
    t_list *to_delete = head->next; // "Porto"
    ft_lstdelone(to_delete, free);
    head->next = new_back;
    printf("ft_lstdelone: ");
    print_list(head);
    
	return (0);
}
*/
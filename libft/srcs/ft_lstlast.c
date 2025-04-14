/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:28:59 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/14 12:28:59 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list    *ft_lstlast(t_list *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
    {
        lst = lst->next;
    }
    return (lst);
}
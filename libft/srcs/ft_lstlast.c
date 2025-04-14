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
    t_list  temp;

    if (!lst)
        return (NULL);
    temp = lst;
    while (temp->next)
    {
        temp = temp->next;
    }
    return (temp);
}
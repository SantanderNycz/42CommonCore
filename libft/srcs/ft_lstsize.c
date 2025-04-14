/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:28:48 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/14 12:28:48 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     *ft_lstsize(t_list *lst)
{
    t_list  *temp;
    int     c;

    temp = lst;
    c = 0;
    while (temp)
    {    
        temp = temp->next;
        c++;
    }
    return (c);
}
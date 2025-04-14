/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:28:23 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/14 12:28:23 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
    
    t_list *element;

    element = malloc(sizeof(t_list));
    if (!element)
        return (NULL);
    element->content = content;
    element->next = NULL;
    return (element);
}
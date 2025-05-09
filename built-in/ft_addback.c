/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addback.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:27:38 by nikhtib           #+#    #+#             */
/*   Updated: 2025/05/08 18:20:06 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void    ft_addback(t_list **list, t_list *new)
{
    t_list *head;
    
    if(!list || !new)
        return;
    if(!*list)
    {
        *list = new;
        return;  
    }    
    head = *list;
    while (head->next)
        head = head->next;
    head->next = new;
}
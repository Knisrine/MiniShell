/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:45:07 by nikhtib           #+#    #+#             */
/*   Updated: 2025/05/02 20:17:31 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list  *ft_lstnew(char  *var, char *value, char *content, bool flag)
{
    t_list  *node;
    if(!value)
        value = "";
    node = malloc(sizeof (t_list));
    if(!node)
        return (NULL);
    node->content = content;
    node->var = var;
    node->value = value;
    node->flag = flag;
    node->next = NULL;
    return node;
}
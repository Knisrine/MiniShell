/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:19:09 by nikhtib           #+#    #+#             */
/*   Updated: 2025/05/04 14:45:36 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    new_env(t_var *v)
{
    // printls(v->list);
    int i;
    v->new_env = (char **) malloc (sizeof (char *) * (v->len_env + 1));
    if(!v->new_env)
        return;
    i = 0;
    while((i < v->len_env) && (v->list))
    {
        v->new_env[i] = v->list->content;
        // printf("-> %s\n",v->list->content);
        v->list = v->list->next;
        i++;
    }
    // i = 0;
    // while(v->new_env[i])
    // {
    //     printf("%s\n", v->new_env[i]);
    //     i++;
    // }
}

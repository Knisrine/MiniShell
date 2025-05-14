/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:28:54 by nikhtib           #+#    #+#             */
/*   Updated: 2025/05/14 18:57:25 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char    *get_var(char *s)
{
    int i;
    int j;
    char *dup;
    
    i = 0;
    j = 0;
    
    dup = ft_strdup(s);
    while(dup[i])
    {
        if(dup[i] == '=')
        {
            while (dup[i])
                dup[i] = '\0';
            break;
        }
        i++;
    }
    return (&dup[j]); 
}

void    printls(t_list *list)
{
    t_list *head;
    head = list;
    if(!list || !head)
    {
        
        return;
    }
    while (head)
    {
        printf("%s\n", head->content);
        head = head->next;
        
    }
}


void  make_list(t_var *v, char **env)
{
    int         i;
    static int  reminder;
    char        *var;
    char        *value;
    t_list      *new  = NULL;
    t_list      *head;
    v->list = NULL;
    head = v->list;
    i = 0;
    while(env[i])
    {
        value = ft_strdup(ft_strchr(env[i], '='));
        var = ft_strdup(get_var(env[i]));
        if(ft_strcmp(var, "PWD") == 0)
            v->pwd = ft_lstnew(ft_strdup(var) ,ft_strdup(value), ft_strdup(env[i]), 0);
        if(ft_strcmp(var, "OLDPWD") == 0)
            v->oldpwd = ft_lstnew(ft_strdup(var) ,ft_strdup(value), ft_strdup(env[i]), 0);
        new = ft_lstnew(ft_strdup(var) ,ft_strdup(value), ft_strdup(env[i]), 0);
        ft_addback(&v->list, new);
        free(value);
        free(var);
        i++;
    }
    if(reminder == 0)
    {
       ft_removelst(v, "OLDPWD");
       reminder++;
    }
    else if(reminder == 1)
        ft_addback(&v->list, v->oldpwd);
}

void    exp_var(t_var *v)
{
    t_list *head;

    head = v->list;
    if(!head)
        return;
    while(head)
    {
        if(head->flag == true)
            printf("%s\n", head->content);
        head = head->next;
    }
}

void    export(char **env, char **av, t_var *v)
{
	t_list   *head;
	t_list   *new;
    char *var;
	char *value;
	if(v->arc == 2)
	{
		exp_var(v);
		exit(0);
	}
	make_list(v, env);
	head = v->list;
	while (v->list)
	{
		if (ft_strcmp((v->list)->var, get_var(av[2])) == 0)
		{
			(v->list)->value = ft_strchr(av[2], '=');
			(v->list)->content = ft_strdup(av[2]);
			v->list = head;
			return;
		}
		v->list = (v->list)->next;
	}
	v->list = head;
	var = get_var(av[2]);
	value = ft_strchr(av[2], '=');
	new = ft_lstnew(ft_strdup(var), ft_strdup(value), ft_strdup(av[2]), 1);
	ft_addback(&v->list, new);
	v->list = head;
}
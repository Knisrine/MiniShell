/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:28:54 by nikhtib           #+#    #+#             */
/*   Updated: 2025/05/04 19:21:14 by nikhtib          ###   ########.fr       */
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
////////////////////
// int maerft(char *arg)
// {
// 	int	i;
// 	int	flag;
	
// 	i = 0;
// 	flag = 0;
// 	while(arg[i])
// 	{
// 		if(arg[i] == '=')
// 		{
// 			flag = 1;
// 			i++;
// 			break;
// 		}
// 		i++;	
// 	}
// 	if(flag == 1 && arg[i] != '\0')
// 		return (1);
// 	return (0);
// }	
///
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
t_list  *make_list(char **env)
{
    int i;
    char *var;
    char *value;
    t_list *new  = NULL;
    t_list *list = NULL;
    t_list *head;
    
    head = list;
    i = 0;
    while(env[i])
    {
        value = ft_strdup(ft_strchr(env[i], '='));
        var = ft_strdup(get_var(env[i]));
        new = ft_lstnew(ft_strdup(var) ,ft_strdup(value), ft_strdup(env[i]), 0);
        ft_addback(&list, new);
        free(value);
        free(var);
        i++;
    }
    return list;
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
	v->list = make_list(env);
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
    // if(maerft(av[2]) == 1)
	// ft_addback(&v->list, new);
    // else
	var = get_var(av[2]);
	value = ft_strchr(av[2], '=');
	new = ft_lstnew(ft_strdup(var), ft_strdup(value), ft_strdup(av[2]), 1);
	ft_addback(&v->list, new);
	v->list = head;
	// printls(v->list);
}
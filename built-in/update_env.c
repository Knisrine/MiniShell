/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:08:30 by nikhtib           #+#    #+#             */
/*   Updated: 2025/05/04 14:52:51 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(dest);
	dest[len + 1] = '=';
	while(src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	return (dest);
}

void	update_env(t_var *v, char *pwd, char *old_pwd)
{
	if(!v->list)
		return;
	t_list *head = NULL;
	char *s;
	
	head = v->list;
	while((v->list)->next)
	{
		if(ft_strcmp((v->list)->var, "PWD") == 0)
		{
			(v->list)->value = ft_strdup(pwd);
			s = ft_strcat((v->list)->var, pwd);
			(v->list)->content = ft_strdup(s);
		}
		if(ft_strcmp((v->list)->var, "OLDPWD") == 0)
			(v->list)->value = ft_strdup(old_pwd);
		(v->list) = (v->list)->next;
	}
	(v->list) = head;
}
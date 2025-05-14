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
	int		i;
	int		len;
	char	*s;

	len = ft_strlen(dest) + 1 + ft_strlen(src);
	s	= malloc(len + 1);
	if(!s)
		return 0;
	i	= 0;
	while(dest[i++])
		s[i] = dest[i];
	s[i] = '=';
	while(src[i++])
		s[i] = src[i];
	s[i] = '\0';
	return (s);
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
			// printf("pwd -> %s\n old_pwd -> %s\n", pwd,old_pwd);
			(v->list)->content = ft_strdup(s);
		}
		if(ft_strcmp((v->list)->var, "OLDPWD") == 0)
			(v->list)->value = ft_strdup(old_pwd);
		(v->list) = (v->list)->next;
	}
	(v->list) = head;
}
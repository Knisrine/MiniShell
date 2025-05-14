/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:49:44 by nikhtib           #+#    #+#             */
/*   Updated: 2025/05/14 13:26:07 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

static  void	*ft_memcpy(char *ds, char *sr, int n)
{
	int			i;

	if (ds == sr)
		return (ds);
	i = 0;
	while (i < n)
	{
		ds[i] = sr[i];
		i++;
	}
	return (ds);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char *s;
    int len;
    
    if(!s1)
        return (s2);
    if(!s2)
        return (s1);
    
    len = ft_strlen(s1) + ft_strlen(s2);
    s = malloc(len + 1);
    if(!s)
        return NULL;
    ft_memcpy(s,s1,ft_strlen(s1));
    ft_memcpy(s +  ft_strlen(s1),s2,ft_strlen(s2));
    return s;
}
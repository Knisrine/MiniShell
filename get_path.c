/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:29:08 by nikhtib           #+#    #+#             */
/*   Updated: 2025/05/14 18:53:48 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strstr(char *str, char *to_find)
{
	int len;
	int i;
	int k;
	len = ft_strlen(to_find);
	
	i = 0;
	k = 0;
	while (str[i])
	{
		while(str[i + k] == to_find[k])
		{		
			k++;
			if (k == len)
			{
				return (&str[i]);
			}
		}
		i++;
	}
	return NULL;
}

static char	*get_path(char **s, char *var)
{
	int		i;
	char	*str;
	
	str = NULL;
	i = 0;
	while (s[i])
	{
		if (ft_strstr(s[i], var))
		{
			str = ft_strdup(ft_strstr(s[i], var));
			break ;
		}
		i++;
	}
	return (str);
}

void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

char	*valid_path(char **env, char *cmmd, char *var)
{
	t_var	v;
	char	**path;
	char	*p;
	int		i;
	
	
	p = NULL;
	v.full_path = get_path(env, var);
	if (!v.full_path)
	{
		write(2, "PATH Not Found!\n", 17);
		exit(1);
	}
	path = ft_split(v.full_path, ':'); 
	free(v.full_path); 
	i = 0;
	while (path[i])
	{
		p = ft_strjoin(path[i], "/");
		p = ft_strjoin(p, cmmd);
		if (!access(p, X_OK))
			return (free_path(path), p);
		free(p);
		i++;
	}
	free_path(path);
	return (NULL); 
}

 
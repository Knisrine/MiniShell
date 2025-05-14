/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:37:06 by nikhtib           #+#    #+#             */
/*   Updated: 2025/05/14 15:15:09 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// char	*valid_path(char **env, char *cmmd, char *var)
// {
// 	t_var	v;
// 	char	**path;
// 	char	*p;
// 	int		i;
	
// 	p = NULL;
// 	v.full_path = get_path(env, var);
// 	if (!v.full_path)
// 	{
// 		write(2, "PATH Not Found!\n", 17);
// 		exit(1);
// 	}
// 	path = ft_split(v.full_path, ':');
// 	free(v.full_path);
// 	i = 0;
// 	while (path[i])
// 	{
// 		p = ft_strjoin(path[i], "/");
// 		p = ft_strjoin(p, cmmd);
// 		if (!access(p, X_OK))
// 			return (free_path(path), p);
// 		free(p);
// 		i++;
// 	}
// 	free_path(path);
// 	return (NULL); 
// }


void	env_function(t_var v, int ac)
{
	int	i;
	char *path_env;
	
	i = 0;
	if(ac > 2)
	{
		error_msg("env : with no options !\n");
		exit(0);
	}
	new_env(&v);
	path_env = valid_path(v.new_env, "env", "_=");
	
	// i = 0;
	// while (v.new_env[i])
	// { 
	// 	printf("%s\n", v.new_env[i]);
	// 	i++;
	// }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:35:34 by nikhtib           #+#    #+#             */
/*   Updated: 2025/05/08 20:57:55 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	
	i = 0;
	while (s1[i] || s2[i])
	{
		if( s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return 0;
}

int	is_builtin(char *cmmd)
{
	
    char *builtin[] = {"echo", "cd", "pwd", "env", "export", "unset", "exit"};
    int	i;
	
	i = 0;
    while (builtin[i])
    {
		
        if (ft_strcmp(cmmd, builtin[i]) == 0)
            return 1;
        i++;
    }
    return 0;
}

void	echo_function(char *s)
{
	while (*s)
	{
		write(1, &(*s), 1);
		s++;
	}
	exit(0);
}

void	exec_builtin(char *cmmd, char **av, char **env, t_var *v)
{
	char	*save_oldpwd;	
	char	*builtin[] = {"echo", "cd", "pwd", "env", "export", "unset", "exit"};
	char	cwd[PATH_MAX];
	
	v->list = make_list(env);
	if(ft_strcmp(builtin[0], cmmd) == 0 && ft_strcmp(av[2], "-n") == 0)
		echo_function(av[3]);
	else if(ft_strcmp(builtin[0], cmmd) == 0)
		echo_function(av[2]);
	else if(ft_strcmp(builtin[1], cmmd) == 0)
	{
		getcwd(cwd, sizeof(cwd));
		save_oldpwd = ft_strdup(cwd);
		if(chdir(av[2]) == 0)
		{
			getcwd(cwd, sizeof(cwd));
			update_env(v, cwd, save_oldpwd);
			free(save_oldpwd);
			return;
		}
		else
		printf("chdir failed !!");
	}
	else if(ft_strcmp(builtin[2], cmmd) == 0)
	{
		getcwd(cwd, sizeof(cwd));
		printf("%s",cwd);
		exit(0);
	}
	else if(ft_strcmp(builtin[3], cmmd) == 0)
		env_function(env, v->arc);
	else if(ft_strcmp(builtin[4], cmmd) == 0)
		export(env, av, v);
	else if(ft_strcmp(builtin[5], cmmd) == 0)
		unset(av, v);
		// exit(0);
	// else if(ft_strcmp(builtin[6], cmmd) == 0)
}
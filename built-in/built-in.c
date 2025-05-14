/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:35:34 by nikhtib           #+#    #+#             */
/*   Updated: 2025/05/14 18:52:10 by nikhtib          ###   ########.fr       */
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

int	only_n(char *s)
{
	int	i;
	i = 0;
	while (s[i])
	{
		if(s[i] != 'n')
			return (1);
		i++;
	}
	return 0;
}

int	echo_option(char *option)
{
	if((option[0] == '-') && only_n(option + 1))
		return (1);
	return (0);
}

void	exec_builtin(char *cmmd, char **av, char **env, t_var *v)
{
	char	*save_oldpwd;	
	char	*builtin[] = {"echo", "cd", "pwd", "env", "export", "unset", "exit"};
	char	cwd[PATH_MAX];
	int	i;

	make_list(v, env);
	if(ft_strcmp(builtin[0], cmmd) == 0)
	{
		if(echo_option(av[2]) == 1)
			printf("%s\n",av[3]);
		else if (echo_option(av[2]) == 1)
		{
			i = 2;
			while (i < v->arc)
			{
				printf("%s\n", av[i]);
				i++;
			}
		}
		else
			printf("%s\n", av[2]);
	}
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
		{
			free(save_oldpwd);
			printf("chdir failed !!");
		}
	}
	else if(ft_strcmp(builtin[2], cmmd) == 0)
	{
		getcwd(cwd, sizeof(cwd));
		printf("%s",cwd);
		exit(0);
	}
	else if(ft_strcmp(builtin[3], cmmd) == 0)
		env_function(*v, v->arc);
	else if(ft_strcmp(builtin[4], cmmd) == 0)
		export(env, av, v);
	else if(ft_strcmp(builtin[5], cmmd) == 0)
		unset(av, v);
}
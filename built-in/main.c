/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:14:08 by nikhtib           #+#    #+#             */
/*   Updated: 2025/05/08 20:02:58 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int main(int ac, char **av, char **env)
{
    char	*cmmd;
    int		id;
    // char	*input;
	t_var	v;
	// if(ac == 1)
	// 	return 0;
	v.len_env = len_env(env);
	v.arc = ac;	
    cmmd = av[1]; 
	// while (1)
	// {
	// 	input = readline("minishell> ");
	// 	// readline();
		// if (is_builtin(cmmd))
		// {
		// 	exec_builtin(cmmd, av, env, &v);
		// 	new_env(&v);
		// }
		// else
		// {	
			id = fork();
			if(id == 0)
			{
				////command
				// if(access(cmmd,X_OK))
				// 	error_msg("command not found !");
				char *path = "/bin/ls";
				execve(path, av[1], env);
				error_msg("execve failed !");
				}
		// }
	// wait(&id);
	// printf("pwd -->%s\n", env[13]);
	// else
	// {
	// 	id = fork();
	// 	if(id == 0)
	// 	{
	// 		//get path
	// 		execve(path, cmmd, env);
	// 		perror("execve :");
	// 		exit(1);
	// 	}
	// }
	}
	// built-in
	// commndes
	// pipes
	// hrdc
/*

	  |
   /    \
  |     cmnd3
  / \    
 */
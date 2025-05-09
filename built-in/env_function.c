/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:37:06 by nikhtib           #+#    #+#             */
/*   Updated: 2025/05/07 12:51:39 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env_function(char **s, int ac)
{
	int	i;

	i = 0;
	if(ac > 2)
	{
		error_msg("env : with no options !\n");
		exit(0);
	}
	while (s[i])
	{
		printf("%s\n", s[i]);
		i++;
	}
	
}

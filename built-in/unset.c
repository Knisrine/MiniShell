/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtib <nikhtib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:09:48 by nikhtib           #+#    #+#             */
/*   Updated: 2025/05/06 23:20:44 by nikhtib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_removelst(t_var *v, char *s)
{
  if(!s)
    return;
  t_list *head;
  t_list *current;

  head = v->list;
  current = v->list;
  if(ft_strcmp(current->var, get_var(s)) == 0)
  {
	head = current->next;
	free(current);
	return;
  }
  while (head->next)
  {
	current = head->next;
    if(ft_strcmp(current->var, s) == 0)
	{
		head->next = current->next;
		free (current);
		head = v->list;	
	}
	else
	head = head->next;
  }
    
}
void    unset(char **av, t_var *v)
{
	if(v->arc != 3)
	{
		error_msg("unset: not enough arguments\n");
		exit(1);
	}
    if(!v->list)
      return;
    ft_removelst(v, av[2]);
}
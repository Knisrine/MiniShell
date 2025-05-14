#ifndef MINISHELL_H
#define MINISHELL_H
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <readline/history.h>
#include <readline/readline.h>

typedef struct t_list 
{
	char			*content;
	char			*var;
	char			*value;
	bool			flag;
	struct t_list	*next;
}	t_list;

typedef struct t_variables
{
	t_list	*list;
	t_list	*oldpwd;
	t_list	*pwd;
	char	*full_path;
	char	**new_env;
	int		len_env;
	int		arc;
}	t_var;

typedef struct s_data
{
	char	**result;
	int		i;
	int		j;
	int		start;
	int		word_count;
	char	*tmp;
} t_data;

t_list  *ft_lstnew(char  *var, char *value, char *content, bool flag);
void	exec_builtin(char *cmmd, char **av, char **env, t_var *v);
void	update_env(t_var *v, char *pwd, char *old_pwd);
void    export(char **env, char **av, t_var *v);
void    ft_addback(t_list **list, t_list *new);
int		ft_strncmp(char *s1, char *s2, int n);
char	**ft_split(char const *s, char c);
void	ft_removelst(t_var *v, char *s);
void	env_function(t_var v, int ac);
int		ft_strcmp(char *s1, char *s2);
void    unset(char **av, t_var *v);
char	*ft_strchr(char *s, int c);
int		is_builtin(char *cmmd);
void  	make_list(t_var *v, char **env);
char	*ft_strdup(char *s1);
int		ft_strlen(char *str);
void    error_msg(char *msg);
int     len_env(char **env);
char    *get_var(char *s);
void    new_env(t_var *v);
void	ft_removelst(t_var *v, char *s);
char	*valid_path(char **env, char *cmmd, char *var);
char    *ft_strjoin(char *s1, char *s2);
///
void    printls(t_list *list);
#endif
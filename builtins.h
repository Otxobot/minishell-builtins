#ifndef	BUILTINS_H
# define BUILTINS_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define	ERROR 1
#define	SUCCESS 0
#define BUFFER_SIZE 4096

typedef struct	s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}				t_env;


t_env	*get_env(char **envp, t_env *env);
char		*get_env_name(char *dest, const char *src);
void     cd(char **args, t_env *env);
int		echo(char **args);
void	pwd(char **cmd);
t_env  *make_node(void);
void    print_nodes(t_env   *env);
t_list *ft_lstlast(t_list *lst);
void    ft_lstadd_back(t_env *lst, t_env *new);
int		ft_strcmp(const char *s1, const char *s2);
char     *search_for_var(t_env *env, char *search);
int    home_case(t_env *env);
int    slash_case(t_env *env);
int    go_back(t_env   *env);
int     absolute_path(t_env *env, char *absolute_path);
int    do_whatever(t_env *env);

#endif

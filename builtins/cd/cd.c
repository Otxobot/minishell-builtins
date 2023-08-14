#include "../../builtins.h"

//void	cd(char **str, t_env *env);
//void	getenv1(char	**envp, t_env *env);
//t_env  *make_node(void);

// int main(int ac, char **av, char **envp)
// {
// 	t_env	*env;

// 	//char *s[] ={"ls", "-l",  NULL};
// 	// int n = 0;
// 	env = make_node();
// 	getenv1(envp, env);
// 	cd(av, env);
// 	//getenv(envp, env);
// 	// if (execve("/bin/ls",s , envp) == -1)
// 	// 	printf("fallo\n");
// }

void	cd(char **str, t_env *env)
{
	if (!str[1])
	{
		//printf("%s\n", getcwd(str[1], sizeof(str)));
		chdir("/Users/abasante");
		//printf("%s\n", getcwd(str[1], sizeof(str)));
	}
}

t_env  *make_node(void)
{
    t_env *new;

    new = malloc(sizeof(t_env));
    if (new == NULL)
        return (NULL);
    new->name = NULL;
    new->value = NULL;
	new->next = NULL;
    return (new);
}

t_list *ft_lstlast(t_list *lst)
{
    if (lst == NULL)
        return (NULL);
    while (lst->next != NULL)
    {
        lst = lst->next;
    }
    return (lst);
}

void    ft_lstadd_back(t_env *lst, t_env *new)
{
    while (lst != NULL)
    {
        lst = lst->next;
    }
    lst = new;
}

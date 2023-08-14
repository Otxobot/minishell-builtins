#include "../../builtins.h"

void    get_env_name(char **envp, t_env *env)
{
    t_env   *tmp;
    int i = 0;

    env = make_node();
    tmp = env;
    while (envp[i] != NULL)
    {
        tmp->name = ft_substr(envp[i], 0, ft_strchr(envp[i], '=') - envp[i]);
        tmp->value = ft_substr(envp[i], ft_strchr(envp[i], '=') - envp[i] + 1,
            ft_strlen(envp[i]));
        if (envp[++i])
        {
            ft_lstadd_back(env, tmp);
            tmp->next = make_node();
            tmp = tmp->next;    
        }
    }
    print_nodes(env);
}

void    print_nodes(t_env   *env)
{
    t_env   *tmp;

    tmp = env;
    while (tmp)
    {
        printf("%s=%s\n", tmp->name, tmp->value);
        tmp = tmp->next;
    }
}

int main(int ac, char **av, char **envp)
{
    t_env   *env;

    get_env_name(envp, env);
}

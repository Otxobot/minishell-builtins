#include "../../builtins.h"

void    get_env(char **envp, t_env *env)
{
    t_env   *tmp;
    int i = 0;

    env = make_node();
    tmp = env;
    while (envp[i] != NULL)
    {
        tmp->name = ft_substr(envp[i], 0, ft_strchr(envp[i], '=') - envp[i]);
        //printf("%s\n", tmp->name);
        printf("%d\n", i);
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
        printf("tmp->name:%s\n", tmp->name);
        tmp = tmp->next;
    }
}

// int     ft_strlen(char *str)
// {
//     int i = 0;

//     while (str[i])
//     {
//         i++;
//     }
//     return (i);
// }

// size_t      ft_strlcpy(char *dst, const char *src, size_t len)
// {
//     size_t  i;
//     char    *pt_src;

//     pt_src = (char *)src;
//     i = 0;
//     if (len > 0)
//     {
//         while (pt_src[i] && i < len - 1)
//         {
//             dst[i] = pt_src[i];
//             i++;
//         }
//         dst[i] = '\0';
//     }
//     while (src[i])
//         i++;
//     return (i);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*strsub;

// 	if (len > (size_t)ft_strlen(s))
// 	{
// 		len = ft_strlen(s);
// 	}
// 	strsub = (char *)malloc(len + 1);
// 	if (start > (unsigned int)ft_strlen(s))
// 	{
// 		*strsub = '\0';
// 		return (strsub);
// 	}
// 	if (!strsub)
// 	{
// 		return (0);
// 	}
// 	ft_strlcpy(strsub, &s[start], len + 1);
// 	return (strsub);
// }

int main(int ac, char **av, char **envp)
{
    t_env   *env;

    get_env(envp, env);
}

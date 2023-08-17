#include "../../builtins.h"

char		*get_env_name(char *dest, const char *src)
{
	int		i;

	i = 0;
	while (src[i] && src[i] != '=' && ft_strlen(src) < BUFFER_SIZE)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int   ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

int     update_oldpwd(t_env *env)
{
    char    cwd[10000];
    t_env   *tmp;
    char    *oldpwd;
    char    *name;

    name = "OLDPWD";
    tmp = env;
    if (getcwd(cwd, sizeof(cwd)) == NULL)
        return (ERROR);
    oldpwd = ft_strjoin("OLDPWD=", cwd);
    while (tmp)
    {
        if (ft_strcmp(tmp->name, name) == 0)
        {
            tmp->value = cwd;
        }
        tmp = tmp->next;  
    }
    return (SUCCESS);
}

void	cd(char **args, t_env *env)
{

    if (!args[1])
    {
        //in this case we have to go to the home directory since the input was only "cd"
        update_oldpwd(env);
    }
}

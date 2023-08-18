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

char     *search_for_home(t_env *env)
{
    t_env *tmp;
    char    *home;
    char    *ret_path;

    home = "HOME";
    tmp = env;
    while (tmp)
    {
        if (ft_strcmp(tmp->name, home) == 0)
        {
            ret_path = tmp->value;
        }
        tmp = tmp->next;
    }
    return (ret_path);
}

int     cd(char **args, t_env *env)
{
    if (!args[1])
    {
        char *home_path;
        //in this case we have to go to the home directory since the input was only "cd"
        //before we do anything, we change the OLDPWD= variable in the environment to the current working directory before changing it, 
        //which is what this command does.
        update_oldpwd(env);
        //now i have to find a way to change to the home directory
        //search_for_home, returns the path in the HOME variable in the environment.
        home_path = search_for_home(env);
        if (chdir(home_path) == 0)
        {
            ft_putstr_fd("Path changed successfully!\n", 1);
            return (SUCCESS);
        }
        else
        {
            ft_putstr_fd("cd: ", 1);
            if (access(home_path, F_OK) == -1)
                ft_putstr_fd("no such file or directory: ", 1);
            else if (access(home_path, R_OK) == -1)
                ft_putstr_fd("permission denied: ", 1);
            ft_putstr_fd("Chdir failed\n", 1);
            return(ERROR);
        }
    }
}

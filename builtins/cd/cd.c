#include "../../builtins.h"

int     update_oldpwd(t_env *env, char *oldpwd)
{
    char    cwd[10000];
    t_env   *tmp;
    char    *name;

    name = "OLDPWD";
    tmp = env;
    while (tmp)
    {
        if (ft_strcmp(tmp->name, name) == 0)
        {
            tmp->value = oldpwd;
        }
        tmp = tmp->next;
    }
    return (SUCCESS);
}

char     *search_for_var(t_env *env, char  *search)
{
    t_env *tmp;
    char    *ret_path;

    tmp = env;
    while (tmp)
    {
        if (ft_strcmp(tmp->name, search) == 0)
        {
            ret_path = tmp->value;
        }
        tmp = tmp->next;
    }
    return (ret_path);
}

int    home_case(t_env *env)
{
    char *home_path;
    char *home;
    char cwd[10000];

    home = "HOME";

    home_path = search_for_var(env, home);
    getcwd(cwd, sizeof(cwd));
    if (chdir(home_path) == 0)
    {
        update_oldpwd(env, cwd);
        ft_putstr_fd("Path changed successfully!\n", 1);
        return (SUCCESS);
    }
    else
    {
        ft_putstr_fd("cd: HOME not set", 1);
        return(ERROR);
    }
}

int    slash_case(t_env *env)
{
    char    *root_path;
    char    cwd[10000];

    getcwd(cwd, sizeof(cwd));
    if (chdir("/") == 0)
    {
        update_oldpwd(env, cwd);
        ft_putstr_fd("Path changed succesfully!\n", 1);
        return (SUCCESS);
    }
    else
    {

        if (access("/", F_OK) == -1)
            ft_putstr_fd("no such file or directory: ", 1);
        else if (access("/", R_OK) == -1)
            ft_putstr_fd("permission denied: ", 1);
        ft_putstr_fd("Chdir failed\n", 1);
        return(ERROR);
    }
}

//now i have to find a way to change to the home directory
//search_for_home, returns the path in the HOME variable in the environment.
//in this case we have to go to the home directory since the input was only "cd"
//before we do anything, we change the OLDPWD= variable in the environment to the current working directory before changing it, 
//which is what this command does.
void     cd(char **args, t_env *env)
{
    char    *s[] = {"ls", "-l", NULL};

    if (!args[1])
        home_case(env);
    else if (args[1][0] == '/')
        slash_case(env);
    execve("/bin/ls", s, NULL);
    
}

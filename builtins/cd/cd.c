#include "../../builtins.h"
#include <unistd.h>

void	cd(char **str, t_env *env);
void	getenv1(char	**envp, t_env *env);
t_env  *make_node(void);

int main(int ac, char **av, char **envp)
{
	t_env	*env;

	//char *s[] ={"ls", "-l",  NULL};
	int n = 0;
	while (envp[n])
	{
		printf("%s\n", envp[n++]);
	}
	getenv1(envp, env);
	cd(av, env);
	//getenv(envp, env);
	// if (execve("/bin/ls",s , envp) == -1)
	// 	printf("fallo\n");
}

void	cd(char **str, t_env *env)
{
	if (!str[1])
	{
		//printf("%s\n", getcwd(str[1], sizeof(str)));
		chdir("/Users/abasante");
		//printf("%s\n", getcwd(str[1], sizeof(str)));
	}
}

void	getenv1(char	**envp, t_env *env)
{
	int 	line;
	int		letter;

	line = 0;
	letter = 0;
	while (envp[line])
	{
		printf("%s\n", envp[line++]);
	}
	line = 0;
	env = make_node();
	while (envp[line])
	{
	// 	printf("line: %d\n", line);
	// 	printf("%ld\n", ft_strchr(envp[line], '=') - envp[line]);
	// 	printf("%s\n",ft_substr(envp[line], 0, ft_strchr(envp[line], '=') - envp[line]));
		env->name = ft_substr(envp[line], 0, ft_strchr(envp[line], '=') - envp[line]);
		line++;
		if (envp[line] != NULL)
		{
			env = make_node();
		}
	}
	printnode();
}

void	printnode(t_env	*env)
{
	
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

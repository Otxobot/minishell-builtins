#include "../builtins.h"

int main(int ac, char **av, char **envp)
{
    t_env   *env;

	//we get and print the environmen
    env = get_env(envp, env);
	printf("before:\n");
    print_nodes(env);

	//trying to change the directory with cd
	cd(av, env);
	printf("------------------------------\n");
	printf("after:\n");
	print_nodes(env);
}

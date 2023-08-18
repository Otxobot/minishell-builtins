#include "../builtins.h"

int main(int ac, char **av, char **envp)
{
    t_env   *env;

	//we get and print the environmen
    env = get_env(envp, env);

	//trying to change the directory with cd
	cd(av, env);
	print_nodes(env);
}

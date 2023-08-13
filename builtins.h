#ifndef	BUILTINS_H
# define BUILTINS_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define	ERROR 1
#define	SUCCESS 0

typedef struct	s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}				t_env;


void	getenv1(char	**envp, t_env *env);
void	cd(char **str, t_env *env);
t_env  *make_node(void);

#endif
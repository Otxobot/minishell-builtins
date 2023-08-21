#include "../builtins.h"

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

int   ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

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

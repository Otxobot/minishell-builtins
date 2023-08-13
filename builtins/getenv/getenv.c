#include "../../builtins.h"

void    get_env(char **envp, t_env *env)
{
    int line = 0;

    while (envp[line] != NULL)
    {
        env->name = ft_substr(envp[line], 0, ft_strchr(envp[line], '=') - envp[line]);
        line++;
    }
}

int     ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
    {
        i++;
    }
    return (i);
}

size_t      ft_strlcpy(char *dst, const char *src, size_t len)
{
    size_t  i;
    char    *pt_src;

    pt_src = (char *)src;
    i = 0;
    if (len > 0)
    {
        while (pt_src[i] != NULL && i < len - 1)
        {
            dst[i] = pt_src[i];
            i++;
        }
        dst[i] = '\0';
    }
    while (src[i])
        i++;
    return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*strsub;

	if (len > (size_t)ft_strlen(s))
	{
		len = ft_strlen(s);
	}
	strsub = (char *)malloc(len + 1);
	if (start > (unsigned int)ft_strlen(s))
	{
		*strsub = '\0';
		return (strsub);
	}
	if (!strsub)
	{
		return (0);
	}
	ft_strlcpy(strsub, &s[start], len + 1);
	return (strsub);
}

int main(int ac, char **av, char **envp)
{
    t_env   *env;

    get_env(envp, env);
}

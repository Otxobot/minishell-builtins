//#include "header.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);

void		echo(char **args)
{
	int i;
	int n_flag;

	n_flag = 0;
	if (!args[0])
	{
		perror("\n");
		exit (1);
	}
	else if (args[0][0] == '-' && args[0][1] == 'n' && args[0][2] == '\0')
		n_flag = 1;
	i = -1;
	if (n_flag)
		i++;
	while (args[++i])
	{
		int pos;
		pos = 0;
		while (args[i][pos] != '\0')
		{
			write (1, &args[i][pos++], 1);
		}
		if (!args[i + 1] && !n_flag)
			write (1, "\n", 1);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}

int main(int ac, char **av)
{
	echo(av);
}
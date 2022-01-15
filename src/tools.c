#include <minitalk.h>

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		integer;

	i = 0;
	integer = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = (str[i] == 45 ? -1 : 1);
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			if ((unsigned long)integer * 10 > 9223372036854775807)
				return (sign == 1) ? -1 : 0;
			integer *= 10;
			integer += str[i] - 48;
		}
		else
			return (integer * sign);
		i++;
	}
	return (integer * sign);
}


void	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		exit(1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
		{
			ft_putchar_fd(s[i++], fd);
		}
	}
}

void	ft_putnbr(int n)
{
	int result;

	result = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		result = -((int)n);
	}
	else
		result = n;
	if (result < 10)
		ft_putchar_fd(result + 48, 1);
	else
	{
		ft_putnbr(result / 10);
		ft_putchar_fd((result % 10) + 48, 1);
	}
}

void	protected_kill(pid_t pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		ft_putstr_fd("fatal: kill failed\n", 2);
		exit(1);
	}
}

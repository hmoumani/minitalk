#include <minitalk.h>

void    handler(int sig)
{
    static char c;
    static int  i = 7;

    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    c |= (SIGUSR2 == sig) << i;
    i--;
    if (i == -1)
    {
        i = 7;
        ft_putchar_fd(c, 1);
        c = 0;
    }
}

int main()
{
    ft_putnbr(getpid());
    ft_putchar_fd('\n', 1);
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while (1)
        ;
}
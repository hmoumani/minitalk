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
        if (c == 0)
        {
            signal(SIGUSR1, receive_pid);
            signal(SIGUSR2, receive_pid);
            while (kill(pid, ACK) != -1)
                ;
            pid = 0;
            return ;
        }
        if (write(1, &c, 1) == -1)
        {
            protected_kill(pid, ACK);
            exit(1);
        }
        c = 0;
    }
    protected_kill(pid, ACK);
}

void    receive_pid(int sig)
{
    static int i = 31;

    signal(SIGUSR1, receive_pid);
    signal(SIGUSR2, receive_pid);
    pid |= (SIGUSR2 == sig) << i;
    i--;
    if (i == -1)
    {
        signal(SIGUSR1, handler);
        signal(SIGUSR2, handler);
        i = 31;
    }
}

int main()
{
    ft_putnbr(getpid());
    ft_putchar_fd('\n', 1);
    signal(SIGUSR1, receive_pid);
    signal(SIGUSR2, receive_pid);
    while (1);
}
#include <minitalk.h>

void    send_char(char c, pid_t pid)
{
    int i;

    i = 7;
    while (i >= 0)
    {
        if (c & (1 << i))
            protected_kill(pid, SIGUSR2);
        else
            protected_kill(pid, SIGUSR1);
        i--;
        usleep(150);
    }
}

void    send_string(char *text, pid_t pid)
{
    int i;

    i = 0;
    while (text[i])
    {
        send_char(text[i], pid);
        ++i;
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        ft_putstr_fd("Error: Arguments\n", 2);
        exit(1);
    }
    send_string(argv[2], ft_atoi(argv[1]));
    return (0);
}

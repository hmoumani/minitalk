#include <minitalk.h>

void    fatal(int sig)
{
    signal(ACK, fatal);
    signal(NACK, fatal);
    if (sig == ACK)
        return ;
    ft_putstr_fd("Fatal: server Error\n", 2);
    exit(1);
}

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
        // while (usleep(1000) != -1)
        //     ;
        usleep(10000);
        i--;
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
    send_char(0, pid);
}

void    send_client_pid(pid_t pid, pid_t server_pid)
{
    int i = 31;

    while (i >= 0)
    {
        if (pid & (1 << i))
            protected_kill(server_pid, SIGUSR2);
        else
            protected_kill(server_pid, SIGUSR1);
        i--;
        usleep(10000);
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        ft_putstr_fd("Error: Arguments\n", 2);
        exit(1);
    }
    signal(ACK, fatal);
    signal(NACK, fatal);
    send_client_pid(getpid(), ft_atoi(argv[1]));
    send_string(argv[2], ft_atoi(argv[1]));
    while (usleep(10000) != -1)
        ;
}

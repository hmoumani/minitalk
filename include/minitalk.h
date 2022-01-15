#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# define ACK SIGUSR1
# define NACK SIGUSR2

pid_t   pid;

void	ft_putnbr(int n);
int     ft_atoi(const char *str);
void    int_to_binary(int n);
void    receive_pid(int sig);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	protected_kill(pid_t pid, int sig);
#endif
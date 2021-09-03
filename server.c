#include <unistd.h>
#include "libft/libft.h"
#include <signal.h>

void	interpret(char *c)
{
	static char	*message;
	char		*to_print;

	if (!message)
	{
		message = ft_strdup(c);
		printf("%s\n", message);
	}
	else
		message = ft_strjoin(message, c);
	if (ft_strlen(message) == 8)
	{
		to_print = ft_itoa_base(ft_atoi(message), 10, "0123456789");
		printf("%s\n", to_print);
	}
}

void	handle_sigusr1(int sig)
{
	interpret("0");
}

void	handle_sigusr2(int sig)
{
	interpret("1");
}

int	main(void)
{
	int					pid;
	struct sigaction	sa_1;
	struct sigaction	sa_2;

	pid = getpid();
	if (pid < 0)
		return (-1);
	ft_putnbr_fd(pid, 0);
	ft_putchar_fd('\n', 0);
	sa_1.sa_handler = &handle_sigusr1;
	sa_2.sa_handler = &handle_sigusr2;
	while ("The prophecy is true")
	{
		sigaction(SIGUSR1, &sa_1, NULL);
		sigaction(SIGUSR2, &sa_2, NULL);
	}
}

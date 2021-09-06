#include <unistd.h>
#include "libft/libft.h"
#include <signal.h>

void	display_binary_to_dec(int binary)
{
	int	decimal;
	int	base;
	int	remainder;

	base = 1;
	decimal = 0;
	remainder = 0;
	while (binary)
	{
		remainder = binary % 10;
		binary /= 10;
		decimal += remainder * base;
		base *= 2;
	}
	ft_putchar_fd(decimal, 1);
}

void	interpret(char *c)
{
	static char	*message;
	char		*to_print;

	if (!message)
		message = ft_strdup(c);
	else
		message = ft_strjoin(message, c);
	if (ft_strlen(message) == 7)
	{
		display_binary_to_dec(ft_atoi(message));
		free(message);
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

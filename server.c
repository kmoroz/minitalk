#include <unistd.h>
#include "libft/libft.h"
#include <signal.h>
#include "server.h"

void	handle_sigusr1(int sig)
{
	printf("first signal\n");
}

void	handle_sigusr2(int sig)
{
	printf("second signal\n");
}

int	main(void)
{
	int			pid;
	t_sigaction	sa;

	pid = getpid();
	if (pid < 0)
		return (-1);
	ft_putnbr_fd(pid, 0);
	ft_putchar_fd('\n', 0);
	while ("The prophecy is true")
	{
		sa.handler_usr1 = &handle_sigusr1;
		sa.handler_usr2 = &handle_sigusr2;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
}

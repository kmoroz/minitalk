#include <unistd.h>
#include "libft/libft.h"

int	main(void)
{
	int	pid;

	pid = getpid();
	if (pid < 0)
		return (-1);
	ft_putnbr_fd(pid, 0);
	ft_putchar_fd('\n', 0);
}

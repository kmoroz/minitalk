/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 12:15:03 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/10/11 16:51:30 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>

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

void	interpret(char c)
{
	static char	message[8];
	static int	i;

	if (!message)
		ft_bzero(message, 8);
	message[i] = c;
	i++;
	if (i == 8)
	{
		display_binary_to_dec(ft_atoi(message));
		i = 0;
		ft_bzero(message, 8);
	}
}

void	handle_sigusr1(void)
{
	interpret('0');
}

void	handle_sigusr2(void)
{
	interpret('1');
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

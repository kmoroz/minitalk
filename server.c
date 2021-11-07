/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 12:15:03 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/11/07 14:59:12 by ksmorozo      ########   odam.nl         */
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

void	interpret(int signal)
{
	static char	message[8];
	static int	i;

	if (signal == SIGUSR1)
		message[i] = '0';
	else
		message[i] = '1';
	i++;
	if (i == 8)
	{
		display_binary_to_dec(ft_atoi(message));
		i = 0;
		ft_bzero(message, 8);
	}
}

int	main(void)
{
	int					pid;

	pid = getpid();
	if (pid < 0)
		return (-1);
	ft_putnbr_fd(pid, 0);
	ft_putchar_fd('\n', 0);
	signal(SIGUSR1, interpret);
	signal(SIGUSR2, interpret);
	while ("The prophecy is true")
	{
		usleep(300);
	}
}

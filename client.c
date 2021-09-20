/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 12:14:31 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/20 14:48:31 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

char	*convert_to_binary(unsigned char c)
{
	char	*conversion;
	char	*result;

	c = *(unsigned char *)&c;
	conversion = ft_itoa_base(c, 2, "01");
	if (ft_strlen(conversion) == 8)
		return (conversion);
	if (ft_strlen(conversion) == 7)
		result = ft_strjoin("0", conversion);
	if (ft_strlen(conversion) == 6)
		result = ft_strjoin("00", conversion);
	free (conversion);
	return (result);
}

void	send_signal(char *str, int pid)
{
	char	*temp;

	temp = str;
	while (*str)
	{
		if (*str == '0')
		{
			kill(pid, SIGUSR1);
			usleep(3000);
		}
		if (*str == '1')
		{
			kill(pid, SIGUSR2);
			usleep(3000);
		}
		str++;
	}
	free(temp);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		while (*message)
		{
			send_signal(convert_to_binary(*message), pid);
			message++;
		}
	}
}

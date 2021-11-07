/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 12:14:31 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/11/07 14:59:06 by ksmorozo      ########   odam.nl         */
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

	conversion = ft_itoa_base(c, 2, "01");
	if (ft_strlen(conversion) == 8)
		return (conversion);
	if (ft_strlen(conversion) == 7)
		result = ft_strjoin("0", conversion);
	if (ft_strlen(conversion) == 6)
		result = ft_strjoin("00", conversion);
	if (ft_strlen(conversion) == 5)
		result = ft_strjoin("000", conversion);
	if (ft_strlen(conversion) == 4)
		result = ft_strjoin("0000", conversion);
	if (ft_strlen(conversion) == 3)
		result = ft_strjoin("00000", conversion);
	if (ft_strlen(conversion) == 2)
		result = ft_strjoin("000000", conversion);
	if (ft_strlen(conversion) == 1)
		result = ft_strjoin("0000000", conversion);
	if (ft_strlen(conversion) == 0)
		result = ft_strjoin("00000000", conversion);
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
			kill(pid, SIGUSR1);
		else if (*str == '1')
			kill(pid, SIGUSR2);
		usleep(300);
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

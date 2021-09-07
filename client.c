#include "libft/libft.h"
#include <unistd.h>
#include <signal.h>

char	*convert_to_binary(char c)
{
	char	*result;

	result = ft_itoa_base(c, 2, "01");
	if (ft_strlen(result) < 7)
		result = ft_strjoin("0", result);
	return (result);
}

void	send_signal(char *str, int pid)
{
	char	*temp;

	//printf("%s\n", str);
	temp = str;
	while (*str)
	{
		if (*str == '0')
		{
			kill(pid, SIGUSR1);
			//printf("%c\n", *str);
			usleep(3000);
		}
		if (*str == '1')
		{
			kill(pid, SIGUSR2);
			//printf("%c\n", *str);
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
	int		count;

	count = 2;
	pid = ft_atoi(argv[1]);
	if (argc >= 2)
	{
		while (count <= argc - 1)
		{
			message = argv[count];
			//printf("%s\n", message);
			while (*message)
			{
				send_signal(convert_to_binary(*message), pid);
				message++;
			}
			count++;
		}
	}
}

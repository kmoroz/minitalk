#include "libft/libft.h"
#include <unistd.h>
#include <signal.h>

char	*convert_to_binary(unsigned char c)
{
	char	*result;

	c = *(unsigned char *)&c;
	result = ft_itoa_base(c, 2, "01");
	if (ft_strlen(result) == 7)
		result = ft_strjoin("0", result);
	if (ft_strlen(result) == 6)
		result = ft_strjoin("00", result);
	//("%s\n", result);
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
	if (argc == 3)
	{
		message = argv[2];
		//printf("%s\n", message);
		while (*message)
		{
			send_signal(convert_to_binary(*message), pid);
			message++;
		}
	}
}

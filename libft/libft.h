/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 11:43:49 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/20 11:41:44 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);
void			ft_putchar_fd(char c, int fd);
char			*ft_strdup(const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
char			*ft_itoa_base(long long int number, int base, char *digits_str);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_putnbr_fd(int n, int fd);

#endif

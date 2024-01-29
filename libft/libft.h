/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:02:23 by gdetourn          #+#    #+#             */
/*   Updated: 2024/01/02 13:48:29 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <strings.h>

char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);

/*ft_printf_sl*/
void	ft_putnbr_base(long int nbr, char *base, int *ret);
void	ft_putnbr_b_un(unsigned int nbr, char *base, int *ret);
void	ft_pnbr_p(unsigned long nbr, char *base, int *ret);
int		ft_check_type(va_list args, const char *format, int *ret);
int		ft_printf(const char *format, ...);

/*utils.c*/
void	ft_putchar(char c, int *ret);
void	ft_putstr(char *s, int *ret);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);

/*read_text.c*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dst, char *src, size_t size);
char	*ft_strjoin_and_free(char *s1, char *s2);
char	*ft_read_text_sl(int fd, char *stash);

#endif

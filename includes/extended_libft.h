/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_libft.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:31:05 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/27 19:43:36 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTENDED_LIBFR_H
# define EXTENDED_LIBFR_H

#include <libft.h>

// @brief same 'as ft_putchar_fd(c, 1);' but return 1
int		extended_ft_putchar(char c);

// @brief free s1 and s2
char	*extended_ft_strjoin(char *s1, char *s2);

char	*ft_itoa_ullong(unsigned long long nbr);
char	*ft_itoa_llong(long long nbr);

char	*ft_itoa_ulong(unsigned long nbr);
char	*ft_itoa_long(long nbr);

char	*ft_itoa_uint(unsigned int nbr);
char	*ft_itoa_int(int nbr);

char	*ft_itoa_ushort(unsigned short nbr);
char	*ft_itoa_short(short nbr);

char	*ft_itoa_uchar(unsigned char nbr);
char	*ft_itoa_char(char nbr);

#endif
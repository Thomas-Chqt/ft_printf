/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_libft.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:31:05 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/28 19:30:44 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTENDED_LIBFT_H
# define EXTENDED_LIBFT_H

# include <libft.h>

// @brief same 'as ft_putchar_fd(c, 1);' but return 1
int				extended_ft_putchar(char c);

// @brief free s1 and s2
char			*extended_ft_strjoin(char *s1, char *s2);

unsigned int	ft_atoi_uint(const char *str);

char			*ft_itoa_ullong(unsigned long long nbr);
char			*ft_itoa_llong(long long nbr);

char			*ft_itoa_ullong_base(unsigned long long nbr, char *base);

// int				ft_is_all(char *str, int (*f)(int));

#endif
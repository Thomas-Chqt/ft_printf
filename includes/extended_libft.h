/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_libft.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:31:05 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/30 20:01:42 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTENDED_LIBFT_H
# define EXTENDED_LIBFT_H

# include <libft.h>

// @brief free s1 and s2
char			*ex_strjoin(char *s1, char *s2);
char			*ex_substr(char *s, unsigned int start, size_t len);

unsigned int	ft_atoi_uint(const char *str);

char			*ft_itoa_ullong(unsigned long long nbr);
char			*ft_itoa_llong(long long nbr);

char			*ft_itoa_ullong_base(unsigned long long nbr, char *base);

char			*create_str(char c, long n);

#endif
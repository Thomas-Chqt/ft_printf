/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_libft.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:31:05 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/23 13:41:26 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTENDED_LIBFT_H
# define EXTENDED_LIBFT_H

# include <libft.h>
# include <stdlib.h>

unsigned int	ft_atoi_uint(const char *str);
size_t			put_n_c(size_t n, size_t minus, char c);

char			*itoa_base(unsigned long long nbr, char *base);
char			*itoa_base_no_minus(long long nbr, char *base);

size_t			unbr_base_len(unsigned long long nbr, char *base);
size_t			nbr_base_len(long long nbr, char *base);

char			*strjoinf(char *s1, char *s2);
char			*create_str(char c, long n);

#endif
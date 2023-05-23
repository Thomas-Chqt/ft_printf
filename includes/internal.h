/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:27:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/23 12:51:18 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "libftprintf.h"

typedef struct s_convert	t_convert;

struct s_convert
{
	char			*key;
	unsigned int	key_len;
	void			(*put_func)(void *);
};

void			ft_put_c(char c);
void			ft_put_s(char *s);
void			ft_put_p(void *ptr);
void			ft_put_d(int nbr);
void			ft_put_i(int nbr);
void			ft_put_u(unsigned int nbr);
void			ft_put_x(int nbr);
void			ft_put_upx(int nbr);
void			ft_put_percent(void);

unsigned int	ft_put_converted(char *key, void *value);

#endif
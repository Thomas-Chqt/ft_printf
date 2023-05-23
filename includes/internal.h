/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:27:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/23 14:59:55 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "libftprintf.h"
# include "libft.h"

typedef struct s_convert	t_convert;

struct s_convert
{
	char			*key;
	unsigned int	key_len;
	void			(*put_func)(void *);
};

void			ft_put_c(void *c);
void			ft_put_s(void **s);
void			ft_put_p(void **ptr);
void			ft_put_d(void *nbr);
void			ft_put_i(void *nbr);
void			ft_put_u(void *nbr);
void			ft_put_x(void *nbr);
void			ft_put_upx(void *nbr);
void			ft_put_percent(void *none);

unsigned int	ft_put_converted(char *key, void *value);

#endif
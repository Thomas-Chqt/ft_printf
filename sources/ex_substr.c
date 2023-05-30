/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:58:06 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/30 20:07:45 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extended_libft.h"

char	*ex_substr(char *s, unsigned int start, size_t len)
{
	char	*new_str;

	new_str = ft_substr(s, start, len);
	free(s);
	return (new_str);
}

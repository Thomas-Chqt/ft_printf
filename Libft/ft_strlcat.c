/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:49:08 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/22 18:02:11 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ret;
	size_t	k;

	i = 0;
	ret = 0;
	k = 0;
	while (dst != NULL && dst[i] != '\0')
		i++;
	while (src != NULL && src[ret] != '\0')
		ret++;
	if (dstsize <= i)
		ret += dstsize;
	else
		ret += i;
	if (dst == NULL || src == NULL)
		return (ret);
	while (src[k] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (ret);
}

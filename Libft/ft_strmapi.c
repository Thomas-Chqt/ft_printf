/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:14:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/18 17:51:39 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*output_str;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	output_str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (output_str == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		output_str[i] = f(i, s[i]);
	output_str[i] = 0;
	return (output_str);
}

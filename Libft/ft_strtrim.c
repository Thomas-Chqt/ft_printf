/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:35:47 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/18 10:52:57 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contains(char const *str, char c);
static void	strtrim_analize(char const *s1, char const *set,
				unsigned int *start, size_t *len);

static int	contains(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	strtrim_analize(char const *s1, char const *set,
							unsigned int *start, size_t *len)
{
	size_t	i;

	*len = ft_strlen(s1);
	i = 0;
	while (s1[i] && contains(set, s1[i]) != 0)
	{
		(*len)--;
		if (*len == 0)
		{
			*start = 0;
			return ;
		}
		i++;
	}
	*start = i;
	i = i + (*len) - 1;
	while (contains(set, s1[i]) != 0)
	{
		(*len)--;
		i--;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	strtrim_analize(s1, set, &start, &len);
	return (ft_substr(s1, start, len));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:17:29 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/27 20:43:31 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "extended_libft.h"
#include <stdio.h>
#include <stddef.h>
#include <wchar.h>

int main()
{	
	int res;

	res = ft_printf("%c\n", 'a');
	return 0;
}

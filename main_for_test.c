/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:17:29 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/28 20:03:03 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <wchar.h>
#include <libc.h>

#include "ftprintf.h"
#include "extended_libft.h"

int main()
{	
	int res = 0;
	
	res = ft_printf("|%#hhX|\n", 0xFF);
	res =    printf("|%#hhX|\n", 0xFF);

	return 0;
}

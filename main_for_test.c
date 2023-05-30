/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:17:29 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/30 20:13:16 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <wchar.h>
#include <libc.h>

#include "ft_printf.h"
#include "extended_libft.h"

int main()
{	
	int res = 0;
	int ft_res = 0;

	char *code = "|%s|";
	ft_res = ft_printf(code, "abcd"); printf(" ---> "); res = printf(code, "abcd"); printf("   -   %d", res == ft_res); printf("\n");

	code = "|%2s|";
	ft_res = ft_printf(code, "abcd"); printf(" ---> "); res = printf(code, "abcd"); printf("   -   %d", res == ft_res); printf("\n");

	code = "|%.2s|";
	ft_res = ft_printf(code, "abcd"); printf(" ---> "); res = printf(code, "abcd"); printf("   -   %d", res == ft_res); printf("\n");

	code = "|%4.2s|";
	ft_res = ft_printf(code, "abcd"); printf(" ---> "); res = printf(code, "abcd"); printf("   -   %d", res == ft_res); printf("\n");

	code = "|%04.2s|";
	ft_res = ft_printf(code, "abcd"); printf(" ---> "); res = printf(code, "abcd"); printf("   -   %d", res == ft_res); printf("\n");

	code = "|%-.2s|";
	ft_res = ft_printf(code, "abcd"); printf(" ---> "); res = printf(code, "abcd"); printf("   -   %d", res == ft_res); printf("\n");

	code = "|%-4.2s|";
	ft_res = ft_printf(code, "abcd"); printf(" ---> "); res = printf(code, "abcd"); printf("   -   %d", res == ft_res); printf("\n");


	code = "|%d|";
	ft_res = ft_printf(code, 42); printf(" ---> "); res = printf(code, 42); printf("   -   %d", res == ft_res); printf("\n");

	code = "|%5d|";
	ft_res = ft_printf(code, 42); printf(" ---> "); res = printf(code, 42); printf("   -   %d", res == ft_res); printf("\n");

	code = "|%05d|";
	ft_res = ft_printf(code, 42); printf(" ---> "); res = printf(code, 42); printf("   -   %d", res == ft_res); printf("\n");

	code = "|%05.3d|";
	ft_res = ft_printf(code, 42); printf(" ---> "); res = printf(code, 42); printf("   -   %d", res == ft_res); printf("\n");

	code = "|%-05.3d|";
	ft_res = ft_printf(code, 42); printf(" ---> "); res = printf(code, 42); printf("   -   %d", res == ft_res); printf("\n");

	code = "|%-05.3d|";
	ft_res = ft_printf(code, -42); printf(" ---> "); res = printf(code, -42); printf("   -   %d", res == ft_res); printf("\n");

	code = "|%-+05.3d|";
	ft_res = ft_printf(code, 42); printf(" ---> "); res = printf(code, 42); printf("   -   %d", res == ft_res); printf("\n");



	code = "|%-#05.3x|";
	ft_res = ft_printf(code, 0xff); printf(" ---> "); res = printf(code, 0xff); printf("   -   %d", res == ft_res); printf("\n");
	
	
	return 0;
}

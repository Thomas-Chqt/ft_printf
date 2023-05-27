/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:17:29 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/27 00:10:46 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "libft.h"
#include "stdio.h"

int main()
{	
	int nbr = 255;
	int res = ft_printf("%.5c\n", 'a');
	return 0;
}

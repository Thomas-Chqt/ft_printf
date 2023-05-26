/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:17:29 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/26 15:20:04 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "libft.h"
#include "stdio.h"

int main()
{	
	int nbr = 255;
	printf("%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n%%\n", 'a', "abcd", &nbr, nbr, nbr, nbr, nbr, nbr);
	return 0;
}

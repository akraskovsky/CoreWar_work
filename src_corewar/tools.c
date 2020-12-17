/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:30:43 by fprovolo          #+#    #+#             */
/*   Updated: 2020/12/17 18:14:57 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    print_usage_exit(char *message)
{
    ft_printf("\x1B[31mERROR: %s\x1b[37m\n", message);
    write(1, "\nProgram usage:\n", 16); 
    write(1, "./corewar [-dump n_cycles] [-v] [[-n number] champion1.cor] ...",\
        63);
    write(1, "\n\nFlags:\n", 9);
    write(1, "-dump\tstops execution and prints memory state after n_cycles\n",\
        61);
    write(1, "-v\truns program in visual mode\n\n", 32);
    exit(1);
}

void	terminate(char *message)
{
	write(1, "\x1B[31m", 5);
	ft_putendl(message);
	write(1, "\x1b[37m", 5);
	exit(1);
}

int		is_positive_int(char *str)
{
	unsigned long	res;

	res = 0;
	if (str == NULL)
		return (-1);
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (-1);
		res = res * 10 + (*str - '0');
		if (res > 2147483647)
			return (-1);
		str++;
	}
	return ((int)res);
}
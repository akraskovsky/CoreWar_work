/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <jconcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:00:38 by fprovolo          #+#    #+#             */
/*   Updated: 2020/12/23 08:59:26 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int argc, char **argv)
{
	t_corewar	cv;

	if (argc < 2)
		print_usage_exit("Too few arguments");
	init_structure(&cv);
	parse_args(&cv, argc, argv);
	print_arena(&cv);
	return (0);
}
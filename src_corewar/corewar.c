/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:00:38 by fprovolo          #+#    #+#             */
/*   Updated: 2020/12/24 22:13:04 by fprovolo         ###   ########.fr       */
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
	print_intro(&cv);					// представление игроков перед игрой
	if (cv.visual)
		print_arena(&cv);
	return (0);
}
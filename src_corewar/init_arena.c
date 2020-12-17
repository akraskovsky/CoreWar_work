/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:52:39 by jconcent          #+#    #+#             */
/*   Updated: 2020/12/16 17:53:34 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_arena(t_corewar *cv)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0 && i != 0)
			ft_printf(" \n");
		if (i % 64 == 0 && i != (MEM_SIZE - 1))
			ft_printf("0x%04x :", i);
		if (i % 1 == 0)
			ft_printf(" ");
		ft_printf("%02x", cv->arena[i]);
		i++;
	}
	ft_printf(" \n");
}

// void	init_arena(t_corewar *cv)
// {
// 	int space;
// 	int i;
// 	int n;

// 	space = MEM_SIZE / cv->nplayer;
// 	i = 0;
// 	n = 0;
// 	while (n < cv->nplayer)
// 	{
// 
// 		Установка стартовых позиций игроков
// 
// 		i += space;
// 		n++;
// 	}
// 	сv->last_live = сv->nplayer - 1;
// }

void init_structure(t_corewar *cv)
{
	int i;

	i = 0;
	ft_memset(cv->arena, 0, sizeof(unsigned char) * MEM_SIZE);
	cv->nb_players = 0;
	while (i < MAX_PLAYERS)
	{
		cv->players[i].nb_player = 0;
		ft_memset(cv->players[i].name, 0, PROG_NAME_LENGTH);
		ft_memset(cv->players[i].comment, 0, COMMENT_LENGTH);
		ft_memset(cv->players[i].code, 0, CHAMP_MAX_SIZE);
		i++;
	}
	cv->last_live = 0;
	cv->dump_stop = -1;
	cv->visual = 0;
}

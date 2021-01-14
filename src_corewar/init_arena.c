/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <jconcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:52:39 by jconcent          #+#    #+#             */
/*   Updated: 2021/01/14 11:27:28 by jconcent         ###   ########.fr       */
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

void	init_arena(t_corewar *cv)
{
	int space;
	int i;
	int n;

	space = MEM_SIZE / cv->nb_players;
	i = 0;
	n = 0;
	while (n < cv->nb_players)
	{
		// Установка стартовых позиций игроков
		ft_memcpy(cv->arena + i, cv->players[n].code, cv->players[n].code_len);
		cv->players[n].pc_address = i;
		i += space;
		n++;
	}
	cv->last_live = cv->nb_players - 1;
}

void	print_intro(t_corewar *cv)
{
	int	i;

	ft_printf("\nIntroducing contestants...\n");
	i = 0;
	while (i < cv->nb_players)
	{
		ft_printf("* Player %d, ", i + 1);
		ft_printf("weighting %d bytes, ", cv->players[i].code_len);
		ft_printf("\"%s\" ", cv->players[i].name);
		ft_printf("(\"%s\") !\n", cv->players[i].comment);
		// print_hex_by32(cv->players[i].code, cv->players[i].code_len);
		i++;
	}
	ft_printf("\n");
}

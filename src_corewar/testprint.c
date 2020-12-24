/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Testprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:01:54 by fprovolo          #+#    #+#             */
/*   Updated: 2020/12/24 22:19:24 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	test_print(t_corewar *cv)
{
    int i;

    i = 0;
	ft_printf("\n***** TEST content of CV *****\n");
    ft_printf("nb_players=%d\n", cv->nb_players);
    ft_printf("dump_stop=%d\n", cv->dump_stop);
    ft_printf("visual=%d\n", cv->visual);
    while (i < MAX_PLAYERS)
    {
        ft_printf("Player %d. orig num %d, requested %d \'%s\'\n", i + 1, cv->players[i].nb_player, cv->players[i].nb_player_request, cv->players[i].name);
        i++;
    }
}
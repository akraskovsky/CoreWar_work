/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <jconcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 09:34:50 by jconcent          #+#    #+#             */
/*   Updated: 2021/01/18 09:53:49 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    is_player(t_corewar *cv, int live)
{
    int i;

    i = -1;
    while (++i < cv->nb_players)
    {
        cv->players[i].nb_live++;
        cv->players[i].last_live_cycle = cv->nb_cycle;
        cv->last_live = i;
    }
}

void op_live(t_corewar *cv, t_list *game)
{
    int live;

    LIVE++;
    cv->ctd++;
    live = reverse_bytes(cv, PC + 1, 4);
    is_player(cv, live);
    PC += 5;
    PC %= MEM_SIZE;
    LIVE_SINCE = -1;
}
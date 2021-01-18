/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <jconcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:36:06 by jconcent          #+#    #+#             */
/*   Updated: 2021/01/18 09:32:50 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    game_list(t_corewar *cv)
{
    t_list *game;

    game = cv->game_list;
    while (game)
    {
        if (!(NEXT_OP >= 0 && NEXT_OP <= 15))
            init_next_op(cv, game);
        if (OP == 0)
        {
            if (NEXT_OP >= 0 && NEXT_OP < 16)
            {
                op_tab[NEXT_OP].f(cv, game);
                NEXT_OP = -1;
            }
        }
        else
            OP -= 1;
        LIVE_SINCE++;
        game = game->next;
    }
}

void    update_vm(t_corewar *cv)
{
    if (cv->nb_cycle_mod % cv->nb_cycle_to_die == 0 && cv->nb_cycle_mod != 0)
    {
        cv->ctd_modified = 0;
        if (cv->ctd >= NBR_LIVE)
        {
            cv->nb_cycle_to_die -= CYCLE_DELTA;
            cv->ctd_modified = 1;
            ft_printf("Cycle_to_die is now %d\n", cv->nb_cycle_to_die);
        }
        cv->ncheck = cv->ctd_modified ? 0 : cv->ncheck + 1;
        if (cv->ncheck % MAX_CHECKS == 0)
        {
            if (!cv->ctd_modified && cv->ncheck != 0)
            {
                cv->nb_cycle_to_die -= CYCLE_DELTA;
                ft_printf("Cycle_to_die is now %d\n", cv->nb_cycle_to_die);
            }
        }
        cv->ctd = 0;
        cv->nb_cycle_mod = 0;
    }
    cv->nb_cycle++;
    cv->nb_cycle_mod++;
}

void    game_start(t_corewar *cv)
{
    while (cv->game_list != NULL)
    {
        if (cv->nb_cycle == cv->dump_stop)
        {
            print_arena(cv);
            break ;
        }
        update_vm(cv);
        ft_printf("It is now cycle %d\n", cv->nb_cycle);
        if (cv->game_list)
        {
            processes_list(cv);
            if ((cv->nb_cycle_mod % cv->nb_cycle_to_die == 0 && cv->nb_cycle_mod != 0)
                || cv->nb_cycle_to_die < 0)
                ;
                //убить процессы
        }
    }
    if (cv->nb_cycle != cv->dump_stop)
        ft_printf("Contestant %d \"%s\", has won !\n", cv->last_live + 1, cv->players[cv->last_live].name);

}
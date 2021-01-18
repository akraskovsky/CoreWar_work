/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <jconcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:19:23 by jconcent          #+#    #+#             */
/*   Updated: 2021/01/18 09:47:01 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int     reverse_bytes(t_corewar *cv, unsigned int pc, int nbytes)
{
    unsigned char two_bytes[2];
    unsigned char four_bytes[4];

    if (nbytes == 2)
    {
        two_bytes[0] = ARENA(pc + 1);
        two_bytes[1] = ARENA(pc);
        return (*(short *)&two_bytes[0]);
    }
    if (nbytes == 4)
    {
        four_bytes[0] = ARENA(pc + 3);
        four_bytes[1] = ARENA(pc + 2);
        four_bytes[2] = ARENA(pc + 1);
        four_bytes[3] = ARENA(pc);
        return (*(int *)&four_bytes[0]);
    }
    return (-1);
}

void    init_next_op(t_corewar *cv, t_list *game)
{
    if (ARENA(PC) > 16 || ARENA(PC) <= 0)
    {
        NEXT_OP = -1;
        PC++;
        PC %= MEM_SIZE;
    }
    else
    {
        NEXT_OP = ARENA(PC) - 1;
        OP = op_tab[NEXT_OP].cycle - 1;
    }
}
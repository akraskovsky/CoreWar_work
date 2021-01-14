/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <jconcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:19:23 by jconcent          #+#    #+#             */
/*   Updated: 2021/01/14 11:36:03 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    init_next_op(t_corewar *cv, t_list *game)
{
    if (ARENA(PC) > 16 || ARENA(PC) <= 0)
    {
        NEXT_OP = -1;
        PC++;
        PC %= MEM_SIZE;
    }
    else
        NEXT_OP = ARENA(PC) - 1;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:07:52 by fprovolo          #+#    #+#             */
/*   Updated: 2020/12/15 11:27:29 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "ft_printf.h"
# include "op.h"

typedef struct s_player
{
	int nb_player;
	unsigned char name[PROG_NAME_LENGTH + 1];
	unsigned char comment[COMMENT_LENGTH + 1];
	unsigned char code[CHAMP_MAX_SIZE];
}	t_player;

typedef struct s_corewar
{
	unsigned char arena[MEM_SIZE];
	t_player	players[MAX_PLAYERS];
	int nb_players;
	int last_live;
}	t_corewar;

void init_structure(t_corewar *cv);
void	print_arena(t_corewar *cv);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:07:52 by fprovolo          #+#    #+#             */
/*   Updated: 2020/12/18 15:35:24 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "ft_printf.h"
# include "op.h"

typedef struct s_player
{
	int				nb_player;
	int				code_len;
	unsigned char	name[PROG_NAME_LENGTH + 1];
	unsigned char	comment[COMMENT_LENGTH + 1];
	unsigned char	code[CHAMP_MAX_SIZE];
	struct s_player	*previous;
}	t_player;

typedef struct s_corewar
{
	unsigned char	arena[MEM_SIZE];
	t_player		players[MAX_PLAYERS];
	int 			nb_players;
	int 			last_live;
	int				dump_stop;
	int				visual;
}	t_corewar;

void	init_structure(t_corewar *cv);
void	print_arena(t_corewar *cv);
void	print_usage_exit(char *message);
void	terminate(char *message);
void	parse_args(t_corewar *cv, int argc, char **argv);
int		is_positive_int(char *str);
int		ft_to_int(uint32_t src);
int		ft_read32(int fd);

#endif
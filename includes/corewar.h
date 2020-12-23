/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <jconcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:07:52 by fprovolo          #+#    #+#             */
/*   Updated: 2020/12/23 09:09:52 by jconcent         ###   ########.fr       */
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
	t_player		players	[MAX_PLAYERS];
	int 			nb_players;
	int 			last_live;
	int				dump_stop;
	int				visual;
	int				nb_process;
}	t_corewar;

typedef struct s_game
{
	int nb_process;			// номер активного игрового процесса, соответсвуте игроку
	int carry;				// Положение каретки
	int reg[REG_NUMBER];	// 16 операций (регистры)
	int op;					// Операция, которая выполняется
	int live_count;			// оставшиеся жизни
	unsigned char next_op;	// Следующая на выполнение операция
} t_game;

void	init_structure(t_corewar *cv);
void	init_arena(t_corewar *cv);
void	print_arena(t_corewar *cv);
void	print_intro(t_corewar *cv);
void	print_usage_exit(char *message);
void	terminate(char *message);
void	parse_args(t_corewar *cv, int argc, char **argv);
int		is_positive_int(char *str);
int		ft_to_int(uint32_t src);
int		ft_read32(int fd);
void	print_hex_by32(unsigned char *area, int len);

#endif
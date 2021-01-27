/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:07:52 by fprovolo          #+#    #+#             */
/*   Updated: 2021/01/26 16:52:15 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "ft_printf.h"
# include "op.h"

# define ARENA(x)	cv->arena[(unsigned int)(x) % MEM_SIZE]
# define NEXT_OP	(((t_game *)game->content)->next_op)
# define PC			(((t_game *)game->content)->process_content)
# define OP			(((t_game *)game->content)->op)
# define LIVE_SINCE (((t_game *)game->content)->live_since)
# define LIVE		(((t_game *)game->content)->live_count)

typedef struct s_player
{
	int				nb_player;
	int				nb_player_request;
	int				code_len;
	int				pc_address;
	int				nb_live;
	int				last_live_cycle;
	unsigned char	name[PROG_NAME_LENGTH + 1];
	unsigned char	comment[COMMENT_LENGTH + 1];
	unsigned char	code[CHAMP_MAX_SIZE];
}	t_player;

typedef struct s_corewar
{
	unsigned char	arena[MEM_SIZE];
	t_player		players	[MAX_PLAYERS];
	int 			nb_players;
	int				nb_process;
	int				nb_cycle;
	int				nb_cycle_mod;
	int				nb_cycle_to_die;
	int				ctd_modified;
	int				ctd;
	int				ncheck;
	id_t			nb_process_alive;
	int 			last_live;
	int				dump_stop;
	int				visual;
	t_list			*game_list;
}	t_corewar;

typedef struct s_game
{
	int n_process;			// номер активного игрового процесса, соответсвуте игроку
	int process_content;
	int carry;				// Положение каретки  ?????
	int reg[REG_NUMBER];	// 16 операций (регистры)
	int op;					// Операция, которая выполняется
	int live_count;			// оставшиеся жизни
	int live_since;
	unsigned char next_op;	// Следующая на выполнение операция
} t_game;

typedef struct s_op
{
  char  *name;
  unsigned char nb_arg;
  t_arg_type args[3];
  unsigned char opcode;
  unsigned int cycle;
  char *description;
  unsigned char octal;
  unsigned char label;
  void  (*f)(t_corewar *cv, t_list *game);
} t_op;

extern t_op op_tab[17];

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
void	parse_player(t_corewar *cv, char *f_name);
void	test_print(t_corewar *cv);

void	op_live(t_corewar *cv, t_list *game);

#endif
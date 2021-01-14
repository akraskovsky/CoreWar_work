#include "corewar.h"

void init_game(t_corewar *cv)
{
    t_game *game;
	int i;

	i = 0;
	while (i < cv->nb_players)
	{
		++cv->nb_process;
		++cv->nb_process_alive;
		ft_lstadd(&(cv->game_list), ft_lstnew(&game, sizeof(t_game)));
		((t_game *)cv->game_list->content)->carry = 0;
    	((t_game *)cv->game_list->content)->n_process = cv->nb_process;
    	((t_game *)cv->game_list->content)->next_op = -1;
    	((t_game *)cv->game_list->content)->op = 0;
    	((t_game *)cv->game_list->content)->live_count = 0;
		((t_game *)cv->game_list->content)->live_since = 0;
		((t_game *)cv->game_list->content)->process_content = cv->players[i].pc_address;
    	ft_memset(&(((t_game *)cv->game_list->content)->reg), 0, (REG_NUMBER) * sizeof(int));
    	((t_game *)cv->game_list->content)->reg[0] = cv->players[0].nb_player;
		i++;
	}
}

void init_structure(t_corewar *cv)
{
	int i;

	i = 0;
	ft_memset(cv->arena, 0, sizeof(unsigned char) * MEM_SIZE);
	cv->nb_players = 0;
	while (i < MAX_PLAYERS)
	{
		cv->players[i].nb_player = 0;
		cv->players[i].nb_player_request = 0;
		ft_memset(cv->players[i].name, 0, PROG_NAME_LENGTH);
		ft_memset(cv->players[i].comment, 0, COMMENT_LENGTH);
		ft_memset(cv->players[i].code, 0, CHAMP_MAX_SIZE);
		i++;
	}
	cv->last_live = 0;
	cv->dump_stop = -1;
	cv->visual = 0;
	cv->nb_process = 0;
	cv->nb_cycle = 0;
	cv->nb_cycle_mod = 0;
	cv->ncheck = 0;
	cv->nb_cycle_to_die = CYCLE_TO_DIE;
}
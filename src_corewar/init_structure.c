#include "corewar.h"

/*

Расширю в структуру t_list 

void init_game(t_corewar *cv)
{
    t_game *game;

    game->carry = 0;
    game->nb_process = cv->nb_process;
    game->next_op = -1;
    game->op = 0;
    game->live_count = 0;
    ft_memset(game->reg, 0, (REG_NUMBER) * sizeof(int));
    game->reg[0] = cv->players[0].nb_player;
}

*/

void init_structure(t_corewar *cv)
{
	int i;

	i = 0;
	ft_memset(cv->arena, 0, sizeof(unsigned char) * MEM_SIZE);
	cv->nb_players = 0;
	while (i < MAX_PLAYERS)
	{
		cv->players[i].nb_player = 0;
		ft_memset(cv->players[i].name, 0, PROG_NAME_LENGTH);
		ft_memset(cv->players[i].comment, 0, COMMENT_LENGTH);
		ft_memset(cv->players[i].code, 0, CHAMP_MAX_SIZE);
		i++;
	}
	cv->last_live = 0;
	cv->dump_stop = -1;
	cv->visual = 0;
	cv->nb_process = 0;
}
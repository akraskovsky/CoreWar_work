/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:09:34 by fprovolo          #+#    #+#             */
/*   Updated: 2020/12/24 22:13:04 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		parse_flags(t_corewar *cv, int *argc, char ***argv)
{
	while (*argc > 0)
	{
		if (ft_strequ(**argv, "-dump"))
		{
			if ((cv->dump_stop = is_positive_int(*(*argv + 1))) < 0 || \
			*argc < 2)
				print_usage_exit("Invalid -dump flag usage");
			*argc -= 2;
			*argv += 2;
		}
		else if (ft_strequ(**argv, "-v"))
		{
			cv->visual = 1;
			(*argc)--;
			(*argv)++;
		}
		else
			return ;
	}
}

static void		parse_num_flag(t_corewar *cv, int *argc, char ***argv)
{
	int			i;

	if (*argc < 3)
		print_usage_exit("Invalid -n flag usage. Must be -n NUM <file.cor>");
	if (ft_strlen(*(*argv + 1)) == 1 && \
	**(*argv + 1) - '0' > 0 && **(*argv + 1) - '0' <= MAX_PLAYERS)
		cv->players[cv->nb_players].nb_player_request = **(*argv + 1) - '0';
	else
		print_usage_exit("Player number must be from 1 to num-of-players");
	i = 0;
	while (i < cv->nb_players)
	{
		if (cv->players[i].nb_player_request == \
		cv->players[cv->nb_players].nb_player_request)
			print_usage_exit("-n flag duplicates with the same number");
		i++;
	}
	*argc -= 2;
	*argv += 2;
}

static void		swap_players(t_player *players, int i)
{
	t_player	buff;

	buff.nb_player = players[i].nb_player;
	buff.nb_player_request = players[i].nb_player_request;
	buff.nb_player = players[i].nb_player;
	ft_memcpy(buff.name, players[i].name, PROG_NAME_LENGTH);
	ft_memcpy(buff.comment, players[i].comment, COMMENT_LENGTH);
	ft_memcpy(buff.code, players[i].code, CHAMP_MAX_SIZE);

	players[i].nb_player = players[i + 1].nb_player;
	players[i].nb_player_request = players[i + 1].nb_player_request;
	players[i].nb_player = players[i + 1].nb_player;
	ft_memcpy(players[i].name, players[i + 1].name, PROG_NAME_LENGTH);
	ft_memcpy(players[i].comment, players[i + 1].comment, COMMENT_LENGTH);
	ft_memcpy(players[i].code, players[i + 1].code, CHAMP_MAX_SIZE);

	players[i + 1].nb_player = buff.nb_player;
	players[i + 1].nb_player_request = buff.nb_player_request;
	players[i + 1].nb_player = buff.nb_player;
	ft_memcpy(players[i + 1].name, buff.name, PROG_NAME_LENGTH);
	ft_memcpy(players[i + 1].comment, buff.comment, COMMENT_LENGTH);
	ft_memcpy(players[i + 1].code, buff.code, CHAMP_MAX_SIZE);
}

static void		sort_players(t_corewar *cv)
{
	int			i;

	i = 0;
	while (i < cv->nb_players)
	{
		if (cv->players[i].nb_player_request > cv->nb_players)
			print_usage_exit("Player number must be from 1 to num-of-players");
		if (cv->players[i].nb_player_request > 0)					// установлен флаг -n
		{
			if (cv->players[i].nb_player_request < (i + 1))			// двигать влево
			{
				swap_players(cv->players, i - 1);
				i--;
				continue;
			}
			if (cv->players[i].nb_player_request > (i + 1))			// двигать вправо
			{
				swap_players(cv->players, i);
				continue;
			}
		}
		i++;
	}
}

void			parse_args(t_corewar *cv, int argc, char **argv)
{
	argc--;
	argv++;
	parse_flags(cv, &argc, &argv);										// -v, -dump flags
	if (argc < 1)
		print_usage_exit("There are no Players in command line");
	while (argc > 0)
	{
		if (cv->nb_players >= MAX_PLAYERS)
			print_usage_exit("Too many players");
		if (ft_strequ(*argv, "-n"))
			parse_num_flag(cv, &argc, &argv);							// -n flag
		parse_player(cv, *argv);
		argc--;
		argv++;
	}
	sort_players(cv);							// сортирорвка в соответствии с флагами -n
	init_arena(cv);
	test_print(cv);								// удалить, тест
}

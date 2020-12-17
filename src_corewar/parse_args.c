/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:09:34 by fprovolo          #+#    #+#             */
/*   Updated: 2020/12/17 20:32:25 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		parse_flags(t_corewar *cv, int *argc, char ***argv)
{
	while (*argc > 0)
	{
		if (ft_strequ(**argv, "-dump"))
		{
			if ((cv->dump_stop = is_positive_int(*(*argv + 1))) < 0 || *argc < 2)
				print_usage_exit("Invalid n_cycles in -dump flag");
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

// static void		parse_num_flag(t_corewar *cv, int *argc, char ***argv)
// {

// }

static t_player	*add_player(t_player *player_buff)
{
	t_player	*new;

	if (!(new = (t_player *)malloc(sizeof(t_player))))
		terminate("Memory allocation error");
	new->previous = player_buff;
	new->nb_player = new->previous ? new->previous->nb_player + 1 : 1;		
	player_buff = new;

	return (player_buff);
}

static void		parse_players(t_corewar *cv, int *argc, char ***argv)
{
	t_player	*all_players;
	int			fd;

	if (*argc < 1)
		print_usage_exit("There are no Players in command line");
	all_players = NULL;
	while (*argc > 0)
	{
		if ((fd = open(**argv, O_RDONLY)) == -1)
			print_usage_exit("File open error");
		if (!(ft_read32(fd) == COREWAR_EXEC_MAGIC))
			ft_printf("Wrong magic code!\n");
		else
			ft_printf("magic code is OK\n");
		add_player(all_players);
		// ft_printf("Player #%d\n", all_players->nb_player);
		// read(fd, all_players->name, PROG_NAME_LENGTH);
		// ft_printf("Player name: %s\n", all_players->name);
		cv->nb_players++;

		(*argc)--;
		(*argv)++;
	}
	return ;
}


void			parse_args(t_corewar *cv, int argc, char **argv)
{
	ft_printf("Before flags:\tCycles: %d, visual=%d\n", cv->dump_stop, cv->visual);	
	argc--;
	argv++;
	parse_flags(cv, &argc, &argv);
	ft_printf("After flags:\tCycles: %d, visual=%d\n", cv->dump_stop, cv->visual);	
	parse_players(cv, &argc, &argv);
}	

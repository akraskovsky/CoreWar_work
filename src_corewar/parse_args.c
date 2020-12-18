/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:09:34 by fprovolo          #+#    #+#             */
/*   Updated: 2020/12/18 15:59:15 by fprovolo         ###   ########.fr       */
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

static void	add_player(t_player **players)
{
	t_player	*new;

	if (!(new = (t_player *)malloc(sizeof(t_player))))
		terminate("Memory allocation error");
	new->previous = *players;
	new->nb_player = new->previous ? new->previous->nb_player + 1 : 1;
	new->name[PROG_NAME_LENGTH] = '\0';
	new->comment[COMMENT_LENGTH] = '\0';
	*players = new;
	return ;
}

static void		parse_players(t_corewar *cv, int *argc, char ***argv)
{
	t_player	*players;
	int			fd;

	players = NULL;
	while (*argc > 0)
	{
		if ((fd = open(**argv, O_RDONLY)) == -1)
			print_usage_exit("File open error");
		if (!(ft_read32(fd) == COREWAR_EXEC_MAGIC))
			ft_printf("Wrong magic code!\n");
		add_player(&players);
		if (read(fd, players->name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
			print_usage_exit("Incorrect file format. Prog name.");
		if (ft_read32(fd) != 0)
			print_usage_exit("Incorrect file format");
		players->code_len = ft_read32(fd);
		if (players->code_len < 1 || players->code_len > CHAMP_MAX_SIZE)
			print_usage_exit("Incorrect code length");
		if (read(fd, players->comment, COMMENT_LENGTH) != COMMENT_LENGTH)
			print_usage_exit("Incorrect file format. Comment.");
		if (ft_read32(fd) != 0)
			print_usage_exit("Incorrect file format");
		if (read(fd, players->comment, players->code_len) != players->code_len)
			print_usage_exit("Incorrect file format. Code length.");
		cv->nb_players++;
		(*argc)--;
		(*argv)++;

		ft_printf("\nFile: \t%s\n", **argv);
		ft_printf("Player \t#%d\n", players->nb_player);
		ft_printf("Name: \t\"%s\"\n", players->name);
		ft_printf("Code_len: \t\"%d\"\n", players->code_len);
		ft_printf("Code: \t\"%s\"\n", players->code);
	}
	return ;
}


void			parse_args(t_corewar *cv, int argc, char **argv)
{
	argc--;
	argv++;
	parse_flags(cv, &argc, &argv);
	if (argc < 1)
		print_usage_exit("There are no Players in command line");
	parse_players(cv, &argc, &argv);
}	

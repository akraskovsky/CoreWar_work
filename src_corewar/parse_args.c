/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:09:34 by fprovolo          #+#    #+#             */
/*   Updated: 2020/12/21 17:29:18 by fprovolo         ###   ########.fr       */
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
	// тут будет логика обработки флага -n и назначения номера играка
// }

static void		parse_player(t_corewar *cv, char *f_name)
{
	int			fd;
	t_player	*player;

	player = cv->players + cv->nb_players; // ук-ль на очередного плеера. добавить проверку на >4 
	cv->nb_players++;
	player->nb_player = cv->nb_players;
	if ((fd = open(f_name, O_RDONLY)) == -1)
		print_usage_exit("File open error");
	if (!(ft_read32(fd) == COREWAR_EXEC_MAGIC))							// magic code
		ft_printf("Wrong magic code!\n");
	if (read(fd, player->name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)	// имя игрока
		print_usage_exit("Incorrect file format. Prog name.");
	if (ft_read32(fd) != 0)												// разделитель 4 байта
		print_usage_exit("Incorrect file format");
	player->code_len = ft_read32(fd);									// длина кода программы
	if (player->code_len < 1 || player->code_len > CHAMP_MAX_SIZE)
		print_usage_exit("Incorrect code length");
	if (read(fd, player->comment, COMMENT_LENGTH) != COMMENT_LENGTH)	// комментарий
		print_usage_exit("Incorrect file format. Comment.");
	if (ft_read32(fd) != 0)												// разделитель 4 байта
		print_usage_exit("Incorrect file format");
	if (read(fd, player->code, player->code_len) != player->code_len)	// код программы
		print_usage_exit("Incorrect file format. Code length.");
	return ;
}

void			parse_args(t_corewar *cv, int argc, char **argv)
{
	argc--;
	argv++;
	parse_flags(cv, &argc, &argv);
	if (argc < 1)
		print_usage_exit("There are no Players in command line");
	while (argc > 0)
	{
		// parse_num_flag(cv, &argc, &argv);	// обработка флага -n
		parse_player(cv, *argv);
		argc--;
		argv++;
	}
	print_intro(cv);
	init_arena(cv);
}

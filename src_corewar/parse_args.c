/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:09:34 by fprovolo          #+#    #+#             */
/*   Updated: 2020/12/18 17:16:54 by fprovolo         ###   ########.fr       */
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

// static void	add_player(t_player **players)
// {
// 	t_player	*new;

// 	if (!(new = (t_player *)malloc(sizeof(t_player))))
// 		terminate("Memory allocation error");
// 	new->previous = *players;
// 	new->nb_player = new->previous ? new->previous->nb_player + 1 : 1;
// 	new->name[PROG_NAME_LENGTH] = '\0';
// 	new->comment[COMMENT_LENGTH] = '\0';
// 	*players = new;
// 	return ;
// }

static void		parse_player(t_corewar *cv, char *f_name)
{
	int			fd;
	t_player	*player;
	// int			check;
	// unsigned char	buff[16];

	player = cv->players + cv->nb_players; // ук-ль на очередного плеера. добавить проверку на >4 
	if ((fd = open(f_name, O_RDONLY)) == -1)
		print_usage_exit("File open error");
	if (!(ft_read32(fd) == COREWAR_EXEC_MAGIC))
		ft_printf("Wrong magic code!\n");
	if (read(fd, player->name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		print_usage_exit("Incorrect file format. Prog name.");
	if (ft_read32(fd) != 0)
		print_usage_exit("Incorrect file format");
	player->code_len = ft_read32(fd);
	if (player->code_len < 1 || player->code_len > CHAMP_MAX_SIZE)
		print_usage_exit("Incorrect code length");
	if (read(fd, player->comment, COMMENT_LENGTH) != COMMENT_LENGTH)
		print_usage_exit("Incorrect file format. Comment.");
	if (ft_read32(fd) != 0)
		print_usage_exit("Incorrect file format");
	if (read(fd, player->comment, player->code_len) != player->code_len)
		print_usage_exit("Incorrect file format. Code length.");
	player->nb_player = cv->nb_players + 1;
	cv->nb_players++;
	// // Контрольное чтение в конце файла
	// check = read(fd, buff, 16);
	// ft_printf("read AFTER: %d\n\n", check);

	return ;
}


void			parse_args(t_corewar *cv, int argc, char **argv)
{
	int			i;

	argc--;
	argv++;
	parse_flags(cv, &argc, &argv);
	if (argc < 1)
		print_usage_exit("There are no Players in command line");
	while (argc > 0)
	{
		// parse_num_flag(cv, &argc, &argv);
		parse_player(cv, *argv);
		argc--;
		argv++;
	}

	ft_printf("Players: %d\n", cv->nb_players);
	i = 0;
	while (i < cv->nb_players)
	{
		ft_printf("\nPlayer \t#%d\n", cv->players[i].nb_player);
		ft_printf("Name: \t\"%s\"\n", cv->players[i].name);
		ft_printf("Comm.: \t\"%s\"\n", cv->players[i].comment);
		ft_printf("Length: \t%d\n", cv->players[i].code_len);
		ft_printf("Code: \t\"%s\"\n", cv->players[i].code);
		i++;
	}
	
}	

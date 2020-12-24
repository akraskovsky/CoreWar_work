/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 21:33:15 by fprovolo          #+#    #+#             */
/*   Updated: 2020/12/24 21:36:06 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		    parse_player(t_corewar *cv, char *f_name)
{
	int			fd;
	t_player	*player;

	player = cv->players + cv->nb_players; 				                // ук-ль на очередного игрока
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
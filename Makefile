# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/11 16:09:01 by fprovolo          #+#    #+#              #
#    Updated: 2020/12/14 18:23:50 by fprovolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = asm
NAME2 = corewar
ASM_FILES =	asm\

VM_FILES = 	corewar\
			testhello\

# имена файлов без расширений

LFT_PATH = ./libft/
SRC_PATH_ASM = ./src_asm/
SRC_PATH_VM = ./src_corewar/
OBJ_PATH_ASM = ./obj_asm/
OBJ_PATH_VM = ./obj_corewar/
INC_PATH = ./includes/

IFLAGS = -I $(LFT_PATH)/includes -I $(INC_PATH)
LFLAGS = -L$(LFT_PATH) -lft
CFLAGS = -Wall -Wextra -Werror

# ASM_SRC = $(addprefix $(SRC_PATH_ASM), $(addsuffix .c, $(ASM_FILES)))
# VM_SRC = $(addprefix $(SRC_PATH_VM), $(addsuffix .c, $(VM_FILES)))

OBJ_ASM = $(addprefix $(OBJ_PATH_ASM), $(addsuffix .o, $(ASM_FILES)))
OBJ_VM = $(addprefix $(OBJ_PATH_VM), $(addsuffix .o, $(VM_FILES)))

LIBFT = $(LFT_PATH)libft.a
INCL = $(INC_PATH)op.h

.PHONY: all clean fclean re

all: $(NAME1) $(NAME2)

$(NAME1): $(LIBFT) $(OBJ_PATH_ASM) $(OBJ_ASM)
	gcc $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJ_ASM) -o $(NAME1)

$(NAME2): $(LIBFT) $(OBJ_PATH_VM) $(OBJ_VM)
	gcc $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJ_VM) -o $(NAME2)

$(LIBFT):
	make -C $(LFT_PATH)

$(OBJ_PATH_ASM):
	mkdir -p $(OBJ_PATH_ASM)

$(OBJ_PATH_VM):
	mkdir -p $(OBJ_PATH_VM)

$(OBJ_PATH_ASM)%.o: $(SRC_PATH_ASM)%.c $(INCL)
	gcc $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_PATH_VM)%.o: $(SRC_PATH_VM)%.c $(INCL)
	gcc $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_PATH_ASM)
	rm -rf $(OBJ_PATH_VM)
	make -C $(LFT_PATH) clean

fclean: clean
	rm -rf $(NAME1)
	rm -rf $(NAME2)
	make -C $(LFT_PATH) fclean

re: fclean all

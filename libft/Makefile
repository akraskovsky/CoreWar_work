# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 15:52:55 by fprovolo          #+#    #+#              #
#    Updated: 2020/02/28 18:32:00 by fprovolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FUNCTIONS = ft_memset\
			ft_bzero\
			ft_memcpy\
			ft_memccpy\
			ft_memmove\
			ft_memchr\
			ft_memcmp\
			ft_strlen\
			ft_strdup\
			ft_strcpy\
			ft_strncpy\
			ft_strcat\
			ft_strncat\
			ft_strlcat\
			ft_strchr\
			ft_strrchr\
			ft_strcmp\
			ft_strncmp\
			ft_strstr\
			ft_strnstr\
			ft_isalpha\
			ft_isdigit\
			ft_isalnum\
			ft_isascii\
			ft_isprint\
			ft_isspace\
			ft_toupper\
			ft_tolower\
			ft_atoi\
			ft_memalloc\
			ft_memdel\
			ft_strnew\
			ft_strdel\
			ft_strclr\
			ft_striter\
			ft_striteri\
			ft_strmap\
			ft_strmapi\
			ft_strequ\
			ft_strnequ\
			ft_strsub\
			ft_strjoin\
			ft_strtrim\
			ft_strsplit\
			ft_itoa\
			ft_putchar\
			ft_putstr\
			ft_putendl\
			ft_putnbr\
			ft_putchar_fd\
			ft_putstr_fd\
			ft_putendl_fd\
			ft_putnbr_fd\
			ft_lstnew\
			ft_lstdelone\
			ft_lstdel\
			ft_lstadd\
			ft_lstiter\
			ft_lstmap\
			ft_max\
			ft_min\
			get_next_line\

PF_FILES = ft_printf ft_printf_fd parse_format get_argument get_int \
			get_unsigned get_string get_character tools set_colors get_floats \
			f_dealer f_flag f_get_binary f_nan_inf f_normalize f_rounding \
			f_tools_mant f_tools_zero f_tools ft_atoi_base f_long_e f_long_g

SRC_PATH = ./sources/
OBJ_PATH = ./objects/
INC_PATH = ./includes/
SRC = $(addprefix $(SRC_PATH), $(patsubst %,%.c,$(FUNCTIONS))) \
		$(addprefix $(SRC_PATH), $(patsubst %,%.c,$(PF_FILES)))
OBJ = $(addprefix $(OBJ_PATH), $(patsubst %,%.o,$(FUNCTIONS))) \
		$(addprefix $(OBJ_PATH), $(patsubst %,%.o,$(PF_FILES)))
INCLUDES = -I $(INC_PATH)
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
		ar rcs $(NAME) $(OBJ)
		ranlib $(NAME)

$(OBJ_PATH):
		mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		gcc $(CFLAGS) $(INCLUDES) -c $< -o $@ 

clean:
		/bin/rm -rf $(OBJ_PATH)

fclean: clean
		/bin/rm -f $(NAME)

re:	fclean all

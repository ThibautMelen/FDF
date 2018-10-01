# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thmelen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/25 17:24:23 by thmelen           #+#    #+#              #
#    Updated: 2018/06/15 16:37:37 by thmelen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fdf

INC_DIR = includes
INC     = fdf.h
SRC_DIR = srcs
LIB_DIR = libft
BIN_DIR = bin

SRC     = main.c \
				start_map.c \
				start_mlx.c \
				resolver_map.c \
				draw_stroke.c \
				art_tools.c \
				event_mlx.c \
				mlx_free.c

SRC     := $(addprefix $(SRC_DIR)/,$(SRC))
BIN     = $(subst $(SRC_DIR),$(BIN_DIR),$(SRC:.c=.o))
LIB     = libft.a

FLAG    = -g -Ofast -flto -march=native -Wall -Wextra -Werror
MLXFLAGS = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

all:
	@$(MAKE) -C $(LIB_DIR) --no-print-directory
	@$(MAKE) -C . $(NAME) --no-print-directory

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR) 2> /dev/null
	@gcc $(FLAG) -I$(LIB_DIR)/include -I$(INC_DIR) -o $@ -c $<
	@printf "\33[2K $$> %s\r" "gcc $(FLAG) -I$(LIB_DIR)/include -I$(INC_DIR) -o $@ -c $<"

$(LIB_DIR)/$(LIB):
	@$(MAKE) -C $(LIB_DIR) --no-print-directory

$(NAME): $(LIB_DIR)/$(LIB) $(INC_DIR)/$(INC) $(BIN)
	@gcc $(BIN) $(MLXFLAGS) $(LIB_DIR)/$(LIB) -o $(NAME)
	@printf "\33[2K$(NAME) [\e[1;32m✓\e[0;39m]\n"

clean:
	@$(MAKE) -C $(LIB_DIR) clean --no-print-directory
	@rm -rf $(BIN_DIR)
fclean: clean
	@$(MAKE) -C $(LIB_DIR) fclean --no-print-directory
	@rm -f $(NAME)
re: fclean all
lib:
	@$(MAKE) -C $(LIB_DIR) --no-print-directory

.PHONY: all clean fclean re lib

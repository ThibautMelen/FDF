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

NAME	= fdf
INC		= includes
SRC_DIR = srcs

SRCS	= main.c \
				start_map.c \
				start_mlx.c \
				resolver_map.c \
				draw_stroke.c \
				art_tools.c \
				event_mlx.c \
				mlx_free.c


OBJ_DIR = obj
OBJS	= $(SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
OFLAGS	= -pipe -flto
MLXFLAGS = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit
LIB_DIR	= libft
LIB		= libft.a

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INC) -c $<

$(NAME): lib $(OBJS)
	$(CC) $(CFLAGS) $(OFLAGS) $(MLXFLAGS) $(OBJS) $(LIB_DIR)/$(LIB) -o $(NAME)
	@mkdir -p $(OBJ_DIR) 2> /dev/null
	@mv $(OBJS) $(OBJ_DIR)/

# Essentials
all: $(NAME)
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIB_DIR) clean
fclean:
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean
re: fclean all

# Libft
lib:
	$(MAKE) -C $(LIB_DIR)

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 17:27:16 by vveselov          #+#    #+#              #
#    Updated: 2018/04/27 12:49:33 by vveselov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

OBJ_DIR = ./

SRC_DIR = ./

INC_DIR = ./

SRC = lem_in.c get_next_line.c minlib.c minlib2.c lists.c input_check.c \
room_check.c link_check.c link_cmp.c add_way.c matrix_creat.c \
bfs_dist.c queue.c get_room.c more_lists.c lets_go.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

HEAD = lem_in.h get_next_line.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.c
	gcc -c $< -o $@ $(CFLAGS) -I $(INC_DIR)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

vpath %.c $(SRC_DIR)

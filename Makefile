# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 16:26:20 by ralves-g          #+#    #+#              #
#    Updated: 2022/09/07 17:48:06 by ralves-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror 
#-fsanitize=leak
MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit
MLX_LINUX	=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -D LINUX
RM			=	rm -f

NAME		=	so_long
NAME2		=	so_long_linux

INCLUDE		=	-I ./
SRCS_		=	\
				animations.c \
				errors.c \
				exit.c \
				exit2.c \
				key_actions.c \
				map_to_img.c \
				map_to_img2.c \
				map_to_img3.c \
				move_character.c \
				move_character2.c \
				move_character3.c \
				move_enemy.c \
				move_enemy2.c \
				mp_checker.c \
				mp_checker2.c \
				mp_checker3.c \
				mp_utils.c \
				objects.c \
				preparations.c \
				preparations2.c \
				preparations3.c \
				nyan.c \
				side_info.c \
				so_long.c \
				so_long_utils.c \
				so_long_wall_utils.c \
				so_long_wall_utils2.c \
				so_long_wall_utils3.c \
				so_long_wall_utils4.c \
				get_next_line.c \
				get_next_line_utils.c
SRCS		=	$(addprefix $(_SRC), $(SRCS_))

_OBJ		=	./obj/
_SRC		= 	./src/
OBJS		=	$(patsubst $(_SRC)%.c, $(_OBJ)%.o, $(SRCS))


all:		$(NAME)
	
$(_OBJ)%.o: $(_SRC)%.c
	$(CC) -c $< -o $@

$(NAME): $(_OBJ) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME) $(INCLUDE)

linux:		$(NAME2)

$(NAME2): $(_OBJ) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LINUX) -o $(NAME2) $(INCLUDE)
	
#bonus:		$(SRCS_B) $(OBJS_B)
#			$(CC) $(CFLAGS) $(SRCS_B) -o $(NAME_B)
#			$(CC) $(CFLAGS) $(SRCS_B) -c

$(_OBJ):
	mkdir $@

clean:
	$(RM) -r $(_OBJ)

fclean:	clean
	$(RM) $(NAME) $(NAME2)

re:	fclean all

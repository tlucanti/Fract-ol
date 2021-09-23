# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kostya <kostya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 20:07:05 by kostya            #+#    #+#              #
#    Updated: 2021/09/23 15:17:51 by kostya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
NAME		=	Fract-ol
CFLAGS		=	-Wall -Wextra -Werror
COPTIONS	=	-O3
RM			=	rm -f
LIBRARY		=	./libmlx.a -Imlx -lXext -lX11 -lm -lz
# ------------------------------------------------------------------------------
SRCS		=	\
				error1		\
				error2		\
				error		\
				event		\
				ft_atodl	\
				ft_memcmp	\
				ft_memset	\
				julia		\
				main		\
				mandelbrot	\
				memory		\
				newton_pool	\
				options		\
				utils1		\
				utils
# ------------------------------------------------------------------------------
HDRS		=	\
				color		\
				error		\
				event		\
				fract_ol	\
				global		\
				memory		\
				time
# ------------------------------------------------------------------------------
MLX_DIR		=	mlxlinux
OBJS_DIR	=	objects
OBJS		=	${SRCS:=.o}
DEPS		=	${HDRS:=.h}
LIBFT		=

.c.o:
	${CC}		${CFLAGS} ${COPTIONS} -c $< -o ${<:.c=.o}

$(NAME):		${DEPS} ${OBJS}
	${MAKE}		-C ${MLX_DIR}
	cp			${MLX_DIR}/libmlx.a .
	${CC}		-o ${NAME} ${CFLAGS} ${COPTIONS} ${OBJS} ${LIBFT} ${LIBRARY} 

# ------------------------------------------------------------------------------
all:			${NAME}

# ------------------------------------------------------------------------------
f:
	rm -rf __make_all_FILE.c
	cat ${DEPS} ${SRCS:=.c} > __make_all_FILE.c
	${CC} -o ${NAME} -O3 -Wall -Wextra __make_all_FILE.c ${LIBFT} ${LIBRARY}
	rm -rf __make_all_FILE.c

# ------------------------------------------------------------------------------
clean:
	${MAKE}		-C ${MLX_DIR} clean
	${RM}		${OBJS}

# ------------------------------------------------------------------------------
fclean:			clean
	${RM}		${NAME}

# ------------------------------------------------------------------------------
apt-install:
	sudo apt	update
	sudo apt	install gcc -y
	sudo apt	install xorg -y
	sudo apt	install libxext-dev -y
	sudo apt	install libbsd-dev -y
	${MAKE}		install

# ------------------------------------------------------------------------------
install:
	sudo ${MAKE} -C ${MLX_DIR}
	sudo cp		${MLX_DIR}/libmlx.a /usr/local/lib/libmlx.a
	sudo cp		${MLX_DIR}/mlx.h /usr/include/mlx.h

# ------------------------------------------------------------------------------
re:				fclean all

# ------------------------------------------------------------------------------
.PHONY:			all clean fclean apt-install install re

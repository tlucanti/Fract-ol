# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kostya <kostya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 20:07:05 by kostya            #+#    #+#              #
#    Updated: 2021/12/01 13:17:25 by kostya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ compiler options ------------------------------
NAME		=	Fract-ol
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
COPTIONS	=	-O3 -ffast-math
# ------------------------------- linker options -------------------------------
LIBRARY		=
OBJS_DIR	=	obj
INCLUDE_DIR	=	inc
SRCS_DIR	=	src
LIBGNL		=	
LIBFT		=	
LIBMLX		=	libmlx.a
# ------------------------------- project sorces -------------------------------
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
				utils2		\
				utils		\
				palette		\
				palette1	\
				mlx_get_screen_size
# ------------------------------------------------------------------------------
HDRS		=	\
				color		\
				error		\
				event		\
				fract_ol	\
				global		\
				memory		\
				time

# ======================= UNCHANGEABLE PART OF MAKEFILE ========================
# ------------------------------------------------------------------------------
RM			=	rm -f
OBJS		=	$(addprefix ${OBJS_DIR}/,${SRCS:=.o})
DEPS		=	$(addprefix ${INCLUDE_DIR}/,${HDRS:=.h})
INCLUDE		=	-I ${INCLUDE_DIR}
OS			=	$(shell uname -s | tr A-Z a-z)
MLX_DIR		=

ifeq ($(OS), linux)
	MLX_DIR		=	mlxlinux
	LIBRARY		=	-Imlx -lXext -lX11 -lm -lz
endif
ifeq ($(OS), darwin)
	MLX_DIR		=	mlxosx
	LIBRARY		=	-lmlx -framework OpenGL -framework AppKit -lz
endif

# ------------------------------------------------------------------------------
all:			libmlx_install ${OBJS_DIR}
	@$(MAKE)	$(NAME) -j

# ------------------------------------------------------------------------------
${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c ${DEPS} Makefile
	${CC}		${CFLAGS} ${COPTIONS} -c -o $@ $< ${INCLUDE}

# ------------------------------------------------------------------------------
libmlx_install:
	@${MAKE}	-C ${MLX_DIR}
	ln			-sf ../${MLX_DIR}/mlx.h ${INCLUDE_DIR}/mlx.h
	ln			-sf ${MLX_DIR}/${LIBMLX} ./${LIBMLX}

# ------------------------------------------------------------------------------
$(NAME):		${OBJS} ${DEPS} ${LIBMLX}
	${MAKE}		-C ${MLX_DIR}
	${CC}		-o ${NAME} ${CFLAGS} ${COPTIONS} ${OBJS} ${LIBRARY} ${LIBMLX} 


# ------------------------------------------------------------------------------
f:
	rm -rf __make_all_FILE.c
	cat ${DEPS} ${SRCS_DIR} > __make_all_FILE.c
	${CC} -o ${NAME} -O3 -Wall -Wextra __make_all_FILE.c ${LIBFT} ${LIBRARY}
	rm -rf __make_all_FILE.c

# ------------------------------------------------------------------------------
clean:
	${MAKE}		-C ${MLX_DIR} clean
	${RM}		${OBJS}

# ------------------------------------------------------------------------------
fclean:			clean
	${RM}		${NAME}
	${RM}		${LIBMLX}

# ------------------------------------------------------------------------------
ifeq (${OS}, linux)
install:
	sudo apt	update
	sudo apt	install gcc -y
	sudo apt	install xorg -y
	sudo apt	install libxext-dev -y
	sudo apt	install libbsd-dev -y
	${MAKE}		install
	sudo		${MAKE} -C ${MLX_DIR}
	sudo		cp		${MLX_DIR}/libmlx.a /usr/local/lib/libmlx.a
	sudo		cp		${MLX_DIR}/mlx.h /usr/include/mlx.h
endif
ifeq ($(OS), darwin)
install:
	brew		install xorgrgb
	chmod		-R 731 ${MLX_DIR}
	${MAKE}		-C ${MLX_DIR}
endif
# ------------------------------------------------------------------------------
re:				fclean all

# ------------------------------------------------------------------------------
.PHONY:			all f clean fclean install re
